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

    std::vector<std::vector<int>> laberinto; // Matriz de adyacencia para representar el laberinto
    int n = 10; // Tamaño de la matriz (ajústalo según el tamaño de tu laberinto)
    definirLaberinto(n, laberinto); // Definir el laberinto según la estructura
    std::vector<std::vector<std::string>> interfaz;

    if (opcion == 1) {
        std::cout << "Resolviendo el laberinto usando BFS..." << std::endl;
        resolverLaberintoBFS(laberinto); // Resolver el laberinto usando BFS
        mostrarLaberinto(interfaz);
    }
    else if (opcion == 2) {
        std::cout << "Resolviendo el laberinto usando DFS..." << std::endl;
        resolverLaberintoDFS(laberinto); // Resolver el laberinto usando DFS
        mostrarLaberinto(interfaz);
    }
    else {
        std::cout << "Opción no válida. Por favor, elige 1 o 2." << std::endl;
    }

    return 0;
}

