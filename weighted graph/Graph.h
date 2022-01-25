#include <algorithm>
#include <iostream>
using namespace std;

class Vertex
{
public:
	std::string label;
	//bool accessable;
};

class Graph
{
public:
	Graph();
	~Graph() = default;

	void AddEdge(std::string source, std::string target, int weight);
	void AddVertex(std::string label);
	int GetIndex(std::string label) const; // -1 if label is not found
	bool IsEdge(int sourceIndex, int targetIndex) const;
	int GetWeight(int sourceIndex, int targetIndex) const;
	void BreadthFirstSearch(string startingVertex) const;
	void BreadthFirstSearch(std::string startingVertex, int visited[]) const;
	void DijkstraShortestPath(string startingVertex) const;
	void DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const;
	void PrintGraph() const;
	static const int MAX_VERTECIES = 10;
private:
	int matrix[MAX_VERTECIES][MAX_VERTECIES];
	int numVertices;
	Vertex vertices[MAX_VERTECIES];
};

