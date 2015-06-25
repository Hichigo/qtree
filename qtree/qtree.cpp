#include "qtree.h"

qtree::qtree()
{
	srand((unsigned)time(nullptr));

	root = nullptr;

	leftX = -3;
	rightX = 5;
	topY = -5;
	botY = 3;

}

qtree::~qtree()
{
	destroy_qtree();
}

void qtree::destroy_qtree(node *leaf) 
{
	if (leaf != nullptr)
	{
		if (leaf->top != nullptr)
			destroy_qtree(leaf->top);
		
		if (leaf->right != nullptr)
			destroy_qtree(leaf->right);

		if (leaf->bottom != nullptr)
			destroy_qtree(leaf->bottom);

		if (leaf->left != nullptr)
			destroy_qtree(leaf->left);

		delete leaf;
	}
}

void qtree::destroy_qtree()
{
	destroy_qtree(root);
}

void qtree::fill_qtree()
{
	root = new node;
	root->x = 0;
	root->y = 0;

	root->index = 0;
	
	root->bTop = true;
	root->bRight = true;
	root->bBottom = true;
	root->bLeft = true;

	root->top = nullptr;
	root->right = nullptr;
	root->bottom = nullptr;
	root->left = nullptr;

	nodes.push_back(*root);

	check_sides(root);
}

void qtree::check_sides(node *leaf)
{
	//проверяем верх
	if ((leaf->y - 1) >= topY && !search_by_coordinates(leaf->x, leaf->y - 1))
	{
		if (leaf->bTop)
		{
			leaf->top = new node;
			insert(leaf->x, leaf->y - 1, 0, false, false, true, false, leaf->top, leaf);
		}
	}
	else
	{
		leaf->bTop = false;
		leaf->top = nullptr;
	}
	//проверяем правую сторону
	if ((leaf->x + 1) <= rightX && !search_by_coordinates(leaf->x + 1, leaf->y))
	{
		if (leaf->bRight)
		{
			leaf->right = new node;
			insert(leaf->x + 1, leaf->y, 0, false, false, false, true, leaf->right, leaf);
		}
	}
	else
	{
		leaf->bRight = false;
		leaf->right = nullptr;
	}
	//проверяем низ
	if ((leaf->y + 1) <= botY && !search_by_coordinates(leaf->x, leaf->y + 1))
	{
		if (leaf->bBottom)
		{
			leaf->bottom = new node;
			insert(leaf->x, leaf->y + 1, 0, true, false, false, false, leaf->bottom, leaf);
		}
	}
	else
	{
		leaf->bBottom = false;
		leaf->bottom = nullptr;
	}
	//проверяем левую сторону
	if ((leaf->x - 1) >= leftX && !search_by_coordinates(leaf->x - 1, leaf->y))
	{
		if (leaf->bLeft)
		{
			leaf->left = new node;
			insert(leaf->x - 1, leaf->y, 0, false, true, false, false, leaf->left, leaf);
		}
	}
	else
	{
		leaf->bLeft = false;
		leaf->left = nullptr;
	}

	// если сторона не пустая то добавляем "лист"
	if (leaf->top != nullptr)
	{
		check_sides(leaf->top);
	}
	//else
	//{
	//	leaf->bTop = false;
	//}

	if (leaf->right != nullptr)
	{
		check_sides(leaf->right);
	}
	//else
	//{
	//	leaf->bRight = false;
	//}

	if (leaf->bottom != nullptr)
	{
		check_sides(leaf->bottom);
	}
	//else
	//{
	//	leaf->bBottom = false;
	//}

	if (leaf->left != nullptr)
	{
		check_sides(leaf->left);
	}
	//else
	//{
	//	leaf->bLeft = false;
	//}
}

void qtree::insert(int x, int y, int i, bool t, bool r, bool b, bool l, node *leaf, node *parent)
{
	if (!t)
	{
		leaf->bTop = rand() % 2 == 0 ? false : true;
		leaf->top = nullptr;
	}
	else
	{
		leaf->top = parent;
	}
	if (!r)
	{
		leaf->bRight = rand() % 2 == 0 ? false : true;
		leaf->right = nullptr;
	}
	else
	{
		leaf->right = parent;
	}
	if (!b)
	{
		leaf->bBottom = rand() % 2 == 0 ? false : true;
		leaf->bottom = nullptr;
	}
	else
	{
		leaf->bottom = parent;
	}
	if (!l)
	{
		leaf->bLeft = rand() % 2 == 0 ? false : true;
		leaf->left = nullptr;
	}
	else
	{
		leaf->left = parent;
	}

	leaf->x = x;
	leaf->y = y;

	leaf->index = i;

	nodes.push_back(*leaf);
}

bool qtree::search_by_coordinates(int x, int y)
{
	for (vector<node>::iterator it = nodes.begin(); it < nodes.end(); ++it)
	{
		if (it->x == x && it->y == y)
		{
			return true;
		}
	}
	return false;
}

void qtree::print_qtree()
{
	for (vector<node>::iterator it = nodes.begin(); it < nodes.end(); ++it)
	{
		cout << it->x << " " << it->y << endl;
		cout << it->bTop << " ";
		cout << it->bRight << " ";
		cout << it->bBottom << " ";
		cout << it->bLeft << endl << endl;
	}
}

void qtree::write_to_file()
{
	ofstream debug;
	debug.open("debug.txt");
	debug << "[";
	for (vector<node>::iterator it = nodes.begin(); it < nodes.end(); ++it)
	{
		debug << "{" << endl;
		debug << "\"x\": " << it->x << "," << endl;
		debug << "\"y\": " << it->y << "," << endl;
		debug << "\"t\": " << it->bTop << "," << endl;
		debug << "\"r\": " << it->bRight << "," << endl;
		debug << "\"b\": " << it->bBottom << "," << endl;
		debug << "\"l\": " << it->bLeft << endl;
		debug << "}," << endl;
	}
	debug << "]";
	debug.close();
}