#pragma once
#include <vector>
#include <unordered_map>

class Graph {
    private:
        void deep_first_search_alg(int node, std::vector<bool> &visited,
                std::unordered_map<int, std::vector<int>> &adj);

    public:
        int countComponents(int n, std::vector<std::vector<int>> &edges);
};
