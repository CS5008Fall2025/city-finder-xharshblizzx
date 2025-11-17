#ifndef GRAPH_H
#define GRAPH_H

#include <limits.h> // For INT_MAX

#define MAX_CITIES 100 // Assuming a maximum of 100 cities for now

// Structure to represent an edge in the graph
typedef struct Edge {
    int dest_city_id;
    int weight;
    struct Edge* next;
} Edge;

// Structure to represent a city (vertex)
typedef struct City {
    char name[50]; // Assuming city names won't exceed 49 characters
    int id;
} City;

// Structure to represent the adjacency list for a city
typedef struct AdjacencyList {
    Edge* head; // Pointer to the head of the edge list
} AdjacencyList;

// Structure to represent the graph
typedef struct Graph {
    int num_cities;
    City cities[MAX_CITIES];
    AdjacencyList adj_lists[MAX_CITIES];
} Graph;

// Function declarations
Graph* create_graph();
void add_city(Graph* graph, const char* city_name);
void add_edge(Graph* graph, int src_id, int dest_id, int weight);
int get_city_id(const Graph* graph, const char* city_name);
void print_graph(const Graph* graph); // For debugging
void free_graph(Graph* graph);

#endif // GRAPH_H
