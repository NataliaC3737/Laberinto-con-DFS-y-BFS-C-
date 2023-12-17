#include <iostream>
#include <vector>
#include "laberinto.h"

void definirLaberinto(int n, std::vector<std::vector<int>>& laberinto) {
    // Implementar aquí la lógica para ingresar el grafo y crear la matriz de adyacencia
    // Por ejemplo, se puede solicitar al usuario que ingrese las conexiones entre nodos
    // y actualizar la matriz de adyacencia en consecuencia
    // Aquí se utiliza una matriz predefinida como ejemplo

    // Crear una matriz de n x n inicializada con ceros
    laberinto = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    // Lógica para ingresar el grafo y crear la matriz de adyacencia
    // (Implementarlo para utilizar un grafo predefinido)
    // Aquí se define un ejemplo de grafo para un laberinto simple
    laberinto[0][1] = 1;
    laberinto[1][0] = 1;
    laberinto[1][2] = 1;
    laberinto[2][1] = 1;
    laberinto[2][3] = 1;
    laberinto[3][2] = 1;
    // ... (agregar más conexiones según el laberinto diseñado)

    // Establecer nodos iniciales y finales (pueden ser definidos como se necesite)
    // Por ejemplo, supongamos que el nodo inicial es el 0 y el nodo final es el 3
}

void mostrarLaberinto(std::vector<std::vector<int>>& laberinto) {
    // Implementar la lógica para mostrar el laberinto y resaltar los nodos explorados
    // Utilizar algún símbolo especial para representar los nodos visitados o explorados

    // Mostrar la matriz de adyacencia
    for (int i = 0; i < laberinto.size(); i++) {
        for (int j = 0; j < laberinto[i].size(); j++) {
            std::cout << laberinto[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void resolverLaberintoBFS() {
    std::vector<std::vector<int>> laberinto;
    int n = 4; // Cantidad de nodos del laberinto (se puede ajustar según sea necesario)
    definirLaberinto(n, laberinto);

    // Implementar la lógica para resolver el laberinto usando BFS
    // ...

    std::cout << "Laberinto resuelto usando BFS:" << std::endl;
    mostrarLaberinto(laberinto);
}

void resolverLaberintoDFS() {
    std::vector<std::vector<int>> laberinto;
    int n = 4; // Cantidad de nodos del laberinto (se puede ajustar según sea necesario)
    definirLaberinto(n, laberinto);

    // Implementar la lógica para resolver el laberinto usando DFS
    // ...

    std::cout << "Laberinto resuelto usando DFS:" << std::endl;
    mostrarLaberinto(laberinto);
}