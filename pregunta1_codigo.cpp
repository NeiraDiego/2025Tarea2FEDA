// ##############  DATOS PREGUNTA  ##############
/*
 * Nombre completo: Diego Ignacio Neira Salgado
 * id usuario: 1702322
 * Autoría: ideación propia con asistencia de chat-GPT para escritura del código
 * fuentes: https://chatgpt.com/
 * Análisis asintótico:
 * Forma en que se comento: 
 *  - primer bloque luego de las librerias: comprensión del problema.
 *  - primer línea de comentario: pseudo-codigo
 *  - lineas adicionales: correcciones de chat-GPT o de fuentes externas
 *  - bloque comentado después del código: análisis asintótico
*/
#include <iostream>
#include <sstream>      // stringstream: separar las lineas
#include <string>       // typos string
#include <map>
#include <vector>
#include <algorithm>    // sort()

using namespace std;

// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* Se trata de realizar un ranking de estudiantes (ID:E) donde 
* se nos entrega una serie de intentos de resolver problemas
* y se deben ordenar, primero por numero de problemas resueltos,
* si dos coinciden luego por menor tiempo de penalizacion y 
* finalmente por el numero de ID en caso de que empaten
*
* Entrada:
* es un archivo con el numero de casos en la primera linea, 
* luego una linea en blanco para separar los intentos 
* luego cada intento realizada, indicando el id del 
* concursante, el numero del problema, el tiempo y finalmente
* un caracter que indica el estado de la respuesta
* Correct, (clarification) Request, Unjudged, Erroneous
* Un caso te prueba se separa por dos espacios consecutivos
*
* Salida:
* una lista de los concursantes ordenados con si ID el numero
* de respuestas correctas y el tiempo de penalizacion
*
* Aproximación:
* Voy a crear una estructura para cada concursante
* (originalmente era un vector pero lo cambie por convenienvia)
* luego en la informacion de cada estudiante le voy a incorporar
* los datos de los intentos por cada linea, sumando el puntaje y 
* el tiempo de penalizacion dentro del struct, finalmente juntaremos
* todos los concursantes en un vector de concursantes y lo imprimimos
* en el orden dado con la funcion de ordenar segun el criterio antes
* descrito
*
*/


// ############## CODIGO ##############

// Struct que representa a un concursante
struct Concursante {
    int id = 0;
    int resueltos = 0;
    int penalizacion = 0;
    bool hizo_envio = false;         // Marca si ha enviado alguna solución
    int intentos_incorrectos[10] = {0};   // Intentos incorrectos por problema
    bool problema_resuelto[10] = {false}; // Llevamos "inventario" de los problemas 
                                          // ya resueltos para no contar 2 veces
};

// compara los concusantes, struct segun plantea la pregunta, primero por 
// cuantos ejercicios resolvió (si se consigue no sigue comparando)
// luego por tiempo de penalizacion si es que los ejercicios resuelots
// son iguales y si ambos son iguales finalmente por el nimero id
bool comparar(const Concursante& a, const Concursante& b) {
    if (a.resueltos != b.resueltos){ 
      return a.resueltos > b.resueltos;
    }
    if (a.penalizacion != b.penalizacion){
      return a.penalizacion < b.penalizacion;
    }
    return a.id < b.id;
}

int main() {
    int casos;
    string linea; // es una variable que siempre será la linea que estamos leyendo
  // es definida como string por lo que hay que convertirla cada vez para usarla

    // Lee la primera linea del archivo para establecer el numero de casos
    getline(cin, linea);
    casos = stoi(linea); // convierte la linea en entero para poder asignarlo a la variable
    getline(cin, linea); // ignora la (1) linea en blanco antes del primer caso

    while (casos--) { // lee cada caso y disminuye con cada iteración 
        map<int, Concursante> concursantes;  // crea el diccionario de concursantes

        // Leer líneas hasta encontrar una línea en blanco (fin del caso)
        while (getline(cin, linea)) {
            if (linea.empty()) break;
            // creamos las variables para almacenar hasta ingresarlos en cada
            // uno de los concursantes
            stringstream ss(linea);
            int numero, problema, tiempo;
            char resultado;

            // Leer datos de la línea: concursante, problema, tiempo y letra
            ss >> numero >> problema >> tiempo >> resultado;

            Concursante& c = concursantes[numero]; //definimos c como el 
            //puntero al concursante en el que vamos a trabajar indicado por el ID
            c.id = numero;
            c.hizo_envio = true;

            //comenzamos con la lectura por linea del resultado y la asignación 
            //de los valores en cada concursante
            // Si la solución fue correcta
            if (resultado == 'C') {
                // Si aún no se había resuelto este problema
                if (!c.problema_resuelto[problema]) {
                    c.problema_resuelto[problema] = true; //definimos el problema como resuelto
                                                          //en la matriz de problemas resueltos 
                    c.resueltos++;  // aumentamos la cantidad de resueltos totales
          // Esta parte fue la que mas problemas me causó para determinar como se calculaba
          // además se también me costó entender que no se suma si nunca se hace correcto
                    c.penalizacion += tiempo + 20 * c.intentos_incorrectos[problema];
                }
            }
            // Si fue incorrecta, se cuenta el intento si no se ha resuelto aún
            else if (resultado == 'I') {
                if (!c.problema_resuelto[problema]) {
                    c.intentos_incorrectos[problema]++;
                }
            }
            // todos los otros casos: R, U y E no afectan en nada, se ignoran
        }

        // Crear un vector con los concursantes que han enviado algo
        // (esta parte fue creada por GPT)
        vector<Concursante> resultado;
        for (auto& [id, c] : concursantes) {
            if (c.hizo_envio) resultado.push_back(c);
        }

        // Ordenar usando la función comparadora qu ecreamos en la primear parate
        sort(resultado.begin(), resultado.end(), comparar);

        // Imprimimos cada concursante de acuerdo al output deseado
        for (auto& c : resultado) {
            cout << c.id << " " << c.resueltos << " " << c.penalizacion << endl;
        }

        // Creamos la parte final del output para indicar al juez que terminamos
        if (casos) cout << endl;
    }

    return 0;
}






// ############## ANÁLISIS ASINTÓTICO ##############
/*
* tiempo:
* - En la parte de la lectura de los datos realiza lecturas (O(1))
*   por cada linea y itera sobre cada una de ellas O(lineas)
*   en cada linea debe hacer lectura e incersión en un map por lo 
*   que la parte mas pesada seria por cada linea O(log(concursantes)
*   por lo que en lectura es O(lineas*log(concursantes))
* - en la parte del ordenamiento realiza la funcion comparador 
*   que tiene tiempo constante (O(1)) pero debe realizar ordenamiento
*   en un map por lo que por cada concursante debe realizarce O(Concursante)
*   dando un ordenamiento de O(Concursante*log(concursantes))
* - la impresion es lineal en concursantes O(concursantes)
* Entonces tenemos O(lineas + lineas*log(concursantes) + Concursante*log(concursantes) + concursantes)
* como las lineas son necesariamente mas que los concursantes ya que un 
* concursante puede presentar muchos intentos (lineas) entonces el término
* mas relevante es:
* O(lineas*log(concursantes))
*
* espacio:
* en el caso del espacio la parte mas relevante es el diccionario de los
* concursantes que es lineal. Las lineas no se almacenan sino que se 
* incorporan dentro del struct que está dentro de cada elemento del diccionario
* por lo que para el caso del espacio es:
* O(concursantes)
*
*/
