#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include "graph.h"

// Function to read cities from a file and add them to the graph
void read_cities_from_file(Graph* graph, const char* filename);

// Function to read distances from a file and add edges to the graph
void read_distances_from_file(Graph* graph, const char* filename);

#endif // FILE_PARSER_H
