#include "ex3.hpp"

void Graph::deep_first_search_alg(int node, std::vector<bool> &visited,
                std::unordered_map<int, std::vector<int>> &adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            deep_first_search_alg(neighbor, visited, adj);
        }
    }
}

int Graph::countComponents(int n, std::vector<std::vector<int>> &edges) {
    std::unordered_map<int, std::vector<int>> adj;
    std::vector<bool> visited(n, false);
    int components = 0;

    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            deep_first_search_alg(i, visited, adj);
            components++;
        }
    }

    return components;
}
