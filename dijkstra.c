#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to find the unvisited node with the minimum distance
static int min_distance(int dist[], int visited[], int num_cities) {
    int min = INFINITY;
    int min_index = -1;

    for (int v = 0; v < num_cities; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to find the shortest path using Dijkstra's algorithm
Path* dijkstra(const Graph* graph, int start_node_id, int end_node_id) {
    int num_cities = graph->num_cities;
    int dist[num_cities];     // Stores the shortest distance from start_node_id to i
    int visited[num_cities];  // visited[i] is 1 if vertex i is included in shortest path tree
    int prev[num_cities];     // Stores the predecessor of each node in the shortest path

    // Initialize dist, visited, and prev arrays
    for (int i = 0; i < num_cities; i++) {
        dist[i] = INFINITY;
        visited[i] = 0;
        prev[i] = -1; // No predecessor yet
    }

    dist[start_node_id] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < num_cities - 1; count++) {
        int u = min_distance(dist, visited, num_cities);

        // If no unvisited node can be reached, or we've processed all reachable nodes
        if (u == -1 || dist[u] == INFINITY) {
            break;
        }

        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        Edge* current_edge = graph->adj_lists[u].head;
        while (current_edge != NULL) {
            int v = current_edge->dest_city_id;
            int weight = current_edge->weight;
            if (!visited[v] && dist[u] != INFINITY && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
            current_edge = current_edge->next;
        }
    }

    // Reconstruct the path
    Path* result_path = (Path*)malloc(sizeof(Path));
    if (result_path == NULL) {
        perror("Failed to allocate memory for path result");
        exit(EXIT_FAILURE);
    }
    result_path->path_nodes = NULL;
    result_path->path_length = 0;
    result_path->total_distance = -1; // Indicate no path found initially

    if (dist[end_node_id] == INFINITY) {
        return result_path; // No path found
    }

    result_path->total_distance = dist[end_node_id];

    // Build path in reverse
    int current_node = end_node_id;
    int temp_path[num_cities];
    int temp_path_len = 0;

    while (current_node != -1) {
        temp_path[temp_path_len++] = current_node;
        current_node = prev[current_node];
    }

    // Allocate memory for path_nodes and copy in correct order
    result_path->path_nodes = (int*)malloc(temp_path_len * sizeof(int));
    if (result_path->path_nodes == NULL) {
        perror("Failed to allocate memory for path nodes");
        free(result_path);
        exit(EXIT_FAILURE);
    }
    result_path->path_length = temp_path_len;
    for (int i = 0; i < temp_path_len; i++) {
        result_path->path_nodes[i] = temp_path[temp_path_len - 1 - i];
    }

    return result_path;
}

// Function to free the memory allocated for a Path
void free_path(Path* path) {
    if (path != NULL) {
        free(path->path_nodes);
        free(path);
    }
}
