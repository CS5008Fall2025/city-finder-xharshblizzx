#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

#define INFINITY INT_MAX

// Structure to hold path information
typedef struct Path {
    int* path_nodes;
    int path_length;
    int total_distance;
} Path;

// Function to find the shortest path using Dijkstra's algorithm
Path* dijkstra(const Graph* graph, int start_node_id, int end_node_id);

// Function to free the memory allocated for a Path
void free_path(Path* path);

#endif // DIJKSTRA_H
