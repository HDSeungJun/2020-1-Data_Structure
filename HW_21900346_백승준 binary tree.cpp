#include <iostream>
using namespace std;

class node
{
public:
	string name;
	double score;
	node* left;
	node* right;
	void set_data(string n, double s);
};

class tree
{
public:
	int node_count;
	node* root;
	tree();
	int insert_root(node t);
	int insert_left(string tname, node t);
	int insert_right(string tname, node t);
	double score_sum();
	double score_average();
	void print_data_inorder();
	void print_data_preorder();
	void print_data_postorder();
};

int node_insert_left(node* p, string tname, node t);
int node_insert_right(node* p, string tname, node t);
double sum_all_nodes(node* p);
void inorder_print(node* p);
void preorder_print(node* p);
void postorder_print(node* p);

int main(void)
{
	tree thetree;
	node  tmp;

	tmp.set_data("Kim", 8.1);
	thetree.insert_root(tmp);
	tmp.set_data("Lee", 6.5);
	thetree.insert_left("Kim", tmp);
	tmp.set_data("Park", 8.3);
	thetree.insert_right("Kim", tmp);
	tmp.set_data("Choi", 7.2);
	thetree.insert_left("Lee", tmp);
	tmp.set_data("Ryu", 9.0);
	thetree.insert_right("Lee", tmp);
	tmp.set_data("Cho", 7.7);
	thetree.insert_right("Park", tmp);

	cout << "Score Sum : " << thetree.score_sum() << "\n";
	cout << "Score Average : " << thetree.score_average() << "\n";

	cout << "\nInorder Traversal Result \n";
	thetree.print_data_inorder();
	cout << "\nPreorder Traversal Result \n";
	thetree.print_data_preorder();
	cout << "\nPostorder Traversal Result \n";
	thetree.print_data_postorder();

	return 0;
}

void node::set_data(string n, double s)
{
	name = n;
	score = s;
}

tree::tree()
{
	root = NULL;
	node_count = 0;
}

// 0: root가 NULL이 아님
// 1: insert root 성공
int tree::insert_root(node t)
{
	if (root != NULL)
		return 0;

	node* p;
	p = new node;
	*p = t;
	p->left = NULL;
	p->right = NULL;

	root = p;
	node_count++;

	return 1;
}

//return value
//1: insert 성공, 
//0: tname의 노드 없음, 
//-1: tname의 노드는 있으나 왼쪽 자식 노드가 NULL이 아님 
int tree::insert_left(string tname, node t)		
{
	int result;
	
	result = node_insert_left(root, tname, t);

	if (result == 1)
		node_count++;

	return result;
}

//return value
//1: insert 성공, 
//0: tname의 노드 없음, 
//-1: tname의 노드는 있으나 왼쪽 자식 노드가 NULL이 아님 
int node_insert_left(node* p, string tname, node t)
{
	int result;

	if (p == NULL)
		return 0;

	if (p->name == tname)
	{
		if (p->left != NULL)
			return -1;

		node* tmp = new node;
		*tmp = t;
		tmp->left = NULL;
		tmp->right = NULL;

		p->left = tmp;

		return 1;
	}
	else
	{
		result = node_insert_left(p->left, tname, t);

		if (result != 0)
			return result;

		return node_insert_left(p->right, tname, t);
	}
}

//return value
//1: insert 성공, 
//0: tname의 노드 없음, 
//-1: tname의 노드는 있으나 오른쪽 자식 노드가 NULL이 아님 
int tree::insert_right(string tname, node t)
{
	int result;

	result = node_insert_right(root, tname, t);

	if (result == 1)
		node_count++;

	return result;
}

//return value
//1: insert 성공, 
//0: tname의 노드 없음, 
//-1: tname의 노드는 있으나 오른쪽 자식 노드가 NULL이 아님 
int node_insert_right(node* p, string tname, node t)
{
	int result;

	if (p == NULL)
		return 0;

	if (p->name == tname)
	{
		if (p->right != NULL)
			return -1;

		node* tmp;
		tmp = new node;

		*tmp = t;
		tmp->right = NULL;
		tmp->left = NULL;

		p->right = tmp;
		return 1;
	}
	else
	{
		result = node_insert_right(p->left, tname, t);

		if (result != 0)
			return result;

		return node_insert_right(p->right, tname, t);
	}
}

double tree::score_sum()
{
	return sum_all_nodes(root);
}

double sum_all_nodes(node* p)
{
	if (p == NULL)
		return 0;

	return (sum_all_nodes(p->left) + sum_all_nodes(p->right) + p->score);
}

double tree::score_average()
{
	return (sum_all_nodes(root) / node_count);
}

void tree::print_data_inorder()
{
	inorder_print(root);
}

void inorder_print(node* p)
{
	if (p == NULL)
		return;

	inorder_print(p->left);
	cout << p->name << " : " << p->score << endl;
	inorder_print(p->right);
}

void tree::print_data_preorder()
{
	preorder_print(root);
}

void preorder_print(node* p)
{
	if (p == NULL)
		return;

	cout << p->name << " : " << p->score << endl;
	preorder_print(p->left);
	preorder_print(p->right);
}

void tree::print_data_postorder()
{
	postorder_print(root);
}

void postorder_print(node* p)
{
	if (p == NULL)
		return;

	postorder_print(p->left);
	postorder_print(p->right);
    cout << p->name << " : " << p->score << endl;
}
