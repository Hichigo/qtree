#include <ctime>
#include "qtree.h"

/*
struct ROOM {
	int x;
	int y;
	bool bTop;
	bool bRight;
	bool bBottom;
	bool bLeft;
	float roomSize;
	float corridorSize;
	float roomSizeHalf;
	float corridorSizeHalf;
	
	void construct(int xx, int yy, bool bbTop, bool bbRight, bool bbBottom, bool bbLeft, float froomSize, float fcorridorSize) {
		x = xx;
		y = yy;
		bTop = bbTop;
		bRight = bbRight;
		bBottom = bbBottom;
		bLeft = bbLeft;
		roomSize = froomSize;
		corridorSize = fcorridorSize;
		roomSizeHalf = roomSize / 2;
		corridorSizeHalf = corridorSize / 2;
	}
};
*/
/*//Наша структура
struct node
{
	int info; //Информационное поле
	char s;
	node *l, *r;//Левая и Правая часть дерева
};

node * tree = NULL; //Объявляем переменную, тип которой структура Дерево
*/
/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО
void push(int a, char str, node **t)
{
	if ((*t) == NULL) //Если дерева не существует
	{
		(*t) = new node; //Выделяем память
		(*t)->info = a; //Кладем в выделенное место аргумент a
		(*t)->s = str;
		(*t)->l = (*t)->r = NULL; //Очищаем память для следующего роста
		return; //Заложили семечко, выходим
	}
	//Дерево есть
	if (a>(*t)->info) push(a, 'r', &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
	else push(a, 'l', &(*t)->l); //Иначе кладем его влево
}
*/
/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ
void print(node *t, int u)
{
	if (t == NULL) return; //Если дерево пустое, то отображать нечего, выходим
	else //Иначе
	{
		print(t->l, ++u);//С помощью рекурсивного посещаем левое поддерево
		for (int i = 0; i<u; ++i) cout << "|";
		cout << t->info << ' ' << t->s << endl; //И показываем элемент
		u--;
	}
	print(t->r, ++u); //С помощью рекурсии посещаем правое поддерево
}
*/
/*
struct node
{
	int key;
	node *left;
	node *right;
};

void add(int a, node **leaf)
{
	if ((*leaf) == nullptr)
	{
		(*leaf) = new node;
		(*leaf)->key = a;
		(*leaf)->left = nullptr;
		(*leaf)->right = nullptr;
		return;
	}

	if (a > (*leaf)->key)
	{
		add(a, &(*leaf)->right);
	}
	else
	{
		add(a, &(*leaf)->left);
	}
}

void print(node *leaf, int d)
{
	if (leaf == nullptr)
	{
		return;
	}
	else
	{
		print(leaf->left, ++d);
		for (int i = 0; i < d; ++i)
		{
			cout << "|";
		}
		cout << leaf->key << endl;
		d--;
	}
	print(leaf->right, ++d);

}

node *root = nullptr;
int n; //Количество элементов
int s; //Число, передаваемое в дерево
cout << "введите количество элементов  ";
cin >> n; //Вводим количество элементов

for (int i = 0; i<n; ++i)
{
cout << "ведите число  ";
cin >> s; //Считываем элемент за элементом

add(s, &root); //И каждый кладем в дерево
}
cout << "ваше дерево\n";
print(root, 0);
*/

void main()
{
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));

	qtree tree;

	tree.fill_qtree();

	tree.print_qtree();


	/*
	for (int i = 0; i < 5; i++)
	{
		tree.insert(rand() % 6, 0);
	}
	tree.print_tree();
	node *r = tree.search(rand()%6, 0);

	if (r != nullptr)
		cout << r->x << endl;
	else
		cout << "nichego ne naideno" << endl;
	*/
	//system("pause");
}