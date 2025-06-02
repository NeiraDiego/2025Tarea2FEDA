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
#include <iostream>     // para entrada/salida estándar
#include <queue>        // para priority_queue
#include <vector>       // para vector
#include <algorithm>    // para sort

using namespace std;

// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* Los soldados lemming se enfrentan por pares completos en cada 
* campo de batalla y salen muertos o disminuidos
* en el poder de su contrincante, se busca establecer quien gana
*
* Entrada:
* Se entregan un numero guerras de campos de batalla, un numero
* de campos de batalla y dos tamaños de ejércitos para cada guerra
* y luego el poder de cada lemming soldado, se enfrentan por pares
* completos en cada campo de batalla y salen muertos o disminuidos
*
* Salida:
* "green and blue died" (si ambos ejercitos se eliminan)
* "blue wins" y una lista de los poderes de los supervivientes
* o "green wins" y la lista de poderes de los supervivientes
*
*
*/


// ############## CODIGO ##############

int main() {
    int T; // la cantidad de "gerras" que se van a pelear
    cin >> T; // se lee en la primera linea

  // primer ciclo while que lee cada linea para ir avanzando en la guerra 
    while (T--) {
      // se lee el encabezado donde se indican los siguietnes datos
        int B, SG, SB; // define campos de batalla, soldados verdes y azules
        cin >> B >> SG >> SB; // lee los datos de la primera linea

        priority_queue<int> verdes; // creamos una lista de prioridad maxima para lemmings verdes
        priority_queue<int> azules; // creamos una lista de prioridad maxima para lemmings azules

        // leemos los valores de los siguientes SG (numero de lemmings verdes) asingando
    // el poder de cada uno de ellos en la lista de prioridad de su ejercito
        for (int i = 0; i < SG; ++i) {
            int power; // creamos la v ariable donde indicaremos el valor hasta agregarlo
            cin >> power; // leemos el poder de la próxima linea
            verdes.push(power); // pusheamos el valor de poder como dato en el ejercito
        }

        // hacemos exactamente lo mismo que en el ciclo anterior pero par el ejercito azul
        for (int i = 0; i < SB; ++i) {
            int power;
            cin >> power;
            azules.push(power);
        }

        // este ciclo representa las batallas de la guerra, seguiremos peleando
    // mientras hayan soldados en ambos ejercitos, mas adelante veremos que pasa
    // cuando uno de los dos ejercitos se acabe
        while (!verdes.empty() && !azules.empty()) {
            // creamos un vector vacio para cada uno de los ejercitos con el 
      // objetivo de almacenar los sobrevivientes hasta que los podamos
      // volver a agregar a las colas de prioridad con su nuevo poder
            vector<int> sobrevivientes_verdes;
            vector<int> sobrevivientes_azules;

            // se definen las batallas hasta llenar los B camos de batalla
      // si ya no hay campos de batalla o si uno de los ejercitos se vacía 
      // se termina el ciclo
            for (int i = 0; i < B && !verdes.empty() && !azules.empty(); ++i) {
                int v = verdes.top(); // guardamos el valor de poder del soldado verde
                                      // antes de hacer el pop
                verdes.pop(); // eliminamos del ejercito el soldado que está en el campo 
                              // de batalla 
                // ahora lo mismo para los zules
                int a = azules.top(); 
                azules.pop();

                // ahora vemos quien gana y devolvemos al ganador al vector
                // que va en camino a volver a su ejercito pero
                // habiendole restado el poder de su contrincante 
                if (v > a) sobrevivientes_verdes.push_back(v - a);
                else if (a > v) sobrevivientes_azules.push_back(a - v);
                // si son iguales no haremos nada porque no vuelven a casa
            }

            // los soldados victoriosos vuelven a base (ejercito) desde el vector
            // de los soldados sobrevivientes
            for (int p : sobrevivientes_verdes) verdes.push(p);
            for (int p : sobrevivientes_azules) azules.push(p);
        }

        // resultado de la guerra, cuando uno o ambos de los ejercitos llegan a cero
        // el ciclo anterior termina y llegamos hasta aqui
        // si ambos ejercitos estan vacios, es un empate, ambos ejercitos murieron
        if (verdes.empty() && azules.empty()) {
            cout << "green and blue died\n";
        // si uno de los dos ejercitos siguen verificamos si son los azules:
        } else if (verdes.empty()) {
            cout << "blue wins\n";
            // ahora nos preparamos para imprimir los soldados gandores, creamos el vector
            // de estos
            vector<int> resultado;
            // vaciamos el ejercito copiando los poderes en el vector resultado 
            while (!azules.empty()) {
                resultado.push_back(azules.top());
                azules.pop();
            }
            // ordenamos el vector para imprimirlos por orden de poder
            sort(resultado.rbegin(), resultado.rend());
            // imprimimos cada uno de los poderes del vector ordenado
            for (int p : resultado){ 
              cout << p << endl;
            }
        // como comprobamos que ni ambos ni el ejercito verde esta vacio, entonces ellos ganaron
        // repetimos exactamente los mismos pasos anteriores pero ahora para el ejercito verde
        } else {
            cout << "green wins\n";
            vector<int> resultado;
            while (!verdes.empty()) {
                resultado.push_back(verdes.top());
                verdes.pop();
            }
            sort(resultado.rbegin(), resultado.rend());
            for (int p : resultado){
              cout << p << endl;
            }
        }

        if (T) cout << endl; // línea en blanco entre casos
    }

    return 0;
}





// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
* - lectura de datos dos ciclos for que suman el total de soldados o
*   sea O(soldados)
* - construccion de las listas (insert en lista de prioridad)
*   O(soldados*log(soldados))
* - cantidad de rondas, en el peor de los casos se podrían
*   eliminar solo un soldado por ronda en cada campo por lo tanto
*   es B veces log(soldado) por lo que tenemos
*   O(B*log(soldados))
* - el ordenamiento de los sobrevivientes es O(n*log(n))
*   por lo tanto el mas significativo es:
*   O(soldados*log(soldados))
*
* espacio:
*- La estructuras relevantes son:
* - colas de prioridad O(n)
* - vectores sobrevivientes O(n)
* - vector de salida (impresion) O(n)
* por lo que es O(n)
*/
