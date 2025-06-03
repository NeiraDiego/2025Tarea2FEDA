// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: propia con asistencia de chat-GPT
 * fuentes: https://chatgpt.com/
 * Análisis asintótico:
 * Forma en que se comento: 
 *  - primer bloque luego de las librerias: comprensión del problema.
 *  - primer línea de comentario: pseudo-codigo
 *  - lineas adicionales: correcciones de chat-GPT o de fuentes externas
 *  - bloque comentado después del código: análisis asintótico
*/

#include <iostream>
#include <string>
#include <list>          // lista doblemente enlazada

using namespace std;

// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* Se inceratron involuntariamente los comandos de inicio de linea y 
* de fin de linea indicados con los simbolos ] y [ respectivamente
* la tarea es reordenar el texto de acuerdo y eliminar los caracteres
*
* Entrada:
* Lineas de texto con los caracteres en cuestion para ser ordenados
* termina la iteracion con el EOF (end-of-file)
*
* Salida:
* La cantidad de lineas de texto pero ordenadas y sin los signos
*
*
* Aproximación:
* se tomaran las lineas y se procesarán hasta encontrar uno de los 
* caracteres y entonces se cambiará el modo de incertar de al final
* del arreglo al principio o vice-versa, para esto voy a usar 
* una lista doblemente enlazada para poder agregar al comienzo o 
* final segun corresponda
*/


// ############## CODIGO ##############


int main() {
    string linea;// definimos la variable donde almacenaremos el texto de la linea
    
    // Leemos cada línea hasta fin de archivo (EOF), cuando llegamos al final del archivo
    // y no hay mas lineas por leer getline arroga False asi que escapamos correctamente
    while (getline(cin, linea)) {
        list<char> resultado;             // Lista doble enlazada para almacenar el texto final
        auto cursor = resultado.begin();  // Iterador que simula la posición del cursor

        for (char c : linea) {// recorremos cada caracter en la linea uno por uno
            if (c == '[') { // cuando encontramos el signo de home
                // Simula tecla "inicio" entonces movemos el cursor al inicio
                cursor = resultado.begin();
            } else if (c == ']') {
                // Simula tecla "fin" asi que muevo el cursor al final
                cursor = resultado.end();
            } else {
                // cuando encontramos cualquier otro caracter hacemos la insecion diracta
                // en la posicion en que el cursor nos tiene posicionados
                resultado.insert(cursor, c);
            }
        }

        // Imprimimos el resultado final haciendo un cout de cada caracter en la lista ya
        // en el orden que debe imprimirse
        for (char c : resultado) {
            cout << c;
        }
        // terminamos con el salto de linea par terminar la linea
        cout << endl;
    }

    return 0;
}


// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
* por cada linea el ciclo for se ejecuta solo una vez
* por cada caracter en la linea por lo que es tiempo lineal
* todas las demas operaciones son de tiempo constante, por 
* lo tanto, si consideramos n los caracteres de todas las lineas:
* O(n)
*
* espacio:
* la estructura principal en la que se almacenan todos los n 
* caracteres por lo que la complejidad espacial es:
* O(n)
*
*/
