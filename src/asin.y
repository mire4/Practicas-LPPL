/*****************************************************************************/
/**  Mireia Pires State, Andrea Gascó Pau e Iñaki Diez Lambies    2022-2023 **/
/*****************************************************************************/

/*----------------------
  Seccion definiciones
------------------------*/
// Preambulo C
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
%}

%union{
  int cent;
  char *ident;
  PF pf;
  EXP exp;
  CONS cons;
}

// Declaraciones Bison
%token IF_ ELSE_ FOR_ RETURN_
%token ASIG_ OPIGUALDAD_ OPDESIGUALDAD_ OPMAYOR_ OPMENOR_ OPMAYORIGUAL_ OPMENORIGUAL_
%token OPMAS_ OPMENOS_ OPMUL_ OPDIV_ OPAND_ OPOR_ OPNEGACION_
%token APAR_ CPAR_ ALLAVE_ CLLAVE_ ACOR_ CCOR_ COMA_ PCOMA_
%token TRUE_ FALSE_ INT_ BOOL_ READ_ PRINT_

// Para los terminales
%token <cent> CTE_ 
%token <ident> ID_

// Para los no-terminales
%type <cent> lista_declaraciones declaracion tipo_simple declaracion_funcion
%type <cent> parametros_formales 
%type <cent> parametros_actuales lista_parametros_actuales
%type <pf> lista_parametros_formales

// Contantes
%type<cons> constante

// Expresiones
%type <exp> expresion expresion_opcional expresion_logica
%type <exp> expresion_igualdad expresion_relacional expresion_adicion
%type <exp> expresion_multiplicativa expresion_unaria expresion_sufijo

// Operadores
%type <cent> operador_logico operador_igualdad operador_relacional
%type <cent> operador_adicion operador_multiplicativo operador_unario
%%

