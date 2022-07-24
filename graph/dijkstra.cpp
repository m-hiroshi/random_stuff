#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <set>
#include <unordered_set>
#include <vector>

#include "util.h"

std::vector<int> dijkstra(const std::vector<std::vector<int>> &adjacency) {
  if (adjacency.empty()) return {};
 
  std::vector<int> res(adjacency.size(), std::numeric_limits<int>::max());
  
  auto cmp = [&res](int left, int right) { return res[left] < res[right]; };
  std::set<int, decltype(cmp)> to_visit(cmp);
  res[0] = 0;
  to_visit.insert(0);

  while (to_visit.size()) {
    auto it = to_visit.begin();
    int node = *it;
    to_visit.erase(it);

    const std::vector<int>& neighbors = adjacency[node];
    for (int i = 0; i < neighbors.size(); ++i) {
      if (i == node || neighbors[i] == std::numeric_limits<int>::max()) continue;
      if (res[node] + neighbors[i] < res[i]) {
        it = to_visit.find(i);
        if (it != to_visit.end()) to_visit.erase(it);
        res[i] = res[node] + neighbors[i];
        to_visit.insert(i);
      }
    }
  }

  return res;
}

int main(int argc, char **argv) {
  const char *usage = "Usage: dijkstra GRAPH_FILE\n";
  if (argc != 2) {
    std::cerr << usage;
    return 1;
  }

  std::ifstream graph_file(argv[1]);
  auto adjacency = load_graph_file(graph_file);

  std::vector<int> shortest_dists = dijkstra(adjacency);
  std::cout << "Shortest distance from node 0 to each node:\n";
  for (int dist : shortest_dists) {
    std::cout << dist << ' ';
  }
  std::cout << '\n';

  return 0;
}
