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
  char* ident;
  PF pf;
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
%type <cent> lista_declaraciones declaracion constante tipo_simple declaracion_funcion
%type <cent> parametros_formales expresion_opcional expresion expresion_logica
%type <cent> expresion_igualdad expresion_relacional expresion_adicion
%type <cent> expresion_multiplicativa expresion_unaria expresion_sufijo
%type <cent> parametros_actuales lista_parametros_actuales
%type <pf> lista_parametros_formales
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
                            { yyerror("Error. Debe de haber al menos una función main."); }
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
                              yyerror("Error. Variable ya declarada.");
                          }
                          | tipo_simple ID_ ASIG_ constante PCOMA_
                          {
                            if ($4 != T_ENTERO)
                              yyerror("Error. Constante no entera");
                            else if ($1 != $4)
                              yyerror("Error. Tipo de variable diferente del asignado.");
                            else
                            {
                              if (insTdS($2, VARIABLE, $1, niv, dvar, -1))
                                dvar += TALLA_TIPO_SIMPLE;
                              else
                                yyerror("Error. Variable ya declarada.");
                            }
                          }
                          | tipo_simple ID_ ACOR_ CTE_ CCOR_ PCOMA_
                          {
                            if ($4 != T_ENTERO)
                              yyerror("Error. Tamaño del array de tipo incorrecto.");
                            else
                            {
                              if (insTdS($2, VARIABLE, $1, niv, dvar, -1))
                                dvar += TALLA_TIPO_SIMPLE;
                              else
                                yyerror("Error. Variable ya declarada.");
                            }
                          }
                          ;

                 constante: CTE_ { $$ = T_ENTERO; }
                          | TRUE_ { $$ = T_LOGICO; }
                          | FALSE_ { $$ = T_LOGICO; }
                          ;

               tipo_simple: INT_ { $$ = T_ENTERO; }
                          | BOOL_ { $$ = T_LOGICO; }
                          ;

       declaracion_funcion: tipo_simple ID_ 
                          {
                            niv = 1;
                            cargaContexto(niv); 
                          }
                            APAR_ parametros_formales CPAR_ bloque
                          {
                            if (insTdS($2, FUNCION, $1, niv - 1, -1, $5))
                            {
                              if (strcmp($2, "main\0") != 0) { $$ = 1; }
                              else { $$ = 0; }
                            }
                            else { yyerror("Error. Declaración repetida de la función."); }
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
                              yyerror("Error. Declaración repetida del parámetro.");
                          }
                          | tipo_simple ID_ COMA_ lista_parametros_formales
                          {
                            $$.ref = insTdD($4.ref, $1);
                            int talla = $4.talla + TALLA_TIPO_SIMPLE;
                            $$.talla = talla;
                            if (!insTdS($2, PARAMETRO, $1, niv, -talla, -1))
                              yyerror("Error. Declaración repetida del parámetro.");
                          }        
                          ;

                    bloque: ALLAVE_ declaracion_variable_local lista_instrucciones RETURN_ expresion PCOMA_ CLLAVE_
                          {
                            INF infoFunc = obtTdD(-1);
                            if (infoFunc.tipo != $5) { yyerror("Error. Tipo de retorno incorrecto."); }
                          }
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
                            {
                              yyerror("Error. Variable sin declarar."); 
                            } else if (infoVar.t != T_ENTERO)
                            {
                              yyerror("Error. Variable diferente de entero.");
                            }
                          }
                          | PRINT_ APAR_ expresion CPAR_ PCOMA_
                          {
                            if ($3 == T_ERROR)
                            {
                              yyerror("Error. Variable sin declarar."); 
                            } else if ($3 != T_ENTERO)
                            {
                              yyerror("Error. Variable diferente de entero.");
                            }
                          }
                          ;

     instruccion_seleccion: IF_ APAR_ expresion CPAR_ 
                          {
                            if ($3 != T_LOGICO) { yyerror("Error. Condición incorrecta."); }
                          }
                            instruccion ELSE_ instruccion
                          ;

     instruccion_iteracion: FOR_ APAR_ expresion_opcional PCOMA_ expresion PCOMA_ expresion_opcional CPAR_
                          {
                            if ($3 == T_ERROR) {
                              yyerror("Error. Inicialización incorrecta."); 
                            } else if ($5 != T_LOGICO) {
                              yyerror("Error. Condición incorrecta."); 
                            } else if ($7 == T_ERROR) {
                              yyerror("Error. Paso incorrecto"); 
                            }
                          }
                            instruccion
                          ;

        expresion_opcional: /* Cadena vacía */ { $$ = T_VACIO; }
                          | expresion { $$ = $1; }
                          ;

                 expresion: expresion_logica { $$ = $1; }
                          | ID_ ASIG_ expresion
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t == T_ERROR) {
                              yyerror("Error. Variable sin declarar."); 
                              $$ = T_ERROR;
                            } else if (infoVar.t == T_ARRAY) {
                              yyerror("Error. Asignación sin indicar índice."); 
                              $$ = T_ERROR;
                            } else if (infoVar.t != $3) {
                              yyerror("Error. Tipo incorrecto en la asignación."); 
                              $$ = T_ERROR;
                            } else { $$ = T_VACIO; }
                          }
                          | ID_ ACOR_ expresion CCOR_ ASIG_ expresion
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t == T_ERROR) {
                              yyerror("Error. Variable sin declarar."); 
                              $$ = T_ERROR;
                            } else if (infoVar.t != T_ARRAY) {
                              yyerror("Error. Variable de tipo diferente a array."); 
                              $$ = T_ERROR;
                            } else if ($3 == T_ENTERO) {
                              yyerror("Error. Índice de tipo incorrecto."); 
                              $$ = T_ERROR;
                            } else {
                              DIM infoArray = obtTdA(infoVar.ref);
                              if (infoArray.telem != $6) {
                                yyerror("Error. Tipo incorrecto en la asignación."); 
                                $$ = T_ERROR;
                              } else {
                                $$ = T_VACIO;
                              }
                            }

                          }
                          ;

          expresion_logica: expresion_igualdad { $$ = $1; }
                          | expresion_logica operador_logico expresion_igualdad 
                            { 
                              if ($1 == T_LOGICO && $3 == T_LOGICO) { $$ = T_LOGICO; }
					                    else {
                                yyerror("Error. Los tipos (logicos) no coinciden."); 
                                $$ = T_ERROR;
                              }
                            }
                          ;

        expresion_igualdad: expresion_relacional { $$ = $1; }
                          | expresion_igualdad operador_igualdad expresion_relacional
                            { 
                              if (($1 == T_ENTERO && $3 == T_ENTERO) ||
                                ($1 == T_LOGICO && $3 == T_LOGICO)) 
                              { 
                                $$ = T_LOGICO; 
                              } else { 
                                yyerror("Error. Los tipos (igualdad) no coinciden."); 
                                $$ = T_ERROR;
                              }
                            }
                          ;

      expresion_relacional: expresion_adicion { $$ = $1; }
                          | expresion_relacional operador_relacional expresion_adicion
                            { 
                              if ($1 == T_ENTERO && $3 == T_ENTERO) { $$ = T_LOGICO; }
                              else {
                                yyerror("Error. Los tipos (relacionales) no coinciden."); 
                                $$ = T_ERROR;
                              }
                            }
                          ;

         expresion_adicion: expresion_multiplicativa { $$ = $1; }
                          | expresion_adicion operador_adicion expresion_multiplicativa
                            { 
                              if ($1 == T_ENTERO && $3 == T_ENTERO) { $$ = T_LOGICO; }
                              else {
                                yyerror("Error. Los tipos (adicionales) no coinciden."); 
                                $$ = T_ERROR;
                              }
                            }
                          ;

  expresion_multiplicativa: expresion_unaria { $$ = $1; }
                          | expresion_multiplicativa operador_multiplicativo expresion_unaria
                            { 
                              if ($1 == T_ENTERO && $3 == T_ENTERO) { $$ = T_LOGICO; }
                              else {
                                yyerror("Error. Los tipos (multiplicativos) no coinciden."); 
                                $$ = T_ERROR;
                              }
                            }
                          ;

          // Revisar
          expresion_unaria: expresion_sufijo { $$ = $1; }
                          | operador_unario expresion_unaria
                            { 
                              if ($2 == T_LOGICO) { $$ = T_LOGICO; }
                              else { 
                                yyerror("Error. No es de tipo lógico (unaria).");
                                $$ = T_ERROR;
                              }
                            }
                          ;

          expresion_sufijo: constante { $$ = T_ENTERO; }
                          | APAR_ expresion CPAR_ { $$ = $2; }
                          | ID_
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t != T_ERROR) { $$ = infoVar.t; }
                            else {
                              yyerror("Error. Variable no declarada.");
                              $$ = T_ERROR;
                            }
                          }
                          | ID_ ACOR_ expresion CCOR_
                          {
                            SIMB infoVar = obtTdS($1);
                            if (infoVar.t == T_ERROR)
                            {
                              yyerror("Error. Variable no declarada.");
                              $$ = T_ERROR;
                            }
                            else if (infoVar.t != T_ARRAY)
                            {
                              yyerror("Error. Variable de tipo incorrecto, se esperaba tipo array.");
                              $$ = T_ERROR;
                            }
                            else if ($3 != T_ENTERO )
                            {
                              yyerror("Error. Índice de tipo incorrecto, se esperaba tipo entero.");
                              $$ = T_ERROR;
                            } else {
                              DIM infoArray = obtTdA(infoVar.ref);
                              // Revisar
                              // if ($3 < 0 || $3 >= infoArray.nelem) {
                              //   yyerror("Error. Índice fuera de rango.");
                              //   $$ = T_ERROR;
                              // }
                              // else { $$ = infoArray.telem; }
                              $$ = infoArray.telem;
                            }    
                          }
                          | ID_ APAR_ parametros_actuales CPAR_
                          {
                            SIMB infoVar = obtTdS($1);
                            INF infoFunc = obtTdD(infoVar.ref);
                            if (infoVar.t == T_ERROR || infoFunc.tipo == T_ERROR) {
                              yyerror("Error. Función no declarada.");
                              $$ = T_ERROR;
                            } else if (!cmpDom(infoVar.ref, $3)) {
                              yyerror("Error. Parámetros incorrectos.");
                              $$ = T_ERROR;
                            } else { $$ = infoVar.t; }
                          }
                          ;

       parametros_actuales: /* Cadena vacía */ { $$ = insTdD(-1, T_VACIO); }
                          | lista_parametros_actuales { $$ = $1; }
                          ;

 lista_parametros_actuales: expresion { $$ = insTdD(-1, $1); }
                          | expresion COMA_ lista_parametros_actuales { $$ = insTdD($3, $1); }
                          ;

           operador_logico: OPAND_
                          | OPOR_
                          ;

         operador_igualdad: OPIGUALDAD_
                          | OPDESIGUALDAD_
                          ;

       operador_relacional: OPMAYOR_
                          | OPMENOR_
                          | OPMAYORIGUAL_
                          | OPMENORIGUAL_
                          ;

          operador_adicion: OPMAS_
                          | OPMENOS_
                          ;

   operador_multiplicativo: OPMUL_
                          | OPDIV_
                          ;

           operador_unario: OPMAS_
                          | OPMENOS_
                          | OPNEGACION_
                          ;

%%
/*****************************************************************************/
