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
%}

%union{
  int cent;
  char *ident; 
}

// Declaraciones Bison
%token IF_ ELSE_ FOR_ RETURN_
%token ASIG_ OPIGUALDAD_ OPDESIGUALDAD_ OPMAYOR_ OPMENOR_ OPMAYORIGUAL_ OPMENORIGUAL_
%token OPMAS_ OPMENOS_ OPMUL_ OPDIV_ OPAND_ OPOR_ OPNEGACION_
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAVE_ CLLAVE_ COMA_ PCOMA_

// Para los terminales
%token <cent> CTE_ TRUE_ FALSE_ INT_ BOOL_ READ_ PRINT_
%token <*ident> ID_

// Para los no-terminales
%type <cent> const tipo_simple 
%type <cent> expresion_opcional expresion expresion_logica expresion_igualdad expresion_relacional
%type <cent> expresion_adicion expresion_multiplicativa expresion_unaria expresion_sufijo
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
                            if (indsTdS($2, VARIABLE, $1, niv, dvar))
                              dvar += TALLA_TIPO_SIMPLE;
                            else
                              yyerror("Error. Variable ya declarada.")
                          }
                          | tipo_simple ID_ ASIG_ constante PCOMA_
                            if ($4 != T_ENTERO)
                              yyerror("Error. Constante no entera")
                            else if ($1 != $4)
                              yyerror("Error. Tipo de variable diferente del asignado.")
                            else
                            {
                              if (indsTdS($2, VARIABLE, $1, niv, dvar))
                                dvar += TALLA_TIPO_SIMPLE;
                              else
                                yyerror("Error. Variable ya declarada.")
                            }
                          | tipo_simple ID_ ALLAVE_ CTE_ CLLAVE_ PCOMA_
                          {
                            if ($4 != T_ENTERO)
                              yyerror("Error. Tamaño del array de tipo incorrecto.")
                            else
                            {
                              if (indsTdS($2, VARIABLE, $1, niv, dvar))
                                dvar += TALLA_TIPO_SIMPLE;
                              else
                                yyerror("Error. Variable ya declarada.")
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
                            niv = niv + 1; // REVISAR - Es = niv + 1 o = 1?
                            cargaContexto(niv); 
                          }
                            APAR_ parametros_formales CPAR_ bloque
                          {
                            if (indsTdS($2, FUNCION, $1, niv - 1, -1 /* REVISAR - Por qué -1? */, $5))
                            {
                              if (strcmp($2, "main\0") != 0) { $$ = 1; }
                              else { $$ = 0; }
                            }
                            else { yyerror("Error. Declaración repetida de la función."); }
                          }
                          ;

       parametros_formales: /* Cadena vacía */ { $$  = insTdD(-1, T_VACIO); }
                          | lista_parametros_formales { $$ = $1; }
                          ;
// REVISAR - Hará falta crear una estructura para la lista de parámetros formales de forma
//           que se pueda saber la referencia del primero (último?) en ser añadido así como
//           que conforme se vayan añadiendo se tenga en cuenta su talla para el desplazamiento
//           en la inserción de la TdD
 lista_parametros_formales: tipo_simple ID_  
                          {

                          }
                          | tipo_simple ID_ COMA_ lista_parametros_formales                   
                          ;

                    bloque: ACOR_ declaracion_variable_local lista_instrucciones RETURN_ expresion PCOMA_ CCOR_
                          ;

declaracion_variable_local: 
                          | declaracion_variable_local declaracion_variable
                          ;

       lista_instrucciones: 
                          | lista_instrucciones instruccion
                          ;

               instruccion: ACOR_ lista_instrucciones CCOR_
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
                            } else if (infoVar != T_ENTERO)
                            {
                              yyerror("Error. Variable diferente de entero.")
                            }
                          }
                          | PRINT_ APAR_ expresion CPAR_ PCOMA_
                          {
                            SIMB infoVar = obtTdS($3);
                            if (infoVar.t == T_ERROR)
                            {
                              yyerror("Error. Variable sin declarar."); 
                            } else if (infoVar != T_ENTERO)
                            {
                              yyerror("Error. Variable diferente de entero.")
                            }
                          }
                          ;

     instruccion_seleccion: IF_ APAR_ expresion CPAR_ 
                          {
                            if ($3 != T_LOGICO) {
                              yyerror("Error. Condición incorrecta."); 
                              $$ = T_ERROR
                            } else { $$ = T_LOGICO}
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
                            SIMB infoVar = obtTdS($1)
                            if (infoVar.t == T_ERROR) {
                              yyerror("Error. Variable sin declarar."); 
                              $$ = T_ERROR;
                            } else if (infoVar.t == T_ARRAY) {
                              yyerror("Error. Asignación sin indicar índice."); 
                              $$ = T_ERROR;
                            } else if (infoVar.t != $3) {
                              yyerror("Error. Tipo incorrecto en la asignación."); 
                              $$ = T_ERROR;
                            } else { $$ = $1; }
                          }
                          | ID_ ALLAVE_ expresion CLLAVE_ ASIG_ expresion
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
                          | ID_ ALLAVE_ expresion CLLAVE_
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
                              if ($3 < 0 || $3 >= infoArray.nelem) {
                                yyerror("Error. Índice fuera de rango.");
                                $$ = T_ERROR;
                              }
                              else { $$ = infoArray.telem; }
                            }    
                          }
                          | ID_ APAR_ parametros_actuales CPAR_
                          {
                            SIMB infoVar = obtTdS($1);
                            INF infoFunc = obtTdD(infoVar.ref)
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
