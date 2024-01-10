#ifndef LABERINTO_H
#define LABERINTO_H

#include <vector>

// Función para definir la matriz de adyacencia que representa el laberinto a partir de un grafo
void definirLaberinto1(int n, std::vector<std::vector<int>>& laberinto);
void definirLaberinto2(int n, std::vector<std::vector<int>>& laberinto);

// Función para mostrar el laberinto con nodos explorados
void mostrarLaberinto1(std::vector<std::vector<std::string>>& matriz);
void mostrarLaberinto2(std::vector<std::vector<std::string>>& matriz);

#endif /* LABERINTO_H */

