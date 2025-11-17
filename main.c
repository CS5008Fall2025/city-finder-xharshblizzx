#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "file_parser.h"
#include "dijkstra.h"

#define MAX_INPUT_LENGTH 256

// Function to print the help message
void print_help() {
    printf("Commands:\n");
    printf("\tlist - list all cities\n");
    printf("\t<city1> <city2> - find the shortest path between two cities\n");
    printf("\thelp - print this help message\n");
    printf("\texit - exit the program\n");
}

// Function to print an invalid command message and help
void print_invalid_command() {
    printf("Invalid Command\n");
    print_help();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <vertices_file> <distances_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Graph* graph = create_graph();
    read_cities_from_file(graph, argv[1]);
    read_distances_from_file(graph, argv[2]);

    printf("*****Welcome to the shortest path finder!******\n");
    print_help();
    printf("*******************************************************\n");

    char input[MAX_INPUT_LENGTH];
    while (1) {
        printf("Where do you want to go today? ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Error or EOF
        }

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        char* token = strtok(input, " ");

        if (token == NULL) {
            print_invalid_command();
            continue;
        }

        if (strcmp(token, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(token, "help") == 0) {
            print_help();
        } else if (strcmp(token, "list") == 0) {
            for (int i = 0; i < graph->num_cities; i++) {
                printf("%s\n", graph->cities[i].name);
            }
        } else {
            char* city1_name = token;
            char* city2_name = strtok(NULL, " ");

            if (city1_name != NULL && city2_name != NULL) {
                int city1_id = get_city_id(graph, city1_name);
                int city2_id = get_city_id(graph, city2_name);

                if (city1_id != -1 && city2_id != -1) {
                    Path* shortest_path = dijkstra(graph, city1_id, city2_id);

                    if (shortest_path->total_distance != -1) {
                        printf("Path Found...\n");
                        for (int i = 0; i < shortest_path->path_length; i++) {
                            printf("\t%s\n", graph->cities[shortest_path->path_nodes[i]].name);
                        }
                        printf("Total Distance: %d\n", shortest_path->total_distance);
                    } else {
                        printf("Path Not Found...\n");
                    }
                    free_path(shortest_path);
                } else {
                    print_invalid_command();
                }
            } else {
                print_invalid_command();
            }
        }
    }

    free_graph(graph);
    return EXIT_SUCCESS;
}
