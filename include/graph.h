//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_GRAPH_H
#define DS_LIBRARY_GRAPH_H

#include "linkedlist.h" // Dependency on Linked List ADT for adjacency list
#include "queue.h"      // Dependency on Queue ADT for BFS
#include "stack.h"      // Dependency on Stack ADT for DFS

// Opaque struct for GraphNode, used in adjacency lists
typedef struct GraphNode GraphNode;

// Opaque struct for Graph (supports directed and undirected graphs)
typedef struct Graph Graph;

// Creates a Graph with the specified number of vertices
// Parameters: numVertices (number of vertices), isDirected (1 for directed, 0 for undirected)
// Returns: Pointer to the created Graph, or NULL if allocation fails
Graph* createGraph(int numVertices, int isDirected);

// Adds an edge to the Graph
// Parameters: graph (Graph pointer), src (source vertex), dest (destination vertex)
// Precondition: src and dest are valid vertex indices (0 to numVertices-1)
void addEdge(Graph* graph, int src, int dest);

// Performs Breadth-First Search (BFS) starting from a given vertex
// Parameters: graph (Graph pointer), startVertex (starting vertex)
// Precondition: startVertex is a valid vertex index
void bfs(Graph* graph, int startVertex);

// Performs Depth-First Search (DFS) starting from a given vertex
// Parameters: graph (Graph pointer), startVertex (starting vertex)
// Precondition: startVertex is a valid vertex index
void dfs(Graph* graph, int startVertex);

// Placement problem: Detects a cycle in an undirected Graph
// Parameters: graph (Graph pointer)
// Returns: 1 if a cycle exists, 0 otherwise
// Precondition: graph is undirected
int detectCycle(Graph* graph);

// Frees the Graph and its nodes
// Parameters: graph (Graph pointer)
void freeGraph(Graph* graph);

#endif // DS_LIBRARY_GRAPH_H
