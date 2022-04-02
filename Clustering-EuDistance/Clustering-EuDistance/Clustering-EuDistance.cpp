// Clustering-EuDistance.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Func.h"
using namespace std;



int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 100);

    
    int DIMENSIONES_TEST[19] =
    {
        1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100
    };
    
    ofstream ARCHIVOS[19];


    int DATA_TT = 20000;
    int RES = {};
    int size = sizeof(DIMENSIONES_TEST) / sizeof(DIMENSIONES_TEST[0]);
    /*
    * xi = punto(A), punto prueba.
    * yi = punto(B), resto de puntos.
    */
    int* xi = new int[(DIMENSIONES_TEST[0])];
    int* yi = new int[(DIMENSIONES_TEST[0])];

    for (int i = 0; i < size; i++) {
        ARCHIVOS[i].open("DATA_DIM_"+ std::to_string(i) + ".txt");
        for (int j = 0; j < DIMENSIONES_TEST[i]; j++)
        {
            // Se toma un punto estatico.
            xi[j] = distrib(gen);
        }
        for (int n = 0; n < DATA_TT; n++)
        {
            for (int y = 0; y < DIMENSIONES_TEST[i]; y++)
            {
                yi[y] = distrib(gen);
            }
            RES = Dimension_n(xi, yi, DIMENSIONES_TEST[i]);
            ARCHIVOS[i] << RES << ' ';
        }
        if (i < size - 1)
        {
            int* new_xi = new int[(DIMENSIONES_TEST[i + 1])];
            int* new_yi = new int[(DIMENSIONES_TEST[i + 1])];
            delete []xi;
            delete []yi;
            xi = new_xi;
            yi = new_yi;
        }
        ARCHIVOS[i].close();
    }
    std::cout << 'B' << endl;


    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

