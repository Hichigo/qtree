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
/*//���� ���������
struct node
{
	int info; //�������������� ����
	char s;
	node *l, *r;//����� � ������ ����� ������
};

node * tree = NULL; //��������� ����������, ��� ������� ��������� ������
*/
/*������� ������ �������� � �������� ������
void push(int a, char str, node **t)
{
	if ((*t) == NULL) //���� ������ �� ����������
	{
		(*t) = new node; //�������� ������
		(*t)->info = a; //������ � ���������� ����� �������� a
		(*t)->s = str;
		(*t)->l = (*t)->r = NULL; //������� ������ ��� ���������� �����
		return; //�������� �������, �������
	}
	//������ ����
	if (a>(*t)->info) push(a, 'r', &(*t)->r); //���� �������� � ������ ��� ������� �������, ������ ��� ������
	else push(a, 'l', &(*t)->l); //����� ������ ��� �����
}
*/
/*������� ����������� ������ �� ������
void print(node *t, int u)
{
	if (t == NULL) return; //���� ������ ������, �� ���������� ������, �������
	else //�����
	{
		print(t->l, ++u);//� ������� ������������ �������� ����� ���������
		for (int i = 0; i<u; ++i) cout << "|";
		cout << t->info << ' ' << t->s << endl; //� ���������� �������
		u--;
	}
	print(t->r, ++u); //� ������� �������� �������� ������ ���������
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
int n; //���������� ���������
int s; //�����, ������������ � ������
cout << "������� ���������� ���������  ";
cin >> n; //������ ���������� ���������

for (int i = 0; i<n; ++i)
{
cout << "������ �����  ";
cin >> s; //��������� ������� �� ���������

add(s, &root); //� ������ ������ � ������
}
cout << "���� ������\n";
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