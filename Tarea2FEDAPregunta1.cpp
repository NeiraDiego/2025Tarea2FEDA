// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: propia con asistencia de chat-GPT para errores de sintaxis
 * fuentes: https://chatgpt.com/
 * Análisis asintótico:
 * Forma en que se comento: 
 *  - primer bloque luego de las librerias: comprensión del problema.
 *  - primer línea de comentario: pseudo-codigo
 *  - lineas adicionales: correcciones de chat-GPT o de fuentes externas
 *  - bloque comentado después del código: análisis asintótico
*/
#include <iostream>
#include <fstream>
/*
Descripción del problema:
Se trata de minimizar el tiempo total de utilizacion de un ascensor:
- total de pisos 31 (-1 que es el piso base)
- el tiempo que toma el ascensor en subir un piso es 4 segundos
- si el ascensor se detiene esto toma 10 segundos adicionales
- subir un piso a pie toma 20 segundos

Entrada:
- por linea se entrega un caso, primer dato el numero de entradas en el caso,
  seguido por el valor del piso en el que se requiere detener 
- el numero de casos 0 indica que se acabaron las entradas

estructuras:
- arreglo de valores 0 si no se detiene, 1 si se detiene



funciones:
- lectura del archivo 
- determinar si el piso f se detiene o no
- escritura del archivo

fuerza bruta? combinatoria de todos las posibles combinaciones 
de pasar o no por un piso?
*/

// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* Se debe buscar el menor numero de caracteres que hacen una combinacion
* que puede formar la palabra completa por repetición en cuestion
*
* Entrada:
* - Una linea en la que se indica el numero de casos
* - Las demas lineas son cadenas de caractéres que componen las palabras
*
* Salida:
* - una linea por tipo que 
*
* Estructuras:
* 
* Funciones:
*
*/


// ############## CODIGO ##############
int main (int argc, char *argv[]) {
 /*  // lectura por linea  
  string linea;
  while (getline(cin, linea)){

    cout << "Línea leída: "<< linea << endl;
  }
*/

/*
  // lectura de entero único por linea
  int x;
  while (cin >> x) {
    cout << "Leí: " << x << endl;
  }
*/

/*
  // lectura a vector de enteros
  vector<int> datos;
  int x;
  while (cin >> x) {
    datos.push_back(x);
  }

  for(int d: datos) {
    cout << d << endl;
  }
  return 0;
*/ 
  return 0;
}




// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
*
* espacio:
*
*/
