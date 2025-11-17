#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new graph
Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        perror("Failed to allocate memory for graph");
        exit(EXIT_FAILURE);
    }
    graph->num_cities = 0;
    for (int i = 0; i < MAX_CITIES; i++) {
        graph->adj_lists[i].head = NULL;
    }
    return graph;
}

// Function to add a city to the graph
void add_city(Graph* graph, const char* city_name) {
    if (graph->num_cities >= MAX_CITIES) {
        fprintf(stderr, "Error: Maximum number of cities reached.\n");
        return;
    }
    // Check if city already exists
    if (get_city_id(graph, city_name) != -1) {
        return; // City already exists, do nothing
    }

    City new_city;
    strncpy(new_city.name, city_name, sizeof(new_city.name) - 1);
    new_city.name[sizeof(new_city.name) - 1] = '\0'; // Ensure null-termination
    new_city.id = graph->num_cities;
    graph->cities[graph->num_cities] = new_city;
    graph->num_cities++;
}

// Function to add an edge to the graph (undirected)
void add_edge(Graph* graph, int src_id, int dest_id, int weight) {
    if (src_id < 0 || src_id >= graph->num_cities || dest_id < 0 || dest_id >= graph->num_cities) {
        fprintf(stderr, "Error: Invalid city ID for adding edge.\n");
        return;
    }

    // Add edge from src to dest
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    if (new_edge == NULL) {
        perror("Failed to allocate memory for edge");
        exit(EXIT_FAILURE);
    }
    new_edge->dest_city_id = dest_id;
    new_edge->weight = weight;
    new_edge->next = graph->adj_lists[src_id].head;
    graph->adj_lists[src_id].head = new_edge;

    // Add edge from dest to src (since it's an undirected graph)
    new_edge = (Edge*)malloc(sizeof(Edge));
    if (new_edge == NULL) {
        perror("Failed to allocate memory for edge");
        exit(EXIT_FAILURE);
    }
    new_edge->dest_city_id = src_id;
    new_edge->weight = weight;
    new_edge->next = graph->adj_lists[dest_id].head;
    graph->adj_lists[dest_id].head = new_edge;
}

// Function to get a city's ID by its name
int get_city_id(const Graph* graph, const char* city_name) {
    for (int i = 0; i < graph->num_cities; i++) {
        if (strcmp(graph->cities[i].name, city_name) == 0) {
            return graph->cities[i].id;
        }
    }
    return -1; // City not found
}

// Function to print the graph (for debugging)
void print_graph(const Graph* graph) {
    printf("Graph (Number of cities: %d):\n", graph->num_cities);
    for (int i = 0; i < graph->num_cities; i++) {
        printf("City %d (%s): ", graph->cities[i].id, graph->cities[i].name);
        Edge* current = graph->adj_lists[i].head;
        while (current != NULL) {
            printf("-> %s (%d) ", graph->cities[current->dest_city_id].name, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_cities; i++) {
        Edge* current = graph->adj_lists[i].head;
        while (current != NULL) {
            Edge* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
}
