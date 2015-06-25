#include <ctime>
#include "qtree.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));

	qtree tree;

	tree.fill_qtree();

	tree.print_qtree();
	tree.write_to_file();

	//tree.destroy_qtree();

}