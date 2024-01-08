// main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

#include <iostream>
#include "laberinto.h" // Incluimos el archivo de funciones del laberinto

int main() {
    std::vector<std::vector<int>> laberinto; // Matriz de adyacencia para representar el laberinto
    int n = 10; // Tamaño de la matriz (ajústalo según el tamaño de tu laberinto)
    definirLaberinto(n, laberinto); // Definir el laberinto según la estructura
    std::vector<std::vector<std::string>> interfaz;

    std::cout << "Bienvenido/a al laberinto" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "------------------------Instrucciones------------------------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "A continuacion se muestra la resolucion por medio de los " << std::endl;
    std::cout << "algoritmos de busqueda en profundidad(DFS) y amplitud(BFS)." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "El nodo (0) representa el inicio, y el nodo (5) el final." << std::endl;
    std::cout << " " << std::endl;

    std::cout << "-------------------------Soluciones--------------------------" << std::endl;
    std::cout << " " << std::endl;
    resolverLaberintoBFS(laberinto); // Resolver el laberinto usando BFS
    std::cout << " " << std::endl;
    resolverLaberintoDFS(laberinto); // Resolver el laberinto usando DFS
    std::cout << " " << std::endl;

    std::cout << "--------------------------Laberinto--------------------------" << std::endl;
    std::cout << " " << std::endl;
    mostrarLaberinto(interfaz);
    
    return 0;
}

