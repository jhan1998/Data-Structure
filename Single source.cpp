#include <stdio.h> 
#include <limits.h> 
#include <iostream>
#include <cstdlib>
using namespace std;


int minDistance(int dist[], bool sptSet[], int V) 
{ 
	
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] < min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

void printPath(int parent[], int j) 
{ 
	if (parent[j] == - 1) 
		return; 

	printPath(parent, parent[j]); 

	cout << j << " "; 
} 

int printSolution(int dist[], int n, int parent[]) 
{ 
	int src = 0; 
	for (int i = 1; i < n; i++) 
	{
		if( parent[i] == -1)
			cout << "impossible"<< endl;
		else if( parent[i] != -1 )
		{
			cout << src << " "; 
			printPath(parent, i); 
			cout<< dist[i] << endl;
		}
	} 
} 

void dijkstra(int **graph, int src, int V) 
{ 

	int dist[V]; 

	bool sptSet[V]; 

	int parent[V]; 

	for (int i = 0; i < V; i++) 
	{ 
		parent[i] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = false; 
	} 

	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minDistance(dist, sptSet, V); 

		sptSet[u] = true; 

		for (int v = 0; v < V; v++) 

			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) 
			{ 
				parent[v] = u; 
				dist[v] = dist[u] + graph[u][v]; 
			} 
	} 
	printSolution(dist, V, parent); 
} 

int main() 
{
	while(!cin.eof())
	{
		int V;
		cin >> V;
		int graph[V][V];
		for(int i = 0 ; i < V ; i++)
			for( int j = 0 ; j < V ; j++)
				graph[i][j] = 0;
		int edge;
		cin >> edge;
		
		while( edge > 0 ){
			int e1, e2, w;
			int counter = 0;
			char input[10];
			while( cin >> input )
			{
				if(counter == 0){
					e1 = atoi(input);
					counter++;
				}
				else if( counter == 1 ){
					e2 = atoi(input);
					counter++;
				}
				else if( counter == 2 ){
					w = atoi(input);
					counter++;
				}
				if(cin.get() == '\n')
					break;
			}
			graph[e1][e2] = w;
			edge--;
		}
		int  *p[V];
		for(int i = 0 ; i < V ; i++)
			p[i] = graph[i];
		dijkstra(p, 0, V); 
	}
	return 0; 
} 

