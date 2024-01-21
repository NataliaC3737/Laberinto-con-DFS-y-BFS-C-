#include <iostream> // E/S estándar
#include <vector> // Vectores
#include <string> // Cadena de texto (interfaz)
#include "laberinto.h" // Encabezado

void definirLaberinto1(int n, std::vector<std::vector<int>>& laberinto) {
    // Crear una matriz de n x n inicializada con ceros
    laberinto = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    // Establecer las conexiones entre los nodos en la matriz de adyacencia
    laberinto[0][1] = 1; // Conexión de nodo 1 a nodo 2
    laberinto[1][0] = 1; // Conexión inversa de nodo 2 a nodo 1
    laberinto[1][2] = 1; // Conexión de nodo 2 a nodo 3
    laberinto[1][8] = 1; // Conexión de nodo 2 a nodo 9
    laberinto[2][1] = 1; // Conexión inversa de nodo 3 a nodo 2
    laberinto[2][3] = 1; // Conexión de nodo 3 a nodo 4
    laberinto[2][9] = 1; // Conexión de nodo 3 a nodo 10
    laberinto[3][2] = 1; // Conexión inversa de nodo 4 a nodo 3
    laberinto[3][4] = 1; // Conexión de nodo 4 a nodo 5
    laberinto[3][7] = 1; // Conexión de nodo 4 a nodo 8
    laberinto[4][3] = 1; // Conexión inversa de nodo 5 a nodo 4
    laberinto[4][5] = 1; // Conexión de nodo 5 a nodo 6 
    laberinto[5][4] = 1; // Conexión inversa de nodo 6 a nodo 5
    laberinto[4][6] = 1; // Conexión de nodo 5 a nodo 7
    laberinto[6][4] = 1; // Conexión inversa de nodo 7 a nodo 5
}
void definirLaberinto2(int n, std::vector<std::vector<int>>& laberinto) {
    // Crear una matriz de n x n inicializada con ceros
    laberinto = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    // Establecer las conexiones entre los nodos en la matriz de adyacencia
    laberinto[0][1] = 1;  // Nodo 0 se conecta con Nodo 1
    laberinto[0][2] = 1;  // Nodo 0 se conecta con Nodo 2
    laberinto[0][3] = 1;  // Nodo 0 se conecta con Nodo 3
    laberinto[1][0] = 1;  // Conexión inversa de Nodo 1 a Nodo 0
    laberinto[2][0] = 1;  // Conexión inversa de Nodo 2 a Nodo 0
    laberinto[3][0] = 1;  // Conexión inversa de Nodo 3 a Nodo 0

    laberinto[1][4] = 1;  // Nodo 1 se conecta con Nodo 4
    laberinto[4][1] = 1;  // Conexión inversa de Nodo 4 a Nodo 1

    laberinto[2][5] = 1;  // Nodo 2 se conecta con Nodo 5
    laberinto[5][2] = 1;  // Conexión inversa de Nodo 5 a Nodo 2

    laberinto[4][6] = 1;  // Nodo 4 se conecta con Nodo 6
    laberinto[4][7] = 1;  // Nodo 4 se conecta con Nodo 7
    laberinto[6][4] = 1;  // Conexión inversa de Nodo 6 a Nodo 4
    laberinto[7][4] = 1;  // Conexión inversa de Nodo 7 a Nodo 4

    laberinto[7][8] = 1;  // Nodo 7 se conecta con Nodo 8
    laberinto[7][9] = 1;  // Nodo 7 se conecta con Nodo 9
    laberinto[8][7] = 1;  // Conexión inversa de Nodo 8 a Nodo 7
    laberinto[9][7] = 1;  // Conexión inversa de Nodo 9 a Nodo 7
}


void mostrarLaberinto1(std::vector<std::vector<std::string>>& matriz) {
    const int filas = 21;
    const int columnas = 21;

    // Crear una matriz de objetos Valor de 21x21
    std::vector<std::vector<std::string>> interfaz(filas, std::vector<std::string>(columnas, ""));

    // Asignar los valores especificados a la matriz
    interfaz = {
        { "          0","0","0","0","0"," ","I"," ","0","0","0","0","0","0","0","0","0","0","0","0","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," ","0"," "," "," ","0" },
        { "          0"," ","9"," ","0"," "," "," "," "," "," "," "," "," "," "," ","0"," ","7"," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," ","0","0","0","0","0","0","0","0","0"," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," "," "," "," "," "," "," "," "," ","0"," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," ","1"," "," "," "," "," "," "," ","0"," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," "," "," "," "," "," "," "," "," ","0"," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," ","0","0","0","0","0"," "," "," ","0"," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," "," "," "," "," ","0"," "," "," "," "," "," "," ","0"," "," "," ","0" },
        { "          0"," ","2"," ","3"," "," "," ","0"," "," "," "," "," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," "," "," "," "," ","0"," "," "," "," "," "," "," ","0"," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," ","0","0","0","0","0","0","0","0","0"," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," ","4"," ","0","0","0","0","0","0","0","0","0","0","0","0","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," ","8"," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," ","6"," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0","0","0","0","0"," ","F"," ","0","0","0","0","0","0","0","0","0","0","0","0","0" }
    };

    // Imprimir la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << interfaz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void mostrarLaberinto2(std::vector<std::vector<std::string>>& matriz) {
    const int filas = 21;
    const int columnas = 21;

    // Crear una matriz de objetos Valor de 21x21
    std::vector<std::vector<std::string>> interfaz(filas, std::vector<std::string>(columnas, ""));

    // Asignar los valores especificados a la matriz
    interfaz = {
        { "          0","0","0","0","0","0","0","0","0"," ","I"," ","0","0","0","0","0","0","0","0","0" },
        { "          0"," "," "," "," "," "," "," ","0"," "," "," ","0"," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," "," "," "," "," ","0"," "," "," ","0"," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," "," "," "," "," ","0"," "," "," ","0"," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," ","0"," "," "," ","0","0","0","0","0"," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," ","1"," "," "," ","3"," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0","0","0","0","0"," ","2"," ","0","0","0","0","0","0","0","0","0" },
        { "          0"," "," "," "," "," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," " },
        { "          0"," ","4"," "," "," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," ","F" },
        { "          0"," "," "," "," "," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," " },
        { "          0"," "," "," ","0"," ","7"," ","0","0","0","0","0","0","0","0","0","0","0","0","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," ","0","0","0","0","0","0","0","0","0"," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," ","6"," ","0"," ","8"," ","0"," ","9"," "," "," "," "," "," "," "," "," ","0" },
        { "          0"," "," "," ","0"," "," "," ","0"," "," "," "," "," "," "," "," "," "," "," ","0" },
        { "          0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0" }
    };

    // Imprimir la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << interfaz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}