#ifndef LABERINTO_H
#define LABERINTO_H

#include <vector>

// Funci�n para definir la matriz de adyacencia que representa el laberinto a partir de un grafo
void definirLaberinto(int n, std::vector<std::vector<int>>& laberinto);

// Funci�n para mostrar el laberinto con nodos explorados
void mostrarLaberinto(std::vector<std::vector<int>>& laberinto);

// Funci�n para resolver el laberinto usando BFS
void resolverLaberintoBFS();

// Funci�n para resolver el laberinto usando DFS
void resolverLaberintoDFS();

#endif /* LABERINTO_H */

