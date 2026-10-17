#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	
    int distance[MAX];
    int pred[MAX];
    int visited[MAX];
    int count, min_distance, nextnode, i, j;

    // Initialize distance matrix, predecessor, and visited arrays
    for (i = 1; i <= n; i++) {
        distance[i] = INFINITY;
        pred[i] = -1;
        visited[i] = 0;
    }

    // Initialize start node
    distance[startnode] = 0;
    count = 0;

    while (count < n) {
        min_distance = INFINITY;
        nextnode = -1;

        // Choose the unvisited node with the minimum distance
        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < min_distance) {
                min_distance = distance[i];
                nextnode = i;
            }
        }

        if (nextnode == -1) {
            break;
        }

        visited[nextnode] = 1;
        count++;

        // Relax adjacent edges
        for (i = 1; i <= n; i++) {
            if (!visited[i] && G[nextnode][i] > 0 && G[nextnode][i] != INFINITY) {
                if (distance[nextnode] + G[nextnode][i] < distance[i]) {
                    distance[i] = distance[nextnode] + G[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
    }

    // Print results with corrected %4d width alignment
    printf("Node\tDistance\tPath\n");
    for (i = 1; i <= n; i++) {
        if (i == startnode) {
            continue; 
        }

        if (distance[i] == INFINITY) {
            printf("%4d\t%8s\tNO PATH\n", i, "INF");
        } else {
            printf("%4d\t%8d\t", i, distance[i]);
            
            // Reconstruct path backward
            j = i;
            printf("%d", j);
            while (pred[j] != -1) {
                printf("<-%d", pred[j]);
                j = pred[j];
            }
            printf("\n");
        }
    }



}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
