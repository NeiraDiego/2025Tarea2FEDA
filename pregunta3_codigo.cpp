// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: codigo de chat-GPT con instrucciones, correcciones y aclaraciones 
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

using namespace std;
// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* Se realizan (por linea) una serie de Querys  que se repiten cada intervalo Period
* dado un numero de registros K que serán aceptados se debe entregar cuales son los Querys (ID)
* que si logran entrar
* 
*
* Entrada:
* por linea se aceptan Registro ID y tiempo de ejecucion
* en la penúlitma linea ingresa el signo # para indicar el fin de registros
* finalmente el numero de registros K a aceptar
*
* Salida:
* Listado en orden de los ID de los Querys aceptadas
*
* Estructuras:
* 
* Funciones:
*
* Se puede recorrer el tiempo (hasta 3000) para hasta que se acepten los K Querys 
* Las Querys se pueden almacenar en un struct que contenga:
* - el ID, el tiempo individual de ejecucion, el tiempo de la próxima ejecucion que
*   utilizaremos como parametro para la cola de prioridad
*/


// ############## CODIGO ##############
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// Estructura para almacenar una QUery
struct Consulta {
    int id;       // ID de la Query
    int tiempo;   // tiempo en que entrega el proximo resultado
    int periodo;  // Periodo fijo de entrega dado en el input

    // Definir la prioridad: primero por tiempo, luego por ID
    bool operator>(const Consulta& otra) const {
        return tiempo > otra.tiempo || (tiempo == otra.tiempo && id > otra.id);
    }
};

int main() {
    // creamos la cola de prioridad 
    // esta parte fue creada por ChatGPT
    priority_queue<Consulta, vector<Consulta>, greater<Consulta>> cola;
    string linea; //creamos el string que leerá las lineas del input

    // Creamos el ciclo while para leer cada linea y la vamos asignando
  // al objeto de tipo string linea para ir operando con ella
    while (getline(cin, linea)) {
        // primero verificamos si tenemos # para detener la ejecución
        if (linea == "#") break;

        istringstream ss(linea);
        string Register; // creamos el string donde almacenaremos el texto
                        // Register para poder ignorarlo
        int id, periodo; // creamos los int que almacenaran temporalmente 
                          // los valores que entrega la linea para 
        ss >> Register >> id >> periodo; // leemos los valores de la linea

        // la primera Consulta se realiza exactamente en el periodo de la misma
        cola.push({periodo, id, periodo});
    }
    // leemos del input el valor K de consultas aceptadas
    int K;
    cin >> K;

    // hacemos un ciclo for por la cola de prioridad de los K 
  // elementos de mayor prioridad
    for (int i = 0; i < K; ++i) {
        // identificamos la consulta que está en el top para
        // poder imprimirla en el output en 3 lineas mas
        Consulta actual = cola.top();
        // borramos de la cola de prioridad esta consulta mas prioritaria
        cola.pop();
        // imprimimos al output el ID de la consulta que acabamos de popear
        cout << actual.id << endl;

        // Calcular el tiempo de la proxima ejecución de una consulta
        int proximoTiempo = actual.tiempo + actual.periodo;
        // actualizamos una nueva consulta en la cola pero con el tiempo actualizdo
        // para el proximo periodo de ejecucion de la consulta
        cola.push({proximoTiempo, actual.id, actual.periodo});
    }

    return 0;
}





// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
* Para el ciclo while de lectura tenemos que como máximo
* puede ser ciclos y luego ejecutar un push (log(n)) en esa cantidad
* de datos por lo que tendríamos O(registros*log(registros))
* Para el ciclo for tendríamos K ciclos y en cada uno tenemos una
* operacion push (log(n)) por lo que tendríamos O(K*log(registros))
*
* espacio:
* la estructura mas grande que tenemos es la cola de prioridad y 
* esta se puede completar hasta llegar a los K elementos solicitados
* por lo que la complegidad espacial es de O(K)
*
*
*/
