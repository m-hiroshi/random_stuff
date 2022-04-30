#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

int prim(std::vector<std::vector<int>>& adjacency) {
    int N = adjacency.size();
    if (N == 0) return 0;

    std::vector<bool> connected(N, false);
    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>> heap;
    heap.push({0, 0});

    int num_connected = 0, res = 0;
    while (num_connected != N) {
        auto [weight, vert] = heap.top();
        heap.pop();

        if (connected[vert]) continue;
        connected[vert] = true;
        res += weight;
        ++num_connected;

        for (int i = 0; i < N; ++i) {
            if (!connected[i]) {
                heap.push({adjacency[vert][i], i});
            }
        }
    }

    return res;
}

int main(int argc, char **argv) {
    const char *usage = "Usage: prim GRAPH_FILE\n";
    if (argc != 2) {
        std::cerr << usage;
        return 1;
    }

    std::ifstream graph_file(argv[1]);
    std::string line;
    std::getline(graph_file, line);

    int num_vert;
    num_vert = std::stod(line);
    std::vector<std::vector<int>> adjacency(
        num_vert, std::vector(num_vert, std::numeric_limits<int>::max()));

    int node1, node2, dist;
    while (std::getline(graph_file, line)) {
        std::istringstream line_stream(line);
        line_stream >> node1 >> node2 >> dist;
        adjacency[node1][node2] = adjacency[node2][node1] = dist;
    }

    std::cout << "Total of cost in the minimum spanning tree: " << prim(adjacency) << "\n";
    return 0;
}