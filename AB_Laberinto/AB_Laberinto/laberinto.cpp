#include <iostream>
#include <vector>
#include "laberinto.h"

void definirLaberinto(int n, std::vector<std::vector<int>>& laberinto) {
    // Implementar aqu� la l�gica para ingresar el grafo y crear la matriz de adyacencia
    // Por ejemplo, se puede solicitar al usuario que ingrese las conexiones entre nodos
    // y actualizar la matriz de adyacencia en consecuencia
    // Aqu� se utiliza una matriz predefinida como ejemplo

    // Crear una matriz de n x n inicializada con ceros
    laberinto = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    // L�gica para ingresar el grafo y crear la matriz de adyacencia
    // (Implementarlo para utilizar un grafo predefinido)
    // Aqu� se define un ejemplo de grafo para un laberinto simple
    laberinto[0][1] = 1;
    laberinto[1][0] = 1;
    laberinto[1][2] = 1;
    laberinto[2][1] = 1;
    laberinto[2][3] = 1;
    laberinto[3][2] = 1;
    // ... (agregar m�s conexiones seg�n el laberinto dise�ado)

    // Establecer nodos iniciales y finales (pueden ser definidos como se necesite)
    // Por ejemplo, supongamos que el nodo inicial es el 0 y el nodo final es el 3
}

void mostrarLaberinto(std::vector<std::vector<int>>& laberinto) {
    // Implementar la l�gica para mostrar el laberinto y resaltar los nodos explorados
    // Utilizar alg�n s�mbolo especial para representar los nodos visitados o explorados

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
    int n = 4; // Cantidad de nodos del laberinto (se puede ajustar seg�n sea necesario)
    definirLaberinto(n, laberinto);

    // Implementar la l�gica para resolver el laberinto usando BFS
    // ...

    std::cout << "Laberinto resuelto usando BFS:" << std::endl;
    mostrarLaberinto(laberinto);
}

void resolverLaberintoDFS() {
    std::vector<std::vector<int>> laberinto;
    int n = 4; // Cantidad de nodos del laberinto (se puede ajustar seg�n sea necesario)
    definirLaberinto(n, laberinto);

    // Implementar la l�gica para resolver el laberinto usando DFS
    // ...

    std::cout << "Laberinto resuelto usando DFS:" << std::endl;
    mostrarLaberinto(laberinto);
}