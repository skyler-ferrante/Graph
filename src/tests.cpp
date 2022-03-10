#include <iostream>
#include <string>
#include <cassert>

#include <graph.hpp>


using std::vector;
using std::string;
using std::cerr;
using std::cout;
using std::endl;

void test_insert(){
	Graph<int> g1;

	for(int i = 0; i < 1000; i++){
		g1.insert_node(i);
	}

	Graph<string> g2;
	g2.insert_node("Test");
	g2.insert_node("Test2");
	g2.insert_node("Test3");
}

void test_create_edge(){
	Graph<int> g1;

	for(int i = 0; i < 1000; i++){
		g1.insert_node(i);
		g1.create_edge(i-1, i);
	}
}

void test_get_edges(){
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

int main(int argc, char** argv){
	test_insert();
	test_create_edge();
	test_get_edges();

	cout << "Tests passed" << std::endl;
	return 0;
}
