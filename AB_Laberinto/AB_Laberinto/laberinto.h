#ifndef LABERINTO_H
#define LABERINTO_H

#include <vector>

// Función para definir la matriz de adyacencia que representa el laberinto a partir de un grafo
void definirLaberinto(int n, std::vector<std::vector<int>>& laberinto);

// Función para mostrar el laberinto con nodos explorados
void mostrarLaberinto(std::vector<std::vector<std::string>>& matriz);

#endif /* LABERINTO_H */

