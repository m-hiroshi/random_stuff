#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#include "util.h"

int prim(std::vector<std::vector<int>> &adjacency) {
  int N = adjacency.size();
  if (N == 0)
    return 0;

  std::vector<bool> connected(N, false);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> heap;
  heap.push({0, 0});

  int num_connected = 0, res = 0;
  while (num_connected != N) {
    auto [weight, vert] = heap.top();
    heap.pop();

    if (connected[vert])
      continue;
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
  auto adjacency = load_graph_file(graph_file);

  std::cout << "Total of cost in the minimum spanning tree: " << prim(adjacency)
            << "\n";
  return 0;
}
