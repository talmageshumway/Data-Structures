#include "Graph.h"
#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <climits>

using namespace std;

Graph::Graph()
{
	numVertices = 0;
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		for (size_t j = 0; j < MAX_VERTECIES; j++)
		{
			matrix[i][j] = INT_MAX;
		}
	}
}

void Graph::AddEdge(std::string source, std::string target, int weight)
{
	int fromIndex = GetIndex(source);
	int toIndex = GetIndex(target);
	assert(fromIndex != -1 and toIndex != -1);
	matrix[fromIndex][toIndex] = weight;
}

void Graph::AddVertex(std::string label)
{
	if (numVertices >= MAX_VERTECIES)
	{
		return;
	}

	vertices[numVertices].label = label;
	//vertices[numVertices].accessable = false;
	numVertices++;
}

int Graph::GetIndex(std::string label) const
{
	for (int i = 0; i < numVertices; i++)
	{
		if (vertices[i].label == label)
		{
			return i;
		}
	}
	return -1;
}

bool Graph::IsEdge(int sourceIndex, int targetIndex) const
{
	if (matrix[sourceIndex][targetIndex] != INT_MAX)
	{
		return true;
	}
	return false;
}

int Graph::GetWeight(int sourceIndex, int targetIndex) const
{

	return matrix[sourceIndex][targetIndex];

}

void Graph::BreadthFirstSearch(string startingVertex) const
{
	cout << "starting BFS with vertex " << vertices[GetIndex(startingVertex)].label << endl;
	int* visited = new int[numVertices];

	for (int i = 0; i < numVertices; i++)
	{
		visited[i] = -1;
	}
	BreadthFirstSearch(startingVertex, visited);
	for (int i = 0; i < numVertices; i++)
	{
		if (visited[i] != -1)
		{
			cout << "\t visited " << vertices[visited[i]].label << endl;
		}
	}
	cout << endl;
	delete[] visited;
}

void Graph::BreadthFirstSearch(std::string startingVertex, int visited[]) const
{
	int index = GetIndex(startingVertex);
	assert(index != -1);
	queue<int> que;
	set<int> found;
	int visitedIndex = 0;
	que.push(index);
	while (que.empty() == false)
	{
		//pop next index
		index = que.front();
		que.pop();
		if (found.find(index) == found.end())
		{
			visited[visitedIndex++] = index;
			found.insert(index);
			for (int i = 0; i < numVertices; i++)
			{
				if (IsEdge(index, i) == true and found.find(i) == found.end())
				{
					que.push(i);
				}
			}
		}
	}
}

void Graph::DijkstraShortestPath(string startingVertex) const
{

	int distance[MAX_VERTECIES];
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		distance[i] = INT_MAX;
	}

	int prevV[MAX_VERTECIES];
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		prevV[i] = -1;
	}
	DijkstraShortestPath(startingVertex, distance, prevV);
	//--------------------------------------------------------
	cout << "Shortest Distance starting from vertex " << vertices[GetIndex(startingVertex)].label << endl;
	for (int i = 0; i < numVertices; i++)
	{
		cout << "\tto: " << vertices[i].label << "\t"; //<<distance<< "Path: " << vertpath;	

		if (distance[i] == INT_MAX)//and matrix[GetIndex(startingVertex)][i] != INT_MAX)
		{
			cout << "no path";
		}
		else
		{
			cout << distance[i] << "\tPath: ";
			
			int path = prevV[i];
			cout << vertices[i].label;
			while (path != GetIndex(startingVertex) and path != -1)
			{
				cout << ", " << vertices[path].label;
				path = prevV[path];
			}
			if(vertices[i].label != vertices[GetIndex(startingVertex)].label)
			{
			 cout << ", " << vertices[GetIndex(startingVertex)].label;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Graph::DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const
{
	bool visited[MAX_VERTECIES];
	for (size_t i = 0; i < MAX_VERTECIES; i++)
	{
		visited[i] = false;
		distance[i] = INT_MAX;
		prevVertex[i] = -1;
	}
	int index = GetIndex(startingVertex);
	int currentDistance;
	int start = index;
	int next = index;
	distance[index] = 0;
	int smallest = index;

	// step 3
	for (int j = 0; j < numVertices; j++)//*
	{
		start = next;
		//find next
		smallest = -1;
		for (int i = 0; i < numVertices; i++)
		{
			if (visited[i] == false && distance[i] != INT_MAX)
			{
				smallest = i;
				break;
			}
		}
		if (smallest == -1)
			break;
		for (int i = 0; i < numVertices; i++)
		{//use smallest unvisited
			if (distance[i] < distance[smallest] and visited[i] == false)
			{
				smallest = i;
			}
		}
		next = smallest;

		// step 3b
		visited[next] = true;

		//check neighbors
		// step 3c
		for (int i = 0; i < numVertices; i++)
		{
			if (IsEdge(next, i) == true and visited[i] == false)  //found.find(i) == found.end())
			{
				currentDistance = distance[next] + GetWeight(next, i);
				//check the distance and update if smaller
				if (distance[i] > currentDistance)//current is shorter
				{
					distance[i] = currentDistance;

					prevVertex[i] = next;//? i'm putting F as c's and F's previous vertex
				}
			}
		}
	}
}

void Graph::PrintGraph() const
{
	cout << "numVerticies: " << numVertices << endl;
	cout << "\t";
	for (int i = 0; i < numVertices - 1; i++)
	{
		cout << vertices[i].label << "\t";
	}
	cout << vertices[numVertices - 1].label;
	cout << endl;
	for (int i = 0; i < numVertices; i++)
	{
		cout << vertices[i].label;
		for (int j = 0; j < numVertices; j++)
		{
			cout << "\t";
			if (matrix[i][j] != INT_MAX)
			{
				cout << matrix[i][j];
			}
			else
			{
				cout << "";
			}
		}
		cout << endl;
	}
	//cout << endl;
}
