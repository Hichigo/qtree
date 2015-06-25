#include "qtree.h"

qtree::qtree()
{
	srand((unsigned)time(nullptr));

	root = nullptr;

	leftX = -1;
	rightX = 2;
	topY = -1;
	botY = 2;

}

qtree::~qtree()
{
	destroy_tree();
}

void qtree::destroy_tree(node *leaf)
{
	if (leaf != nullptr)
	{
		//destroy_tree(leaf->top);
		destroy_tree(leaf->right);
		//destroy_tree(leaf->bottom);
		destroy_tree(leaf->left);
		delete leaf;
	}
}

void qtree::destroy_tree()
{
	destroy_tree(root);
}

void qtree::insert(int x, int y, node *leaf)
{
	if (x >= leaf->x)
	{
		if (leaf->right != nullptr)
		{
			insert(x, 0, leaf->right);
		}
		else
		{
			leaf->right = new node;
			leaf->right->x = x;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
	else if (x < leaf->x)
	{
		if (leaf->left != nullptr)
		{
			insert(x, 0, leaf->left);
		}
		else
		{
			leaf->left = new node;
			leaf->left->x = x;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
}

void qtree::insert(int x, int y)
{
	if (root != nullptr)
	{
		insert(x, y, root);
	}
	else
	{
		root = new node;
		root->x = x;
		root->left = nullptr;
		root->right = nullptr;
	}
}

void qtree::print_tree()
{
	print(root, 0);
}

void qtree::print(node *leaf, int depth)
{
	if (leaf == nullptr)
	{
		return;
	}
	else
	{
		print(leaf->left, ++depth);
		for (int i = 0; i < depth; ++i)
		{
			cout << "|";
		}
		cout << leaf->x << endl;
		depth--;
	}
	print(leaf->right, ++depth);
}

node *qtree::search(int x, int y)
{
	return search(x, y, root);
}

node *qtree::search(int x, int y, node *leaf)
{
	if (leaf != nullptr)
	{
		if (x == leaf->x)
		{
			return leaf;
		}
		if (x < leaf->x)
		{
			return search(x, y, leaf->left);
		}
		else
		{
			return search(x, y, leaf->right);
		}
	}
	else
	{
		return nullptr;
	}
}

void qtree::fill_qtree()
{
	root = new node;
	root->x = 0;
	root->y = 0;
	
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
	if ((leaf->x - 1) <= leftX && !search_by_coordinates(leaf->x - 1, leaf->y))
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

	if (leaf->top != nullptr)
	{
		check_sides(leaf->top);
	}
	if (leaf->right != nullptr)
	{
		check_sides(leaf->right);
	}
	if (leaf->bottom != nullptr)
	{
		check_sides(leaf->bottom);
	}
	if (leaf->left != nullptr)
	{
		check_sides(leaf->left);
	}
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