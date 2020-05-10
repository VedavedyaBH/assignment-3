#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 



struct Eg 
{ 
	int src, dest, weight; 
}; 

struct Gp 
{ 
	int V, E;  
	struct Eg* edge; 
}; 

struct Gp* CG(int V, int E) 
{ 
	struct Gp* graph = new Gp; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Eg[E]; 

	return graph; 
} 
struct subset 
{ 
	int parent; 
	int rank; 
}; 
int find(struct subset subsets[], int i) 
{ 
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
}  
void Union(struct subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y);  
	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 
	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 

int Comp(const void* a, const void* b) 
{ 
	struct Eg* a1 = (struct Eg*)a; 
	struct Eg* b1 = (struct Eg*)b; 
	return a1->weight > b1->weight; 
} 


 void MST(struct Gp* graph) 
{ 
	int V = graph->V; 
	struct Eg result[V]; 
	int e = 0; 
	int i = 0;
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), Comp); 
 
	struct subset *subsets = 
		(struct subset*) malloc( V * sizeof(struct subset) );
  
	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 
 
	while (e < V - 1 && i < graph->E) 
	{  
		struct Eg next_edge = graph->edge[i++]; 

		int x = find(subsets, next_edge.src); 
		int y = find(subsets, next_edge.dest); 

		if (x != y) 
		{ 
			result[e++] = next_edge; 
			Union(subsets, x, y); 
		} 
		
	} 

	printf("Following are the edges in the constructed MST\n"); 
	for (i = 0; i < e; ++i) 
		printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
												result[i].weight); 
	return; 
} 
int main() 
{ 
	int V = ; 
	int E = ;
	struct Gp* graph = CG(V, E); 
 
	graph->edge[0].src = ; 
	graph->edge[0].dest = ; 
	graph->edge[0].weight = ; 

	graph->edge[1].src = ; 
	graph->edge[1].dest = ; 
	graph->edge[1].weight = ; 
 
	graph->edge[2].src = ; 
	graph->edge[2].dest = ; 
	graph->edge[2].weight = ; 

	graph->edge[3].src = ; 
	graph->edge[3].dest = ; 
	graph->edge[3].weight = ; 

	graph->edge[4].src = ; 
	graph->edge[4].dest = ; 
	graph->edge[4].weight = ; 

	MST(graph); 

	return 0; 
} 



 
