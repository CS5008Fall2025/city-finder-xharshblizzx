#include "file_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Function to read cities from a file and add them to the graph
void read_cities_from_file(Graph* graph, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening cities file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) > 0) {
            add_city(graph, line);
        }
    }
    fclose(file);
}

// Function to read distances from a file and add edges to the graph
void read_distances_from_file(Graph* graph, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening distances file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char city1_name[50];
        char city2_name[50];
        int distance;

        // Attempt to parse the line
        if (sscanf(line, "%49s %49s %d", city1_name, city2_name, &distance) == 3) {
            int city1_id = get_city_id(graph, city1_name);
            int city2_id = get_city_id(graph, city2_name);

            if (city1_id != -1 && city2_id != -1) {
                add_edge(graph, city1_id, city2_id, distance);
            } else {
                fprintf(stderr, "Warning: Skipping distance entry with unknown city: %s\n", line);
            }
        } else {
            fprintf(stderr, "Warning: Skipping malformed distance entry: %s\n", line);
        }
    }
    fclose(file);
}
