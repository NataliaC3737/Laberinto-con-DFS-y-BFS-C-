#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>

// Funci�n para resolver el laberinto usando BFS
void resolverLaberintoBFS(std::vector<std::vector<int>>& laberinto);

// Funci�n para resolver el laberinto usando DFS (recursivo)

bool dfsRecursivo(std::vector<std::vector<int>>& laberinto, int inicio, int& nodosRecorridos);

// Funci�n para resolver el laberinto usando DFS
void resolverLaberintoDFS(std::vector<std::vector<int>>& laberinto);

#endif /* BUSQUEDA_H */