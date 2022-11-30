// Ejemplo sintactico-semantico (absurdo) sin errores.
// Comprobad el resultado con la funcion "verTdS". Advertid
// que los parametros se situen en orden inverso en la TdS
// y deben tener desplazamientos negativos.
//---------------------------------------------------------
bool a;
int  b[27];

int F (int x, int y)
{ 
   bool a[27]; int b; 

  return y-x;
}

int c[27];
int d;

int main()
{
  int z[27];  int x; 

  read(x); read(d);

  if (x < d) print( F(x,d));
  else print( F(d,x));

  return 0;
}
    
  x = 14;  y = true;
  if (x) {                 // La expresion del `if' debe ser 'logico'
    x = X(x, y);           // En la asignacion a una variable simple
    x = Y(y, x);           // En el dominio de los parametros actuales
  }
  else {}
  return 0;                // En la declaracion de la funcion [1]
}                          // El programa tiene mas de un `main'

// [1] El error en la declaracion de la funcion se detecta al
//     analizar la expresion del "return" ya que la declaracion
//     de la funcion no se pudo completar por un error anterior.
