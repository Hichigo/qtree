/*
	need more comments (it's for me :) )
*/

#pragma once
#include <iostream>
#include <fstream> //debug
#include <ctime>
#include <vector>
using namespace std;

struct node { // struct room
	int x;
	int y;
	int index;
	bool bTop;
	bool bRight;
	bool bBottom;
	bool bLeft;
	node *top;
	node *right;
	node *bottom;
	node *left;
};

class qtree
{
public:
	qtree();
	~qtree();

	void fill_qtree();
	void destroy_qtree();
	void print_qtree(); // debug
	void write_to_file(); //debug

private:
	void destroy_qtree(node *leaf); // something wrong (bug)
	void insert(int x, int y, int i, bool t, bool r, bool b, bool l, node *leaf, node *parent);
	void check_sides(node *leaf);
	bool search_by_coordinates(int x, int y);

	node *root;
	vector<node> nodes; // need for search (i don't know may be wrong)

	// limitation coordinates (-1, -1) (2, 2)
	int leftX; // x max left -1
	int rightX; // x max right 2
	int topY; // y max top -1
	int botY; // y max bottom 2
};