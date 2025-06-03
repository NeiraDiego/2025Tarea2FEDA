// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: codigo asistido por chat-GPT, con comentarios y análisis propio
 * fuentes: https://chatgpt.com/
 * Forma en que se comento: 
 *  - primer bloque luego de las librerias: comprensión del problema.
 *  - primer línea de comentario: pseudo-codigo
 *  - lineas adicionales: correcciones de chat-GPT o de fuentes externas
 *  - bloque comentado después del código: análisis asintótico
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>    // Para sort
#include <sstream>      // Para procesar cada línea
#include <string>

using namespace std;

// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* se busca establecer la cantidad maxima de repeticiones
* de una combinación de cursos 
*
* Entrada:
* primera linea la cantidad de e estudiantes del muestreo
* e lineas con los 5 cursos de 100-499 que eligio cada estudiante
* 0 para indicar que se acabó el último muestreo
*
* Salida: 
* una linea por muestreo que indique la maxima frecuencia de las combinaciones
*
*/


// ############## CODIGO ##############

int main() {
    int n; // def la variable para el numero de estudiantes que entregará el input

    while (true) {
        cin >> n; // leemos la primera linea como numero de estudiantes
        if (n == 0) break; // leemos el 0 como linea de salida para terminar el programa

        map<vector<int>, int> frecuencia; // mapa, la parte mas importante del código
                                          // porque aqui es donde se almacenará 
                                          // la frecuencia de las dif combinaciones
        int max_frecuencia = 0; // Popularidad máxima iniciada en cero para buscar un máximo

        for (int i = 0; i < n; ++i) { // vamos a poblar el mapa con n (estudiantes)
            vector<int> cursos(5); // primero creamos el vector de cursos con tamaño fijo 5
                                  // ya que eso está dado en el problema
                                  // como maximos cursos que se pueden inscribir
            for (int j = 0; j < 5; ++j) { // para cada estudiante poblamos con los 
                                          // 5 cursos iscritos
                cin >> cursos[j];
            }
            sort(cursos.begin(), cursos.end()); // ordenamos los cursos para comparar
                                                // independiente de el orden en 
                                                // que se ingresan
            frecuencia[cursos]++; // en el map en el indice identificado por el vector de cursos
                                  // ordenados agregamos 1 a la frecuencia o la creamos si no está
            if (frecuencia[cursos] > max_frecuencia) { // se revisa si el nuevo valor de 
                                                      // frecuencia es la mayor hasta ahora
                max_frecuencia = frecuencia[cursos];  // y se reemplaza si lo es
            }
        }

        int total = 0; // definimos la variable para indicar el resultado final por linea
        for (const auto& par : frecuencia) { // revisamos cada elemento "par" del map
                                            // frecuencia 
            if (par.second == max_frecuencia) { // si la combinacion cumple que tiene la 
                                                // frecuencia máxima entonces
                total += par.second;  // la agregamos a la cuenta de cuantas cumple
            }
        }

        cout << total << endl; // imprmimimos el total de cuantas cumplen
    }

    return 0;
}




// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
* - la lectura de los datos depende de n, el numero de estudiantes
*   si bien se leen cada uno de los cursos estos son cte = 5 por lo 
*   que queda O(n)
* - el ordenamiento es tiempo constante O(5) por lo explicado anteriormente
* - la inserciones son O(logn) para cada inserción pero son n inserciones
*   por lo que tenemos O(n*log(n))
* - la impresión tiene un valor esperado constante pero peor caso O(n)
*   por lo que el codigo es O(n*log(n))
*
* espacio:
* - la estructura relevante es la estructura mas relevante y si bien tiene 
*   como llave un vector este es de tamaño constante 5 por lo que es:
*   O(n)
*
*/
