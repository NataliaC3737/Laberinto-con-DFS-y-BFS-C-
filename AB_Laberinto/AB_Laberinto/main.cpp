// main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

#include <iostream>
#include "laberinto.h" // Incluimos el archivo de funciones del laberinto

int main() {
    int opcion;
    std::cout << "Elige el modo de resolucion del laberinto:" << std::endl;
    std::cout << "1. BFS" << std::endl;
    std::cout << "2. DFS" << std::endl;
    std::cin >> opcion;

    if (opcion == 1) {
        std::cout << "Resolviendo el laberinto usando BFS..." << std::endl;
        resolverLaberintoBFS();
    }
    else if (opcion == 2) {
        std::cout << "Resolviendo el laberinto usando DFS..." << std::endl;
        resolverLaberintoDFS();
    }
    else {
        std::cout << "Opción no válida. Por favor, elige 1 o 2." << std::endl;
    }

    return 0;
}
