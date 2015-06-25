/*
	НУЖНО БОЛЬШЕ КОММЕНТАРИЕВ
*/

#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

struct node {
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

	void insert(int x, int y);
	void fill_qtree();
	node *search(int x, int y);
	void destroy_tree();
	void print_tree();
	void print_qtree();
	void write_to_file();

private:
	void destroy_tree(node *leaf);
	void insert(int x, int y, node *leaf);
	node *search(int x, int y, node *leaf);
	void print(node *leaf, int depth);

	//qtree
	void insert(int x, int y, int i, bool t, bool r, bool b, bool l, node *leaf, node *parent);
	void check_sides(node *leaf);
	bool search_by_coordinates(int x, int y);

	node *root;
	vector<node> nodes;

	// ограничивающий генерацию квадрат (-1, -1) (2, 2)
	int leftX; // x слева -1
	int rightX; // x справа 2
	int topY; // y сверху -1
	int botY; // y снизу 2
};