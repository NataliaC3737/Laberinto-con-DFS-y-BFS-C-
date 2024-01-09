#include <iostream> // E/S estándar
#include <vector> // Vectores
#include <queue> // Cola (usada en BFS)
#include <stack> // Fila (usada en DFS)
#include <string> // Cadena de texto (interfaz)
#include "laberinto.h" // Encabezado

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
    laberinto[5][4] = 1; // Conexión inversa de nodo 6 a nodo 5
    laberinto[4][6] = 1; // Conexión de nodo 5 a nodo 7
    laberinto[6][4] = 1; // Conexión inversa de nodo 7 a nodo 5
}

void mostrarLaberinto(std::vector<std::vector<std::string>>& matriz) {
    const int filas = 20;
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
        { "          0"," "," "," "," "," "," "," ","0","0","0","0","0","0","0","0","0"," "," "," ","0" },
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
        cola.pop();
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

// Función para resolver el laberinto usando DFS (recursivo)
bool dfsRecursivo(std::vector<std::vector<int>>& laberinto, std::vector<bool>& visitado, int nodoActual, int& nodosRecorridos) {
    visitado[nodoActual] = true; // Marcar el nodo actual como visitado
    std::cout << nodoActual << " "; // Mostrar el nodo actual
    nodosRecorridos++; // Incrementar contador de nodos recorridos

    if (nodoActual == 5) { // Si se encuentra el nodo 5, detener la búsqueda
        return true;
    }

    // Recorrer los nodos adyacentes al nodo actual
    for (int i = 0; i < laberinto[nodoActual].size(); ++i) {
        if (laberinto[nodoActual][i] != 0 && !visitado[i]) { // Si hay conexión y el nodo no ha sido visitado
            if (dfsRecursivo(laberinto, visitado, i, nodosRecorridos)) { // Llamada recursiva para el nodo adyacente
                return true; // Si se encontró el nodo 5, terminar la recursión
            }
        }
    }

    return false;
}

// Función wrapper para llamar al DFS recursivo
void resolverLaberintoDFS(std::vector<std::vector<int>>& laberinto) {
    std::vector<bool> visitado(laberinto.size(), false); // Vector para marcar nodos visitados
    int inicio = 0; // Nodo de inicio es el nodo 0
    int nodosRecorridos = 0; // Contador de nodos recorridos

    std::cout << "Recorrido del laberinto usando DFS: ";
    if (!dfsRecursivo(laberinto, visitado, inicio, nodosRecorridos)) {
        std::cout << "No se encontró el nodo 5." << std::endl;
    }
    else {
        std::cout << " " << std::endl;
        std::cout << "Nodos recorridos: " << nodosRecorridos << std::endl;
    }
}
