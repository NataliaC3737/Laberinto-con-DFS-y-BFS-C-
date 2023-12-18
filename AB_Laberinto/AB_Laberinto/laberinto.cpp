#include <iostream>
#include <vector>
#include "laberinto.h"

void definirLaberinto(int n, std::vector<std::vector<int>>& laberinto) {
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
    laberinto[4][6] = 1; // Conexión de nodo 5 a nodo 7
    laberinto[5][4] = 1; // Conexión inversa de nodo 6 a nodo 5
    laberinto[6][4] = 1; // Conexión inversa de nodo 7 a nodo 5

    // Marcar el nodo de inicio (Nodo 1)
    laberinto[0][1] = 2; // Usamos el valor 2 para representar el nodo de inicio
    laberinto[1][0] = 2; // Conexión inversa del nodo de inicio

    // Marcar el nodo final (Nodo 6)
    laberinto[4][5] = 3; // Usamos el valor 3 para representar el nodo final
    laberinto[5][4] = 3; // Conexión inversa del nodo final
}

void mostrarLaberinto(std::vector<std::vector<int>>& laberinto) {
    // Mostrar la matriz de adyacencia con nodos marcados
    for (int i = 0; i < laberinto.size(); i++) {
        for (int j = 0; j < laberinto[i].size(); j++) {
            if (laberinto[i][j] == 2) {
                std::cout << "I "; // Marcar nodo de inicio
            }
            else if (laberinto[i][j] == 3) {
                std::cout << "F "; // Marcar nodo final
            }
            else {
                std::cout << laberinto[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void resolverLaberintoBFS() {
    std::vector<std::vector<int>> laberinto;
    int n = 10; // Cantidad de nodos del laberinto (se puede ajustar según sea necesario)
    definirLaberinto(n, laberinto);

    // Implementar la lógica para resolver el laberinto usando BFS
    // ...

    std::cout << "Laberinto resuelto usando BFS:" << std::endl;
    mostrarLaberinto(laberinto);
}

void resolverLaberintoDFS() {
    std::vector<std::vector<int>> laberinto;
    int n = 10; // Cantidad de nodos del laberinto (se puede ajustar según sea necesario)
    definirLaberinto(n, laberinto);

    // Implementar la lógica para resolver el laberinto usando DFS
    // ...

    std::cout << "Laberinto resuelto usando DFS:" << std::endl;
    mostrarLaberinto(laberinto);
}