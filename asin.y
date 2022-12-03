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
                  programa: lista_declaraciones
                          ;

       lista_declaraciones: declaracion
                          | lista_declaraciones declaracion
                          ;

               declaracion: declaracion_variable
                          | declaracion_funcion
                          ;

      declaracion_variable: tipo_simple ID_ PCOMA_
                          | tipo_simple ID_ ASIG_ constante PCOMA_
                          | tipo_simple ID_ ALLAVE_ CTE_ CLLAVE_ PCOMA_
                          ;

                 constante: CTE_
                          | TRUE_
                          | FALSE_
                          ;

               tipo_simple: INT_
                          | BOOL_
                          ;

       declaracion_funcion: tipo_simple ID_ APAR_ parametros_formales CPAR_ bloque
                          ;

       parametros_formales: 
                          | lista_parametros_formales
                          ;

 lista_parametros_formales: tipo_simple ID_
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
                          | PRINT_ APAR_ expresion CPAR_ PCOMA_
                          ;

     instruccion_seleccion: IF_ APAR_ expresion CPAR_ instruccion ELSE_ instruccion
                          ;

     instruccion_iteracion: FOR_ APAR_ expresion_opcional PCOMA_ expresion PCOMA_ expresion_opcional CPAR_ instruccion
                          ;

        expresion_opcional:
                          | expresion
                          ;

                 expresion: expresion_logica
                          | ID_ ASIG_ expresion
                          | ID_ ALLAVE_ expresion CLLAVE_ ASIG_ expresion
                          ;

          expresion_logica: expresion_igualdad { $$ = $1; }
                          | expresion_logica operador_logico expresion_igualdad 
                            { if ($1 == T_LOGICO && $3 == T_LOGICO) { $$ = T_LOGICO; }
					                    else { $$ = T_ERROR; 
                                    yyerror("Error. Los tipos (logicos) no coinciden."); 
                                    $$ = T_ERROR;
                                   }
                            }
                          ;

        expresion_igualdad: expresion_relacional { $$ = $1; }
                          | expresion_igualdad operador_igualdad expresion_relacional
                            { if (($1 == T_ENTERO && $3 == T_ENTERO) ||
                                    ($1 == T_LOGICO && $3 == T_LOGICO)) { $$ = T_LOGICO; }
                                else { $$ = T_ERROR; 
                                      yyerror("Error. Los tipos (igualdad) no coinciden."); 
                                      $$ = T_ERROR;
                                    }
                            }
                          ;

      expresion_relacional: expresion_adicion { $$ = $1; }
                          | expresion_relacional operador_relacional expresion_adicion
                            { if ($1 == T_ENTERO && $3 == T_ENTERO) { $$ = T_LOGICO; }
                                else { $$ = T_ERROR; 
                                      yyerror("Error. Los tipos (relacionales) no coinciden."); 
                                      $$ = T_ERROR;
                                    }
                            }
                          ;

         expresion_adicion: expresion_multiplicativa { $$ = $1; }
                          | expresion_adicion operador_adicion expresion_multiplicativa
                            { if ($1 == T_ENTERO && $3 == T_ENTERO) { $$ = T_LOGICO; }
                                else { $$ = T_ERROR; 
                                      yyerror("Error. Los tipos (adicionales) no coinciden."); 
                                      $$ = T_ERROR;
                                    }
                            }
                          ;

  expresion_multiplicativa: expresion_unaria { $$ = $1; }
                          | expresion_multiplicativa operador_multiplicativo expresion_unaria
                            { if ($1 == T_ENTERO && $3 == T_ENTERO) { $$ = T_LOGICO; }
                                else { $$ = T_ERROR; 
                                      yyerror("Error. Los tipos (multiplicativos) no coinciden."); 
                                      $$ = T_ERROR;
                                    }
                            }
                          ;

          expresion_unaria: expresion_sufijo { $$ = $1; }
                          | operador_unario expresion_unaria
                          ;

          expresion_sufijo: constante
                          | APAR_ expresion CPAR_
                          | ID_
                          | ID_ ALLAVE_ expresion CLLAVE_
                          | ID_ APAR_ parametros_actuales CPAR_
                          ;

       parametros_actuales: 
                          | lista_parametros_actuales
                          ;

 lista_parametros_actuales: expresion
                          | expresion COMA_ lista_parametros_actuales 
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
