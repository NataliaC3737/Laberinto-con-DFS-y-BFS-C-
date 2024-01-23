#include <iostream> // E/S estándar
#include <vector> // Vectores
#include <queue> // Cola (usada en BFS)
#include <stack> // Fila (usada en DFS)
#include <string> // Cadena de texto (interfaz)
#include "busqueda.h" //Encabezado

// Función para resolver el laberinto usando BFS
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
        cola.pop(); // Borrar el elemento del frente
        nodosRecorridos++; // Incrementar contador de nodos recorridos

        std::cout << nodoActual << " "; // Mostrar el nodo actual (se suma 1 para ajustar el índice)

        if (nodoActual == 5) { // Si se encuentra el nodo 5, detener la búsqueda
            std::cout << " " << std::endl;
            std::cout << "Nodos recorridos: " << nodosRecorridos << std::endl;
            return;
        }

        // Recorrer los nodos adyacentes al nodo actual
        for (int i = 0; i < laberinto[nodoActual].size(); ++i) {
            if (laberinto[nodoActual][i] != 0 && !visitado[i]) { // Si hay conexión y el nodo no ha sido visitado
                cola.push(i); // Agregar el nodo adyacente a la cola
                visitado[i] = true; // Marcar el nodo adyacente como visitado
            }
        }
    }
}

// Función para resolver el laberinto usando DFS (con pila)
bool dfsRecursivo(std::vector<std::vector<int>>& laberinto, int inicio, int& nodosRecorridos) {
    std::vector<bool> visitado(laberinto.size(), false); // Vector para marcar nodos visitados
    std::stack<int> pila; 
    pila.push(inicio); // Iniciar la pila con el nodo de inicio

    while (!pila.empty()) {
        int nodoActual = pila.top(); // Obtiene el elemento superior (último elemento agregado) de la pila
        pila.pop(); // Se elimina el elemento superior de la pila

        if (!visitado[nodoActual]) {
            visitado[nodoActual] = true; // Marcar el nodo actual como visitado
            std::cout << nodoActual << " "; // Mostrar el nodo actual
            nodosRecorridos++; // Incrementar contador de nodos recorridos

            if (nodoActual == 5) { // Si se encuentra el nodo final, detener la búsqueda
                return true;
            }

            // Empujar a la pila los nodos adyacentes no visitados
            for (int i = laberinto[nodoActual].size() - 1; i >= 0; --i) {
                if (laberinto[nodoActual][i] != 0 && !visitado[i]) {
                    pila.push(i);
                }
            }
        }
    }

    return false; // No se encontró el nodo final
}

// Función wrapper para llamar al DFS con pila
void resolverLaberintoDFS(std::vector<std::vector<int>>& laberinto) {
    int inicio = 0; // Nodo de inicio es el nodo 0
    int nodosRecorridos = 0; // Contador de nodos recorridos

    std::cout << "Recorrido del laberinto usando DFS con pila: ";
    if (!dfsRecursivo(laberinto, inicio, nodosRecorridos)) {
        std::cout << "No se encontró el nodo 5." << std::endl;
    }
    else {
        std::cout << " " << std::endl;
        std::cout << "Nodos recorridos: " << nodosRecorridos << std::endl;
    }
}