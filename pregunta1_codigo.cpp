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
#include <vector>
#include <algorithm> // para binary_search

using namespace std;
// ############## ANÁLISIS DEL PROBLEMA ##############
/*
* Descripción del problema:
* Se trata de minimizar el tiempo total de utilizacion de un ascensor:
* - total de pisos 31 (-1 que es el piso base)
* - el tiempo que toma el ascensor en subir un piso es 4 segundos
* - si el ascensor se detiene esto toma 10 segundos adicionales
* - subir a pie toma 20 segundos
*
* Entrada:
* - por linea se entrega un caso, primer dato el numero de entradas en el caso,
*   seguido por el valor del piso en el que se requiere detener 
* - el numero de casos 0 indica que se acabaron las entradas
*
* Salida:
* - una linea por tipo que 
*
* Idea:
* Crear una lista (vector) de los pisos requeridos, luego analizar el costo
* de las diferentes combinaciones en las que se salta alguno de los pisos 
* intermedios, almacenar en una variable la convinacion ganadora hasta el 
* momento y el costo (segundos que se demora), solo se reemplaza si es que
* el nuevo análisis es mejor
*
* Estructuras:
* 
* Funciones:
* - tiempo de cada comb inacion para comparar con el resultado anterior
*
*/


// ############## CODIGO ##############
  // definimos las constantes dadas en el enunciado
  // definido en main pero lo saque para usar en la funcion
  const int pisos = 31;
  const int t_subir = 4;
  const int t_detencion = 10;
  const int t_a_pie = 20;
 
int tiempo_iter(vector<int>& pisos_pedidos, vector<int>& pisos_iteracion){
  int tiempo_total;
  int ultimo_piso_visitado = 0;
  // se itera para que cada piso pedido sea cumplido
  for (size_t i = 0; i < pisos_pedidos.size(); i++) {
    // si el piso i en pisos_pedidos está en pisos_iteracion entonces
    // se corresponde el mayor entre tiempo_total y el tiempo en 
    // llegar hasta ese piso si no está es el tiempo hasta el último
    // piso visitado y subir hasta el pedido
    if(binary_search(pisos_iteracion.begin(),pisos_iteracion.end(),pisos_pedidos[i]{
      tiempo_total = max(tiempo_total,pisos_pedidos[i]
    }
  }
  return tiempo_total;
  }
int main () {
 // ciclo de entrada de los argumentos (por linea)
  while (true){
    // toma el primer termino para determinar el ciclo de carga de datos
    int n;
    cin >> n;
    // salida en la ultima linea (con valor 0) del archivo
    if (n == 0){
      break;
    }
    // se crea la lista de pisos pedidos y se pobla con n datos
    vector<int> pisos_pedidos;
    for (int i = 0; i < n; ++i){
      int piso;
      cin >> piso;
      pisos_pedidos.push_back(piso);
    }
    // se crea el valor a devolver y se asigna un valor grande 
    // se puede usar 600 ya que es lo que indica el enunciado como máximo
    int resultado = 600;
    // se crea vector en que se agregarán los pisos en que se detendrá
    vector<int> pisos_efectivos;
    /* 
    // funcion para ver si se estan cargando los datos
    for (size_t i = 0; i<pisos_pedidos.size(); ++i) {
      cout << i << pisos_pedidos[i] << endl;
    }
    */
    // se crean ciclos for para probar cada combinacion y
    // se evalúa cada dato y se compara con resultado
    // GPT: consulto como crear las combinaciones sin hacer 30 ciclos for
    

  }
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
