#include <iostream> // E/S est�ndar
#include <vector> // Vectores
#include <queue> // Cola (usada en BFS)
#include <stack> // Fila (usada en DFS)
#include <string> // Cadena de texto (interfaz)
#include "busqueda.h" //Encabezado

// Funci�n para resolver el laberinto usando BFS
void resolverLaberintoBFS(std::vector<std::vector<int>>& laberinto) {
    std::queue<int> cola;
    std::vector<bool> visitado(laberinto.size(), false); // Vector para marcar nodos visitados
    int inicio = 0; // Nodo de inicio es el nodo 1
    int nodosRecorridos = 0; // Contador de nodos recorridos

    cola.push(inicio); // Agregar el nodo de inicio a la cola
    visitado[inicio] = true; // Marcar el nodo de inicio como visitado

    std::cout << "Recorrido del laberinto usando BFS: ";

    while (!cola.empty()) {
        int nodoActual = cola.front(); // Obtener el nodo actual de la cola
        cola.pop();
        nodosRecorridos++; // Incrementar contador de nodos recorridos

        std::cout << nodoActual << " "; // Mostrar el nodo actual (se suma 1 para ajustar el �ndice)

        if (nodoActual == 5) { // Si se encuentra el nodo 5, detener la b�squeda
            std::cout << " " << std::endl;
            std::cout << "Nodos recorridos: " << nodosRecorridos << std::endl;
            return;
        }

        // Recorrer los nodos adyacentes al nodo actual
        for (int i = 0; i < laberinto[nodoActual].size(); ++i) {
            if (laberinto[nodoActual][i] != 0 && !visitado[i]) { // Si hay conexi�n y el nodo no ha sido visitado
                cola.push(i); // Agregar el nodo adyacente a la cola
                visitado[i] = true; // Marcar el nodo adyacente como visitado
            }
        }
    }
}

// Funci�n para resolver el laberinto usando DFS (recursivo)
bool dfsRecursivo(std::vector<std::vector<int>>& laberinto, std::vector<bool>& visitado, int nodoActual, int& nodosRecorridos) {
    visitado[nodoActual] = true; // Marcar el nodo actual como visitado
    std::cout << nodoActual << " "; // Mostrar el nodo actual
    nodosRecorridos++; // Incrementar contador de nodos recorridos

    if (nodoActual == 5) { // Si se encuentra el nodo 5, detener la b�squeda
        return true;
    }

    // Recorrer los nodos adyacentes al nodo actual
    for (int i = 0; i < laberinto[nodoActual].size(); ++i) {
        if (laberinto[nodoActual][i] != 0 && !visitado[i]) { // Si hay conexi�n y el nodo no ha sido visitado
            if (dfsRecursivo(laberinto, visitado, i, nodosRecorridos)) { // Llamada recursiva para el nodo adyacente
                return true; // Si se encontr� el nodo 5, terminar la recursi�n
            }
        }
    }

    return false;
}

// Funci�n wrapper para llamar al DFS recursivo
void resolverLaberintoDFS(std::vector<std::vector<int>>& laberinto) {
    std::vector<bool> visitado(laberinto.size(), false); // Vector para marcar nodos visitados
    int inicio = 0; // Nodo de inicio es el nodo 0
    int nodosRecorridos = 0; // Contador de nodos recorridos

    std::cout << "Recorrido del laberinto usando DFS: ";
    if (!dfsRecursivo(laberinto, visitado, inicio, nodosRecorridos)) {
        std::cout << "No se encontr� el nodo 5." << std::endl;
    }
    else {
        std::cout << " " << std::endl;
        std::cout << "Nodos recorridos: " << nodosRecorridos << std::endl;
    }
}
