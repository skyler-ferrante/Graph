#include <iostream>
#include <string>
#include <cassert>

#include <graph.hpp>

#define HIGH_AMOUNT 1000000
#define LOW_AMOUNT 0

using std::vector;
using std::string;
using std::cout;
using std::endl;

void test_create_edge(int amount);
void test_get_edges(int amount);
void test_bfs();

int main(int argc, char** argv){
	test_create_edge(HIGH_AMOUNT);
	test_create_edge(LOW_AMOUNT);

	test_get_edges(HIGH_AMOUNT);
	test_get_edges(LOW_AMOUNT);

	test_bfs();

	cout << "Tests passed" << endl;
	return 0;
}

void test_create_edge(int amount){
	// Test create edges without checking anything
	// Creating edges of undefined keys defines them
		
	Graph<int> g1;

	for(int i = 0; i < amount; i++){
		g1.create_edge(i-1, i);	
		g1.create_edge(i-2, i);
	}
}

void test_get_edges(int amount){
	// Test get edges by creating edges and checking for them
	
	Graph<int> g1;

	vector<int> correct_edges(amount);

	for(int i = 0; i < amount; i++){
		correct_edges[i] = i;
		g1.create_edge(0, i);
	}
	
	assert( correct_edges == g1.get_edges(0));
	assert( vector<int>{} == g1.get_edges(1));
	
	g1.create_undirected_edge(2,3);

	assert( vector<int>{2} == g1.get_edges(3));
	assert( vector<int>{3} == g1.get_edges(2));
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
	
	g1.create_undirected_edge(800, 799);

	// Possible path
	vector<int> correct_path = {1,4,7,11};
	vector<int> given_path = g1.bfs(1,11);

	assert( correct_path == given_path );

	// Not possible path
	correct_path = {};
	given_path = g1.bfs(0,800);
	
	assert( correct_path == given_path ); 

	// Empty graph
	Graph<int> g2;
	
	correct_path = {};
	given_path = g2.bfs(0,10);
	
	assert( correct_path == given_path );
}
