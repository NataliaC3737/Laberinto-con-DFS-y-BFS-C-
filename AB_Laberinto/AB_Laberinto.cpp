// AB_Laberinto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

#include <iostream>
#include <vector>
using namespace std;

// Definición de una matriz global para representar la matriz de adyacencia
vector<vector<int>> matriz;

// Función para crear una matriz de adyacencia con n nodos
void crearMatriz(int n) {
    for (int i = 0; i < n; i++) {
        // Creamos un vector de tamaño n inicializado con ceros para representar una fila de la matriz
        vector<int> row(n, 0);
        // Agregamos la fila a la matriz
        matriz.push_back(row);
    }
}

// Función para añadir una conexión entre nodos a y b en la matriz
void anadirConexion(int a, int b) {
    // Marcamos la conexión entre nodo a y nodo b como 1 en ambas direcciones (grafo no dirigido)
    matriz[a][b] = 1;
    matriz[b][a] = 1;
}

// Función para imprimir la matriz de adyacencia
void imprimirMatriz() {
    // Iteramos sobre cada fila y columna de la matriz para imprimirla
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz.size(); j++) {
            cout << matriz[i][j] << " "; // Imprimimos el valor en la posición (i, j) de la matriz
        }
        cout << endl; // Imprimimos una nueva línea después de cada fila
    }
}

int main() {
    int n; // Cantidad de nodos del grafo
    cin >> n; // Se lee la cantidad de nodos desde la entrada estándar

    // Se llama a la función crearMatriz con n para inicializar la matriz de adyacencia
    crearMatriz(n);

    int q; // Cantidad de aristas
    cin >> q; // Se lee la cantidad de aristas desde la entrada estándar

    // Se ingresan las q aristas entre nodos a y b y se añaden a la matriz
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b; // Se lee una arista desde la entrada estándar
        anadirConexion(a, b); // Se añade la conexión entre los nodos a y b en la matriz
    }

    // Se imprime la matriz de adyacencia resultante
    cout << "Matriz de adyacencia:" << endl;
    imprimirMatriz(); // Llama a la función de imprimir para mostrar la matriz

    return 0;
}

