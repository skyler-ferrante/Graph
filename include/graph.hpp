#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>

using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::list;

using std::cout;
using std::endl;

template<class T>
class Graph {
	public:
		Graph();

		// Create directed edge from first to second parameter
		void create_edge(T from, T to);

		// Create undirected edge from first to second parameter
		void create_undirected_edge(T a, T b);

		// Get edges of given node
		vector<T> get_edges(T node);

		// Print representation of graph to stdout
		void print_nodes();

		// Breadth first search
		vector<T> bfs(T root, T goal);

	private:
		// Hash map of nodes to edges
		unordered_map<T, vector<T>> graph;
};

// We need to put template code in header files
// See: https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

template<class T>
Graph<T>::Graph(){};

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

template<class T>
vector<T> Graph<T>::bfs(T root, T goal){
	unordered_set<T> s;
	list< vector<T> > q;

	s.insert(root);
	q.push_back( {root} );
	
	T current;

	while( not q.empty() ){
		vector<T> path = q.front();	
		q.pop_front();

		current = path.back();

		if( current == goal ){
			return path;
		}

		for( T edge : get_edges(current) ){

			// If edge not in set
			if( s.find(edge) == s.end() ){
				vector<T> new_path {path};
				new_path.push_back(edge);
				
				s.insert(edge);
				q.push_back( new_path);
			}
		}
	}

	vector<T> empty;
	return empty;
}

#endif
