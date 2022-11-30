/*****************************************************************************/
/**  Mireia Pires State, Andrea Gascó Pau e Iñaki Diez Lambies    2022-2023 **/
/*****************************************************************************/

/*----------------------
  Subseccion preambulo
------------------------*/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define  retornar(x) {if (verbosidad) ECHO; return(x); }
%}
/*---------------------------------------------------------------------
  Estas opciones evitan "warnings" innecesarios y permiten obtener el
  numero de linea actual en la variable global "yylineno".
-----------------------------------------------------------------------*/

/*-------------------------
  Subseccion definiciones
---------------------------*/
%option noinput       
%option nounput       
%option yylineno  

/*----------------------
  Expresiones regulares
------------------------*/
delimitador    [ \t\n]+
letra          [A-Za-z] 
digito         [0-9]
entero         {digito}+
real1          {entero}"."{digito}*
real2          {digito}*"."{entero}
comentario     \/\/.*
id             {letra}({letra}|{digito}|"_")*

/*----------------------
  Subseccion reglas
------------------------*/
%%
{comentario}   { if (verbosidad) ECHO; }

"true"         { retornar(TRUE_);   }
"false"        { retornar(FALSE_);  }
"int"          { retornar(INT_);    }
"bool"         { retornar(BOOL_);   }
"return"       { retornar(RETURN_); }
"read"         { retornar(READ_);   }
"print"        { retornar(PRINT_);  }
"if"           { retornar(IF_);     }
"else"         { retornar(ELSE_);   }
"for"          { retornar(FOR_);    }

{id}           { retornar(ID_);     }
{entero}       { retornar(CTE_);    }
{real1}        { retornar(CTE_);    }
{real2}        { retornar(CTE_);    }

"="            { retornar(ASIG_);   }

"&&"           { retornar(OPAND_);  }
"||"           { retornar(OPOR_);   }

"=="           { retornar(OPIGUALDAD_);    }
"!="           { retornar(OPDESIGUALDAD_); }

">"            { retornar(OPMAYOR_);       }
"<"            { retornar(OPMENOR_);       }
">="           { retornar(OPMAYORIGUAL_);  }
"<="           { retornar(OPMENORIGUAL_);  }

"+"	           { retornar(OPMAS_);   }
"-"            { retornar(OPMENOS_); }

"*"            { retornar(OPMUL_);   }
"/"            { retornar(OPDIV_);   }

"!"            { retornar(OPNEGACION_); }

{delimitador}  { if (verbosidad) ECHO;  }
"("            { retornar(APAR_);       }
")"            { retornar(CPAR_);       }
"{"            { retornar(ACOR_);       }
"}"            { retornar(CCOR_);       }
"["            { retornar(ALLAVE_);     }
"]"            { retornar(CLLAVE_);     }
","            { retornar(COMA_);       }
";"            { retornar(PCOMA_);      }

.	             { yyerror("Caracter desconocido"); }
%%