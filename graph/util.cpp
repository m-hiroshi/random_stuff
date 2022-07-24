#include "util.h"

#include <limits>
#include <sstream>

std::vector<std::vector<int>> load_graph_file(std::ifstream& graph_file) {
  std::string line;
  std::getline(graph_file, line);

  int num_vert;
  num_vert = std::stod(line);
  std::vector<std::vector<int>> adjacency(
      num_vert, std::vector<int>(num_vert, std::numeric_limits<int>::max()));

  int node1, node2, dist;
  while (std::getline(graph_file, line)) {
    std::istringstream line_stream(line);
    line_stream >> node1 >> node2 >> dist;
    adjacency[node1][node2] = adjacency[node2][node1] = dist;
  }

  return adjacency;
}
