#include "heuristica.h"
#include <iostream>

int main(int argc, char* argv[]) {
    int n, m, k, u, v, w;
    std::cin >> n >> m >> k;
    Grafo g(n,std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v >> w;
        g[u - 1][v - 1] = w;
        g[v - 1][u - 1] = w;
    }
    Heuristica h(g,k);
    std::vector<std::set<int>> res = h.resolver();
    std::vector<int> conjuntoPorVertice(n);
    for ( int i = 0; i < k; i++) {
        for (auto & v : res[i]) {
            conjuntoPorVertice[v] = i;
        }
    }
    for (auto & conj : conjuntoPorVertice) {
        std::cout << conj + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}