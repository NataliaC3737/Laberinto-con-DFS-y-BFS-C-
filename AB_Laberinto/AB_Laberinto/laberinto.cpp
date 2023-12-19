#include <iostream> // E/S est�ndar
#include <vector> // Vectores
#include <queue> // Cola (usada en BFS)
#include <stack> // Fila (usada en DFS)
#include "laberinto.h" // Encabezado

void definirLaberinto(int n, std::vector<std::vector<int>>& laberinto) {
    // Crear una matriz de n x n inicializada con ceros
    laberinto = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));

    // Establecer las conexiones entre los nodos en la matriz de adyacencia
    laberinto[1][2] = 1; // Conexi�n de nodo 2 a nodo 3
    laberinto[1][8] = 1; // Conexi�n de nodo 2 a nodo 9
    laberinto[2][1] = 1; // Conexi�n inversa de nodo 3 a nodo 2
    laberinto[2][3] = 1; // Conexi�n de nodo 3 a nodo 4
    laberinto[2][9] = 1; // Conexi�n de nodo 3 a nodo 10
    laberinto[3][2] = 1; // Conexi�n inversa de nodo 4 a nodo 3
    laberinto[3][4] = 1; // Conexi�n de nodo 4 a nodo 5
    laberinto[3][7] = 1; // Conexi�n de nodo 4 a nodo 8
    laberinto[4][3] = 1; // Conexi�n inversa de nodo 5 a nodo 4
    laberinto[4][6] = 1; // Conexi�n de nodo 5 a nodo 7
    laberinto[6][4] = 1; // Conexi�n inversa de nodo 7 a nodo 5

    // Marcar el nodo de inicio (Nodo 1) - Valor 2
    laberinto[0][1] = 2; // Conexi�n de nodo 1 a nodo 2
    laberinto[1][0] = 2; // Conexi�n inversa de nodo 2 a nodo 1

    // Marcar el nodo final (Nodo 6) - Valor 3
    laberinto[4][5] = 3; // Conexi�n de nodo 5 a nodo 6 
    laberinto[5][4] = 3; // Conexi�n inversa de nodo 6 a nodo 5
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

// Funci�n para resolver el laberinto usando BFS
void resolverLaberintoBFS(std::vector<std::vector<int>>& laberinto) {
    std::queue<int> cola;
    std::vector<bool> visitado(laberinto.size(), false); // Vector para marcar nodos visitados
    int inicio = 0; // Nodo de inicio es el nodo 1

    cola.push(inicio); // Agregar el nodo de inicio a la cola
    visitado[inicio] = true; // Marcar el nodo de inicio como visitado

    std::cout << "Recorrido del laberinto usando BFS:" << std::endl;

    while (!cola.empty()) {
        int nodoActual = cola.front(); // Obtener el nodo actual de la cola
        cola.pop();

        std::cout << nodoActual + 1 << " "; // Mostrar el nodo actual (se suma 1 para ajustar el �ndice)

        // Recorrer los nodos adyacentes al nodo actual
        for (int i = 0; i < laberinto[nodoActual].size(); ++i) {
            if (laberinto[nodoActual][i] != 0 && !visitado[i]) { // Si hay conexi�n y el nodo no ha sido visitado
                cola.push(i); // Agregar el nodo adyacente a la cola
                visitado[i] = true; // Marcar el nodo adyacente como visitado
            }
        }
    }
    std::cout << std::endl;
}

// Funci�n para resolver el laberinto usando DFS (recursivo)
void dfsRecursivo(std::vector<std::vector<int>>& laberinto, std::vector<bool>& visitado, int nodoActual) {
    visitado[nodoActual] = true; // Marcar el nodo actual como visitado
    std::cout << nodoActual + 1 << " "; // Mostrar el nodo actual (se suma 1 para ajustar el �ndice)

    // Recorrer los nodos adyacentes al nodo actual
    for (int i = 0; i < laberinto[nodoActual].size(); ++i) {
        if (laberinto[nodoActual][i] != 0 && !visitado[i]) { // Si hay conexi�n y el nodo no ha sido visitado
            dfsRecursivo(laberinto, visitado, i); // Llamada recursiva para el nodo adyacente
        }
    }
}

// Funci�n wrapper para llamar al DFS recursivo
void resolverLaberintoDFS(std::vector<std::vector<int>>& laberinto) {
    std::vector<bool> visitado(laberinto.size(), false); // Vector para marcar nodos visitados
    int inicio = 0; // Nodo de inicio es el nodo 1

    std::cout << "Recorrido del laberinto usando DFS:" << std::endl;
    dfsRecursivo(laberinto, visitado, inicio);
    std::cout << std::endl;
}
