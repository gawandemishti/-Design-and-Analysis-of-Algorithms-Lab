#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 9999 
typedef struct{
int u,v,weight;
} Edge;
typedef struct{
int parent;
} Subset;
int find(Subset subsets[],int i){
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}
void Union(Subset subsets[],int x, int y){
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	subsets[xroot].parent = yroot;
}
void kruskalMST(int **cost, int V) {

	int edgeCount = 0;
	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++){
		if(cost[i][j] != 0 && cost[i][j] != INF){
			edgeCount++;
		}
	}
}
Edge *edges = (Edge *)malloc(edgeCount * sizeof(Edge));
int k = 0;
for (int i = 0; i < V; i++){
	for(int j = i + 1; j < V; j++){
		if (cost[i][j] != 0 && cost[i][j] != INF){
			edges[k].u = i;
			edges[k].v = j;
			edges[k].weight = cost[i][j];
			k++;
		}
	}
}
for(int i = 0; i < edgeCount - 1; i++){
	for (int j = 0; j < edgeCount - i - 1; j++){
		if(edges[j].weight > edges[j + 1].weight) {
			Edge temp = edges[j];
			edges[j] = edges[j + 1];
			edges[j + 1] = temp;
		}
	}
}
Subset *subsets = (Subset *)malloc(V* sizeof(Subset));
for(int v =0; v < V; v++){
	subsets[v].parent = v;
}
int mstEdges = 0;
int totalCost = 0;
int edgeIdx = 0;
while(mstEdges < V - 1 && edgeIdx < edgeCount){
	Edge nextEdges = edges[edgeIdx++];
	int x = find(subsets, nextEdges.u);
	int y = find(subsets, nextEdges.v);
	if ( x != y){
		printf("Edge %d:(%d, %d) cost:%d\n", mstEdges, nextEdges.u, nextEdges.v, nextEdges.weight);
		totalCost += nextEdges.weight;
		Union(subsets, x, y);
		mstEdges++;
	}
}
printf("Minimum cost= %d\n", totalCost);
free(edges);
free(subsets);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
