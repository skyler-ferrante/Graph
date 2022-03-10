#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

using std::cout;
using std::endl;

template<class T>
class Graph {
	public:
		Graph();
		void insert_node(T node);

		void create_edge(T from, T to);
		void create_undirected_edge(T a, T b);

		vector<T> get_edges(T node);

		void print_nodes();

	private:
		unordered_map<T, vector<T>> graph;
};

// We need to put template code in header files
// See: https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

template<class T>
Graph<T>::Graph(){
	;
};

template<class T>
void Graph<T>::insert_node(T node){
	vector<T> v;
	graph[node] = v;
}

template<class T>
void Graph<T>::create_edge(T from, T to){
	graph[from].push_back(to);
}

template<class T>
void Graph<T>::create_undirected_edge(T a, T b){
	graph[a].push_back(b);
	graph[b].push_back(a);
}

template<class T>
vector<T> Graph<T>::get_edges(T node){
	return graph[node];
}

template<class T>
void Graph<T>::print_nodes(){
	for(auto a : graph){
		cout << a.first << endl;

		for( auto ele : a.second ){
			cout << "\t" << ele << endl;
		}
	}
	
}

//template<class T>
//void Graph<T>::bfs(T root, T goal){
//	std::queue<T>

#endif
