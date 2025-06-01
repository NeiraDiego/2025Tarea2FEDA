#include <iostream>

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
*/


