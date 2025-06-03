// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: codigo de chat-GPT con instrucciones, correcciones y comentarios mios.
 * fuentes: https://chatgpt.com/
 * Análisis asintótico:
 * Forma en que se comento: 
 *  - primer bloque luego de las librerias: comprensión del problema.
 *  - primer línea de comentario: pseudo-codigo
 *  - lineas adicionales: correcciones de chat-GPT o de fuentes externas
 *  - bloque comentado después del código: análisis asintótico
*/
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* Un ferry puede llevar hasta n autos y tarda t minutos en cruzar. 
* Los autos llegan en cualquier momento y a cualquier orillas. 
* El ferry parte desde la orilla izquierda y cruza solo si lleva 
* autos o si hay autos esperando en la orilla contraria. Se debe calcular a qué 
* minuto cada auto llega a la otra orilla.
*
* Entrada:
* en la primera linea se muestra el numero de casos.
* en la segunda se entregan tres enteros: la capacidad del ferry, 
* el tiempo de cruce y la cantidad de autos que se van a entregar (lineas).
* luego siguen líneas con la llegada de cada auto y a cual orilla llega (left o right).
*
* Salida:
* Para cada auto, se imprime la hora en que llega a la otra orilla, 
* en el mismo orden en que salieron en la entrada.
*
*/

// ############## CODIGO ##############

// creamos un struct para almacenar la informacion de cada uno de los autos
// necesitamos la hora de llegada para para establecer la prioridad y 
// tambien el indice para poder entregarlos en el mismo orden a la hora de 
// imprimir
struct Auto {
    int horaLlegada;
    int indice;
};

int main() {
    int casos; // creamos la variable para el numero de casos
    cin >> casos; // lo leemos y lo almacenamos en su variable

    // ejecutamos un while para tantos ciclos como casos tenemos
    while (casos--) { // disminuimos casos en cada ciclo para controlar la salida
        // creamos las variables para almacenar los datos de cada caso
        int capacidad; // capacidad del ferry en este caso
        int tiempoCruce; // tiempo que se demora en crusar el rio el ferry
        int cantidadAutos; // cantidad máxima de autos que puede llevar en cada viaje
        cin >> capacidad >> tiempoCruce >> cantidadAutos; // leemos y almacenamos

        queue<Auto> izquierda, derecha; // creamos cada fila (FIFO) para los autos en cada orilla 
        vector<int> resultado(cantidadAutos); // creamos el vector en el que pondremos el tiempo
                                              // total para cada auto

        // para cada auto tomamos el dato de llegada y a que orilla
        for (int i = 0; i < cantidadAutos; ++i) {
            int hora; // variable para meter la hora de llegada en el la fila
            string orilla; // creamos la variable para leer a que orilla llega
            cin >> hora >> orilla; // leemos las dos variables de la fila

            if (orilla == "left") { // si llega con el dato de orilla "left"
                izquierda.push({hora, i});// entonces lo metemos a la fila izquerda
            } else {// el único otro caso es que sea en la orilla derecha
                derecha.push({hora, i});// asi que lo incorporamos a esa fila
        // notar que incluimos el indice i como el id de cada auto para mostrar la salida
            }
        }

        int tiempoActual = 0; // creamos el reloj: la variable para llevar el control del tiemo
        bool enIzquierda = true;  // creamos otra variable para controlar donde está el ferry
                                  // que comienza en la izquerda, por eso true

        while (!izquierda.empty() || !derecha.empty()) {
           // definimos que la orilla actual es la izqueda si la variable enIzquerda
      // y la orilla actual es la dercha si es falas y vice versa
            queue<Auto>& orillaActual    = enIzquierda ? izquierda : derecha;
            queue<Auto>& orillaContraria = enIzquierda ? derecha   : izquierda;
            
            // creamos la variable para establecer el tiempo a la proxima llegada
            int proximaLlegada = INT32_MAX;// comenzamos con tiempo maximo para minimizar
            if (!izquierda.empty()) {// si hay elemeontos en el lado izquerdo
        // la proxima llegada será la min entre la proxima anterior que en esta
        // primera lextura sera el entero máximo y la hora de llegada del auto que 
        // esté en el primer lugar de la fila (FIFO), o sea el más antiguo
                proximaLlegada = min(proximaLlegada, izquierda.front().horaLlegada);
            }
        // lo mismo para la derecha, pero ahora se compara con el lado izquerdo por que
      // en el paso anterior se actualizó proximaLlegada          
            if (!derecha.empty()) {
                proximaLlegada = min(proximaLlegada, derecha.front().horaLlegada);
            }

            // Si no hay autos esperando en la orilla actual, avanzamos el reloj hasta la próxima llegada.
            if (orillaActual.empty() ||
                orillaActual.front().horaLlegada > tiempoActual) {
                tiempoActual = max(tiempoActual, proximaLlegada);
            }

            // Cargamos autos al ferry desde la orilla actual mientras haya autos y espacio.
            vector<Auto> ferry; // creamos el vector de los autos que están en el ferri
            while (!orillaActual.empty() &&// verificamos si es que ya está vacío el puerto
                   orillaActual.front().horaLlegada <= tiempoActual && // si el próximo auto ya llegó
                   ferry.size() < capacidad) {// y si todavía el vector de autos cargados entra en el ferry
                ferry.push_back(orillaActual.front());// entonces cargamos el primer auto que esté en la
                                                        // orilla actual

                orillaActual.pop(); // y lo popeamos porque ya no está esperando
            }

            // Si se cargó algún auto o hay autos esperando en la orilla contraria, cruzamos.
            if (!ferry.empty() || // el ferry no está vacío 
                (!orillaContraria.empty() && // hay autos en la orilla contraria
                 orillaContraria.front().horaLlegada <= tiempoActual)) {// y el proximo auto ya llegó
                // asi que cruzamos

                tiempoActual += tiempoCruce; // adelantamos el reloj para ver cuando llegó al otro lado

                // Registramos la hora de llegada de cada auto transportado.
                for (const Auto& autoFerry : ferry) {
                    resultado[autoFerry.indice] = tiempoActual;// leemos el reloj y aontamos la hora en cada
                                                                // auto que se está bajando del ferry

                }

                // Cambiamos la posición del ferry.
                enIzquierda = !enIzquierda;

            } else {
                // Si no hay necesidad de cruzar, esperamos a la próxima llegada.
                tiempoActual = proximaLlegada;
            }
        }
        // para cada elemento de resultado vamos  a imprimir la hora de salida
        for (int horaSalida : resultado) {
            cout << horaSalida << endl;
        }
        // con esta linea evitamos que en la ultima iteracion se imprima agregue la linea
    // cosa que el problema explicita 
        if (casos > 0) {
            cout << endl;
        }
    }

    return 0;
}



// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
* se utilizan dos colas pero cada auto m es insertada solo en 
* una de ellas, los diferentes ciclos iteran sobre este número
* si bien hay varios ciclos estos se van sumando de forma lineal
* la por lo que cada parte del codigo es lineal o sea:
* O(m)
*
*
* espacio:
* las colas de la izquerda, de la derecha, el vector de resultado
* son todos independientes y de tamaño m, el vector del ferry es de 
* tamaño aun mas pequeño n, por lo que la complejidad temporal del
* código es 
* O(m)
*
*/
