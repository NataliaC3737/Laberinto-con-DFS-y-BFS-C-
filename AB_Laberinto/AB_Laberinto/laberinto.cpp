#include <iostream> // E/S estándar
#include <vector>   // Vectores
#include <queue>    // Cola (usada en BFS)
#include <climits>  // Valor máximo de entero (usado en BFS)
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

// Función para la búsqueda en amplitud (BFS)
void BFS(std::vector<std::vector<int>>& laberinto, int source) {
    // Vector para almacenar el estado de los nodos (NO_VISITADO = 0, VISITADO = 1)
    std::vector<int> estado(laberinto.size(), 0);

    // Vector para almacenar la distancia desde el nodo fuente a cada nodo del grafo
    std::vector<int> distancia(laberinto.size(), INT_MAX);

    // Vector para almacenar el padre de cada nodo
    std::vector<int> padre(laberinto.size(), -1);

    estado[source] = 1; // Marcar el nodo fuente como visitado
    distancia[source] = 0; // Distancia desde el nodo fuente hasta él mismo es 0
    padre[source] = -1; // El nodo fuente no tiene un padre

    std::queue<int> Q; // Crear una cola para el recorrido BFS
    Q.push(source); // Insertar el nodo fuente en la cola

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v = 0; v < laberinto.size(); v++) {
            // Si hay una conexión entre u y v, y v no ha sido visitado
            if (laberinto[u][v] == 1 && estado[v] == 0) {
                estado[v] = 1; // Marcar el nodo v como visitado
                distancia[v] = distancia[u] + 1; // Actualizar la distancia a v desde el nodo fuente
                padre[v] = u; // Establecer el padre de v como u
                Q.push(v); // Agregar v a la cola para explorar sus nodos adyacentes
            }
        }
    }
}

// Función para la búsqueda en profundidad (DFS)
void DFS(std::vector<std::vector<int>>& laberinto, int u, std::vector<bool>& vst) {
    vst[u] = true; // Marcar el nodo actual como visitado

    // Recorrer todos los nodos adyacentes a u
    for (int v = 0; v < laberinto.size(); v++) {
        // Si hay una conexión entre u y v, y v no ha sido visitado
        if (laberinto[u][v] == 1 && !vst[v]) {
            DFS(laberinto, v, vst); // Llamada recursiva para explorar el nodo v
        }
    }
}

// Función para resolver el laberinto usando BFS
void resolverLaberintoBFS() {
    std::vector<std::vector<int>> laberinto;
    int n = 6; // Ajusta el tamaño de la matriz según sea necesario
    definirLaberinto(n, laberinto); // Crear la matriz de adyacencia del laberinto

    int inicio = 0; // Nodo de inicio
    BFS(laberinto, inicio); // Resolver el laberinto usando BFS

    std::cout << "Laberinto resuelto usando BFS:" << std::endl;
    mostrarLaberinto(laberinto); // Mostrar el laberinto resuelto por consola
}

// Función para resolver el laberinto usando DFS
void resolverLaberintoDFS() {
    std::vector<std::vector<int>> laberinto;
    int n = 6; // Ajusta el tamaño de la matriz según sea necesario
    definirLaberinto(n, laberinto); // Crear la matriz de adyacencia del laberinto

    std::vector<bool> visitado(laberinto.size(), false); // Vector de nodos visitados para DFS

    int inicio = 0; // Nodo de inicio
    DFS(laberinto, inicio, visitado); // Resolver el laberinto usando DFS

    std::cout << "Laberinto resuelto usando DFS:" << std::endl;
    mostrarLaberinto(laberinto); // Mostrar el laberinto resuelto por consola
}