/*----------------------
  Seccion de reglas
------------------------*/
                  programa:
                          {
                            dvar = 0;
                            niv = 0;
                            cargaContexto(niv);
                          }
                            lista_declaraciones
                          {
                            if ($2 == 0)
                              yyerror("Debe de haber al menos una función main.");
                            else if ($2 > 1)
                              yyerror("El programa tiene más de un main.");
                            else
                              emite(FIN, crArgNul(), crArgNul(), crArgNul());
                          }
                          ;

       lista_declaraciones: declaracion { $$ = $1; }
                          | lista_declaraciones declaracion { $$ = $1 + $2; }
                          ;

               declaracion: declaracion_variable { $$ = 0; }
                          | declaracion_funcion { $$ = $1; }
                          ;

      declaracion_variable: tipo_simple ID_ PCOMA_
                          {
                            if (insTdS($2, VARIABLE, $1, niv, dvar, -1))
                              dvar += TALLA_TIPO_SIMPLE;
                            else 
                              yyerror("Variable ya declarada.");
                          }
                          | tipo_simple ID_ ASIG_ constante PCOMA_
                          {
                            if ($1 != $4) {
                              yyerror("Tipo de variable diferente del asignado.");
                              insTdS($2, VARIABLE, T_VACIO, niv, dvar, -1);
                            } else {
                              if (insTdS($2, VARIABLE, $1, niv, dvar, -1))
                              {
                                dvar += TALLA_TIPO_SIMPLE;
                                int desp = creaVarTemp();
                                emite(EASIG, crArgEnt($4.v), crArgNul(), crArgPos(niv, desp))
                              }
                              else
                                yyerror("Variable ya declarada.");
                            }
                          }
                          | tipo_simple ID_ ACOR_ CTE_ CCOR_ PCOMA_
                          {
                            if ($4 <= 0) { 
                              yyerror("Tamaño del array incorrecto.");
                              insTdS($2, VARIABLE, T_VACIO, niv, dvar, -1);
                            } else {
                              if (insTdS($2, VARIABLE, T_ARRAY, niv, dvar, insTdA($1, $4)))
                                dvar += $4 * TALLA_TIPO_SIMPLE;
                              else
                                yyerror("Variable ya declarada.");
                            }  
                          }
                          ;

                 constante: CTE_ { $$.t = T_ENTERO; $$.v = $1; }
                          | TRUE_ { $$.t = T_LOGICO; $$.v = 1; }
                          | FALSE_ { $$.t = T_LOGICO; $$.v = 0; }
                          ;

               tipo_simple: INT_ { $$ = T_ENTERO; }
                          | BOOL_ { $$ = T_LOGICO; }
                          ;

       declaracion_funcion: tipo_simple ID_ 
                          {
                            niv++;
                            $<cent>$=dvar;
                            dvar = 0;
                            cargaContexto(niv); 

                          }
                            APAR_ parametros_formales CPAR_ 
                          {
                            if (!insTdS($2, FUNCION, $1, niv - 1, -1, $5))
                              yyerror("Declaración repetida de la función.");
                          }
                          bloque
                          {
                            descargaContexto(niv);
                            dvar = $<cent>$;
                            niv--;

                            if (strcmp($2, "main\0") == 0) { $$ = 1; }
                            else { $$ = 0; }
                          }  
                          ;

       parametros_formales: /* Cadena vacía */ { $$  = insTdD(-1, T_VACIO); }
                          | lista_parametros_formales { $$ = $1.ref; }
                          ;

 lista_parametros_formales: tipo_simple ID_  
                          {
                            $$.ref = insTdD(-1 , $1);
                            int talla = TALLA_TIPO_SIMPLE;
                            $$.talla = talla;
                            if (!insTdS($2, PARAMETRO, $1, niv, -talla, -1))
                              yyerror("Declaración repetida del parámetro.");
                          }
                          | tipo_simple ID_ COMA_ lista_parametros_formales
                          {
                            $$.ref = insTdD($4.ref, $1);
                            int talla = $4.talla + TALLA_TIPO_SIMPLE;
                            $$.talla = talla;
                            if (!insTdS($2, PARAMETRO, $1, niv, -talla, -1))
                              yyerror("Declaración repetida del parámetro.");
                          }        
                          ;

                    bloque: ALLAVE_ declaracion_variable_local lista_instrucciones RETURN_ expresion PCOMA_ 
                          {
                            INF infoFunc = obtTdD(-1);
                            if (infoFunc.tipo == T_ERROR) { yyerror("Error en la declaración de la función."); } 
                            else if (infoFunc.tipo != $5.t) { yyerror("Tipo de retorno incorrecto."); }
                          }
                          CLLAVE_
                          ;

declaracion_variable_local: 
                          | declaracion_variable_local declaracion_variable
                          ;

       lista_instrucciones: 
                          | lista_instrucciones instruccion
                          ;

               instruccion: ALLAVE_ lista_instrucciones CLLAVE_
                          | intruccion_expresion
                          | instruccion_entrada_salida
                          | instruccion_seleccion
                          | instruccion_iteracion
                          ;

      intruccion_expresion: expresion PCOMA_
                          | PCOMA_
                          ;

