// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: codigo de chat-GPT
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
    int n;
    cin >> n;
    if (n == 0) break;

    while (true) {
      vector<int> objetivo(n);
      cin >> objetivo[0];
      if (objetivo[0] == 0) break; // Fin del bloque

      // Leer el resto de la permutación
      for (int i = 1; i < n; ++i) {
        cin >> objetivo[i];
      }

      stack<int> estacion;
      int siguiente = 1;  // Vagón que entra desde A
      int indice = 0;     // Índice en la secuencia objetivo

      while (siguiente <= n) {
        estacion.push(siguiente); // El vagón entra a la estación
        // Intentar mover desde estación a B si coincide con lo deseado
          while (!estacion.empty() && estacion.top() == objetivo[indice]) {
            estacion.pop();
            ++indice;
          }
          ++siguiente;
        }

      if (estacion.empty()) {
        cout << "Yes\n";
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
*
* espacio:
*
*/
