// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: codigo de chat-GPT revisado y comentado por mi
 * fuentes: https://chatgpt.com/
 * Análisis asintótico:
 * Forma en que se comento: 
 *  - primer bloque luego de las librerias: comprensión del problema.
 *  - primer línea de comentario: pseudo-codigo
 *  - lineas adicionales: correcciones de chat-GPT o de fuentes externas
 *  - bloque comentado después del código: análisis asintótico
*/
#include <iostream>      // Para entrada/salida estándar
#include <stack>         // Para usar la pila (stack)
#include <vector>        // Para manejar los arreglos dinámicos


using namespace std;

// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
*
* Entrada:
*
* Salida:
*
* Estructuras:
* 
* Funciones:
*
*/


// ############## CODIGO ##############


int main() {
  // mientras tengamos mas lineas las sigue leyendo
  // usa break para salir del loop
  while (true) {
    // establece n como el número de vagones que tendrá
    // cada uno de los casos o permutaciones a evaluar,
    // en caso de que sea 0 (para el utlimo del archivo)
    // sale definitivamente del loop para retornar 0 (de éxito de main)
    int n;
    cin >> n;
    if (n == 0) break; //esto lee el segundo cerco consecutivo por que 
                        //el primero fue leido en el while interno

    while (true) {
      // se crea el vector de tamaño n para almacenar la permutacion de la 
      // linea
      vector<int> objetivo(n);
      // se lee el primer numero de la linea para verificar si es 0 y en 
      // ese caso cerrar la permutacion
      cin >> objetivo[0];
      if (objetivo[0] == 0) break; // Fin del bloque cuando no hay 
                                    // mas permutaciones

      // se lee el resto de la linea para agregar al vector objetivo
      for (int i = 1; i < n; ++i) {
        cin >> objetivo[i];
      }

      // se crea el stack de enteros vacio de vagones que estan 
      // apilados en la estacion para ser devueltos a B en orden
      // opuesto al que ingresaron (por eso stack)
      stack<int> estacion;
      int siguiente = 1;  // vagon que entra desde A, iniciando desde 1
                          // ya que el problema no contempla vagon 0
      int indice = 0;     // Índice en la secuencia objetivo
      // tercer ciclo while, recive el siguiente vagon y lo 
      // pone en B si es que es el siguiente correcto segun los objetivos
      // o lo pone en el stack de la estacion si es que no corresponde
      while (siguiente <= n) {
        estacion.push(siguiente); // el vagon entra al stack
        // cuarto ciclo while que intenta si es posible sacar el siguiente
        // vagon desde el stack para ir completando B
          while (!estacion.empty() && estacion.top() == objetivo[indice]) {
            estacion.pop(); // va vaciando el stack a medida que se usa
            ++indice; // actualiza el indice para verificar el siguiente objetivo
                     // ya que el actual ya fue satisfecho
          }
          ++siguiente; // actualizamos siguiente y pasamos al siguiente vagon de A
        }
      // en el caso de éxito se vació el stack ya que en el ciclo while que 
      // recién terminó conseguimos vaciar A, por lo que si no hay nada en A,
      // no hay nada en el stack y B esta ordenado segun objetivo, entonces 
      // hemos conseguido comprobar que se puede ordenar de la forma deseada
      if (estacion.empty()) {
        cout << "Yes\n";
      // si queda algo en el stack, entonces no se puede ordenar 
      // como se plantea en la linea
      } else {
        cout << "No\n";
      }
    }
      cout << '\n'; // Línea en blanco entre bloques
    }

    return 0;
}





// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
* si bien la estructura del código con 4 ciclos anidados
* parecería indicar una alta complegidad temporal esto no 
* es tan directo, las operaciones sobre stack: push, top y pop
* y la lectura de arreglos en indices conocidos son lineales:
* - Ciclo while 1:  opera sobre las lineas iniciales y del numero 
*                   de vagones O(casos)
* - Ciclo while 2:  opera sobre las lineas no leidas en el primero
*                   y completa O(lineas)
* - Ciclo while 3:  opera sobre los vagones de cada permutacion
*                   O(vagones)
* - Ciclo while 4:  realiza comparaciones (tiempo lineal) por cada
*                   valor de vagones.
* Resultado: O(casos*lineas*vagones*vagones)
*
*
* espacio:
* las estructuras son mas bien pequeñas, siendo los stack O(vagones)
* el vector de los vagones objetivos O(vagones) y estos se no se requieren
* despues del análiss de cada linea, por lo que el código es muy bajo
* en consumo de memoria:
* O(vagones)
*
*/