instruccion_entrada_salida: READ_ APAR_ ID_ CPAR_ PCOMA_
                          {
                            SIMB infoVar = obtTdS($3);
                            if (infoVar.t == T_ERROR)
                              yyerror("Variable sin declarar."); 
                            else if (infoVar.t != T_ENTERO)
                              yyerror("Variable diferente de entero.");
                          }
                          | PRINT_ APAR_ expresion CPAR_ PCOMA_
                          {
                            if ($3.t == T_ERROR)
                              yyerror("Variable sin declarar."); 
                            else if ($3.t != T_ENTERO)
                              yyerror("Variable diferente de entero.");
                          }
                          ;

     instruccion_seleccion: IF_ APAR_ expresion CPAR_ 
                          {
                            if ($3.t != T_LOGICO && $3.t != T_ERROR) { yyerror("Condición incorrecta."); }
                            else if ($3.t != T_ERROR)
                            {
                              int ifLans = creaLans(si);  
                              emite(EIGUAL, crArgPos(niv, $3.d), crArgEnt(0), crArgEtq(ifLans)); 
                            }
                          }
                            instruccion 
                          {
                            if ($3.t != T_ERROR)
                            {
                              completaLans(ifLans, crArgEtq(si));
                              int elseLans = creaLans(si);
                              emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(elseLans)); 
                            }
                          }
                          ELSE_ instruccion
                          {
                            if ($3.t != T_ERROR)
                              completaLans(elseLans, crArgEtq(si));
                          }
                          ;

     instruccion_iteracion: FOR_ APAR_ expresion_opcional PCOMA_ expresion PCOMA_ expresion_opcional CPAR_
                          {
                            if ($3.t == T_ERROR) {
                              yyerror("Inicialización incorrecta.");
                            //} else if ($3.t != T_VACIO && $3.t != T_ENTERO && $3.t != T_LOGICO) {
                            //  yyerror("La expresión opcional debe ser de tipo simple.");
                            } else if ($5.t != T_LOGICO) {
                              yyerror("Condición incorrecta."); 
                            } else if ($7.t == T_ERROR) {
                              yyerror("Paso incorrecto"); 
                            } else {
                              int forLans = creaLans();
                              emite(EIGUAL, crArgPos(niv, $5.d), crArgEnt(0), crArgEtq(forLans));
                            }
                          }
                            instruccion
                          {
                            // Comprobar que el for está bien?
                            completaLans(forLans, crArgEtq(si));
                          }
                          ;

        expresion_opcional: /* Cadena vacía */ { $$.t = T_VACIO; }
                          | expresion { $$ = $1; }
                          ;

                 expresion: expresion_logica { $$ = $1; }
                          | ID_ ASIG_ expresion
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t == T_ERROR) {
                              yyerror("Variable sin declarar."); 
                              $$.t = T_ERROR;
                            } else if (infoVar.t == T_ARRAY) {
                              yyerror("Asignación sin indicar índice."); 
                              $$.t = T_ERROR;
                            } else if ($3.t == T_ERROR) { 
                              $$.t = T_ERROR;
                            } else if (infoVar.t != $3.t) {
                              yyerror("Tipo incorrecto en la asignación."); 
                              $$.t = T_ERROR;
                            } else {
                              emite(EASIG, crArgEnt($3.d), crArgNul(), crArgPos(infoVar.n, infoVar.d));
                              $$.t = T_VACIO; 
                            }
                          }
                          | ID_ ACOR_ expresion CCOR_ ASIG_ expresion
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t == T_ERROR) {
                              yyerror("Variable sin declarar."); 
                              $$.t = T_ERROR;
                            } else if (infoVar.t != T_ARRAY) {
                              yyerror("Variable de tipo diferente a array."); 
                              $$.t = T_ERROR;
                            } else if ($3.t == T_ERROR || $6.t == T_ERROR) {
                              $$.t = T_ERROR;
                            } else if ($3.t != T_ENTERO) {
                              yyerror("Índice de tipo incorrecto."); 
                              $$.t = T_ERROR;
                            } else {
                              DIM infoArray = obtTdA(infoVar.ref);
                              if (infoArray.telem != $6) {
                                yyerror("Tipo incorrecto en la asignación."); 
                                $$.t = T_ERROR;
                              } else {
                                emite(EVA, crArgPos(niv, infoVar.d), crArgPos(niv, $3.d), crArgPos(niv, $6.d));
                                $$.t = T_VACIO;
                              }
                            }
                          }
                          ;

          expresion_logica: expresion_igualdad { $$ = $1; }
                          | expresion_logica operador_logico expresion_igualdad 
                            { 
                              if ($1 == T_LOGICO && $3 == T_LOGICO) { 
                                int desp = creaVarTemp();
                                emite($2, crArgPos(niv, $1.p), crArgPos(niv, $3.p), crArgPos(niv, desp));
                                $$.t = T_LOGICO;
                                $$.d = desp;
                              }
					                    else if ($1 == T_ERROR || $3 == T_ERROR) {
                                $$ = T_ERROR;
                              } else { 
                                yyerror("Los tipos (logicos) no coinciden."); 
                                $$ = T_ERROR; 
                              }  
                            }
                          ;

        expresion_igualdad: expresion_relacional { $$ = $1; }
                          | expresion_igualdad operador_igualdad expresion_relacional
                            { 
                              if (($1.t == T_ENTERO && $3.t == T_ENTERO) ||
                                ($1.t == T_LOGICO && $3.t == T_LOGICO)) 
                              { 
                                int desp = creaVarTemp();
                                emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, desp));
                                emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si + 2));
                                emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, desp));                                $$.t = T_LOGICO;
                                $$.d = desp;
                              } else if ($1.t == T_ERROR || $3.t == T_ERROR) {
                                $$.t = T_ERROR;
                              } else { 
                                yyerror("Los tipos (igualdad) no coinciden."); 
                                $$.t = T_ERROR;
                              }
                            }
                          ;

      expresion_relacional: expresion_adicion { $$ = $1; }
                          | expresion_relacional operador_relacional expresion_adicion
                            { 
                              if ($1.t == T_ENTERO && $3.t == T_ENTERO) {
                                int desp = creaVarTemp();
                                emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, desp));
                                emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si + 2));
                                emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, desp));
                                $$.t = T_LOGICO; 
                                $$.d = desp;
                              } else if ($1.t == T_ERROR || $3.t == T_ERROR) {
                                $$.t = T_ERROR;
                              } else {
                                yyerror("Los tipos (relacionales) no coinciden."); 
                                $$.t = T_ERROR;
                              }
                            }
                          ;

         expresion_adicion: expresion_multiplicativa { $$ = $1; }
                          | expresion_adicion operador_adicion expresion_multiplicativa
                            { 
                              if ($1.t == T_ENTERO && $3.t == T_ENTERO) {
                                int desp = creaVarTemp();
                                emite($2, crArgPos(niv, $1.p), crArgPos(niv, $3.p), crArgPos(niv, desp));
                                $$.t = T_ENTERO;
                                $$.d = desp;
                              } else if ($1.t == T_ERROR || $3.t == T_ERROR) {
                                $$.t = T_ERROR;
                              } else {
                                yyerror("Los tipos (adicionales) no coinciden."); 
                                $$.t = T_ERROR;
                              }
                            }
                          ;

  expresion_multiplicativa: expresion_unaria { $$ = $1; }
                          | expresion_multiplicativa operador_multiplicativo expresion_unaria
                            { 
                              if ($1.t == T_ENTERO && $3.t == T_ENTERO) {
                                int desp = creaVarTemp();
                                emite($2, crArgPos(niv, $1.p), crArgPos(niv, $3.p), crArgPos(niv, desp));
                                $$.t = T_ENTERO;
                                $$.d = desp;
                              } else if ($1.t == T_ERROR || $3.t == T_ERROR) {
                                $$.t = T_ERROR;
                              } else {
                                yyerror("Los tipos (multiplicativos) no coinciden."); 
                                $$.t = T_ERROR;
                              }
                            }
                          ;

          // Revisar
          expresion_unaria: expresion_sufijo { $$ = $1; }
                          | operador_unario expresion_unaria
                            { 
                              if ($2.t == T_LOGICO) {
                                if ($1 == EDIF)
                                {
                                  int desp = creaVarTemp();
                                  emite($1, crArgEnt(1), crArgPos(niv, $2.d), crArgPos(niv, desp)); 
                                  $$.t == $2.t;
                                  $$.d == desp;
                                } else {
                                  yyerror("Operación incorrecta para tipo lógico (unaria).");
                                  $$.t = T_ERROR;
                                }
                              } else if ($2.t == T_ENTERO) {
                                if ($1 == EDIF || $1 == ESUM)
                                {
                                  int desp = creaVarTemp();
                                  if ($1 == EDIF)
                                    emite(ESIG, crArgPos(niv, $2.d), crArgNul(), crArgPos(niv, desp));
                                  else
                                    emite(EASIG, crArgPos(niv, $2.d), crArgNul(), crArgPos(niv, desp));
                                  $$.t == $2.t;
                                  $$.d == desp;
                                } else {
                                  yyerror("Operación incorrecta para tipo entero (unaria).");
                                  $$.t = T_ERROR;
                                }
                              } else if ($2.t == T_ERROR) {
                                $$.t = T_ERROR;                              
                              } else { 
                                yyerror("No es de tipo lógico o entero (unaria).");
                                $$.t = T_ERROR;
                              }
                            }
                          ;

          expresion_sufijo: constante 
                          { 
                            $$.t = $1.t;
                            int desp = creaVarTemp();
                            emite(EASIG, crArgEnt($1.v), crArgNul(), crArgPos(niv, desp));
                            $$.d = desp;
                          }
                          | APAR_ expresion CPAR_ { $$ = $2; }
                          | ID_
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t != T_ERROR) { 
                              $$.t = infoVar.t; 
                              $$.d = infoVar.d;
                            }
                            else {
                              yyerror("Variable no declarada.");
                              $$.t = T_ERROR;
                            }
                          }
                          | ID_ ACOR_ expresion CCOR_
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t == T_ERROR)
                            {
                              yyerror("Variable no declarada.");
                              $$.t = T_ERROR;
                            }
                            else if (infoVar.t != T_ARRAY)
                            {
                              yyerror("Variable de tipo incorrecto, se esperaba tipo array.");
                              $$.t = T_ERROR;
                            }
                            else if ($3 != T_ENTERO )
                            {
                              yyerror("Índice de tipo incorrecto, se esperaba tipo entero.");
                              $$.t = T_ERROR;
                            } else {
                              DIM infoArray = obtTdA(infoVar.ref);
                              if ($3.d > infoArray.nelem - 1) {
                                yyerror("Acceso fuera de límites del array.");
                                $$.t = T_ERROR;
                              } else {
                                int desp = creaVarTemp();
                                emite(EAV, crArgPos(niv, infoVar.d), crArgEnt($3.d * TALLA_TIPO_SIMPLE), crArgPos(niv, desp))
                                $$.t = infoArray.telem;
                                $$.d = desp;
                              }
                            }    
                          }
                          | ID_ APAR_ parametros_actuales CPAR_
                          {
                            SIMB infoVar = obtTdS($1);
                            INF infoFunc = obtTdD(infoVar.ref);
                            if (infoVar.t == T_ERROR || infoFunc.tipo == T_ERROR) {
                              yyerror("Función no declarada.");
                              $$.t = T_ERROR;
                            } else if (!cmpDom(infoVar.ref, $3)) {
                              yyerror("Parámetros incorrectos.");
                              $$.t = T_ERROR;
                            } else { $$.t = infoVar.t; }
                          }
                          ;

       parametros_actuales: /* Cadena vacía */ { $$ = insTdD(-1, T_VACIO); }
                          | lista_parametros_actuales { $$ = $1; }
                          ;

 lista_parametros_actuales: expresion { $$ = insTdD(-1, $1); }
                          | expresion COMA_ lista_parametros_actuales { $$ = insTdD($3, $1); }
                          ;

           operador_logico: OPAND_ { $$ = EMULT; }
                          | OPOR_  { $$ = ESUM;  }
                          ;

         operador_igualdad: OPIGUALDAD_     { $$ = EIGUAL;}
                          | OPDESIGUALDAD_  { $$ = EDIST; }
                          ;

       operador_relacional: OPMAYOR_      { $$ = EMAY;   }
                          | OPMENOR_      { $$ = EMEN;   }
                          | OPMAYORIGUAL_ { $$ = EMAYEQ; }
                          | OPMENORIGUAL_ { $$ = EMENEQ; }
                          ;

          operador_adicion: OPMAS_   { $$ = ESUM; }
                          | OPMENOS_ { $$ = EDIF; }
                          ;

   operador_multiplicativo: OPMUL_ { $$ = EMULT; }
                          | OPDIV_ { $$ = EDIVI; }
                          ;

           operador_unario: OPMAS_      { $$ = ESUM; }
                          | OPMENOS_    { $$ = EDIF; }
                          | OPNEGACION_ { $$ = EDIF; }
                          ;

%%
/*****************************************************************************/
