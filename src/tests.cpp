#include <iostream>
#include <string>
#include <cassert>

#include <graph.hpp>

using std::vector;
using std::string;
using std::cerr;
using std::cout;
using std::endl;

void test_insert();
void test_create_edge();
void test_get_edges();
void test_bfs();

int main(int argc, char** argv){
	test_insert();
	test_create_edge();
	test_get_edges();
	test_bfs();

	cout << "Tests passed" << std::endl;
	return 0;
}

void test_insert(){
	// Test inserting without doing anything

	// Testing insert numbers
	Graph<int> g1;
	for(int i = 0; i < 1000; i++){
		g1.insert_node(i);
	}

	// Testing insert strings
	Graph<string> g2;
	g2.insert_node("Test");
	g2.insert_node("Test2");
	g2.insert_node("Test3");
}

void test_create_edge(){
	// Test create edges without checking anything
	// Creating edges of undefined keys defines them
		
	Graph<int> g1;

	for(int i = 0; i < 1000; i++){
		g1.insert_node(i);
		g1.create_edge(i-1, i);	
		g1.create_edge(i-2, i);
	}
}

void test_get_edges(){
	// Test get edges by creating edges and checking for them
	
	int amount = 1000;
	Graph<int> g1;

	g1.insert_node(0);
	for(int i = 1; i < amount; i++){
		g1.create_undirected_edge(0, i);
	}
	
	int x = 1;
	for( auto a : g1.get_edges(0) ){
		assert( x == a );
		x++;
	}
	
	for(int i = 1; i < amount; i++){
		vector<int> v = g1.get_edges(i);

		assert( v.size() == 1 );
		assert( v[0] == 0 );
	}
}

void test_bfs(){
	// Test breadth first search
	
	Graph<int> g1;

	g1.create_undirected_edge(1, 2);
	g1.create_undirected_edge(1, 3);
	g1.create_undirected_edge(1, 4);

	g1.create_undirected_edge(2, 5);
	g1.create_undirected_edge(2, 6);

	g1.create_undirected_edge(4, 7);
	g1.create_undirected_edge(4, 8);

	g1.create_undirected_edge(5, 9);
	g1.create_undirected_edge(5, 10);

	g1.create_undirected_edge(7, 11);
	g1.create_undirected_edge(7, 12);

	g1.create_undirected_edge(8, 12);
	
	vector<int> correct_path = {1,4,7,11};
	vector<int> given_path = g1.bfs(1,11);

	assert( correct_path == given_path );
}
