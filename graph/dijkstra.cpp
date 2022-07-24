#include <fstream>
#include <iostream>
#include <vector>

#include "util.h"

std::vector<int> dijkstra(const std::vector<std::vector<int>> &adjacency) {
  
}

int main(int argc, char **argv) {
  const char *usage = "Usage: dijkstra GRAPH_FILE\n";
  if (argc != 2) {
    std::cerr << usage;
    return 1;
  }

  std::ifstream graph_file(argv[1]);
  auto adjacency = load_graph_file(graph_file);

  std::vector<int> shortest_paths = dijkstra(adjacency);
}
