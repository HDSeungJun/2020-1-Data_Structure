#include <iostream>
using namespace std;

class node
{
public:
	string name;
	double score;
	node* link;
	void set_data(string s, double n);
};

class my_stack
{
	node* head, * tail;
	
public:
	my_stack();
	void push(node t);
	//void add_to_tail(node t);
	node pop();
	bool list_empty();
};

int main(void)
{
	my_stack        a;

	node tmp;

	tmp.set_data("KIM", 22.2);

	a.push(tmp);

	tmp.set_data("LEE", 33.3);

	a.push(tmp);

	tmp.set_data("PARK", 44.4);

	a.push(tmp);

	tmp.set_data("CHOI", 55.5);

	a.push(tmp);

	tmp = a.pop();

	cout << tmp.name << " : " << tmp.score << "\n";

	tmp = a.pop();

	cout << tmp.name << " : " << tmp.score << "\n";

	return 0;
}

void node::set_data(string s, double n)
{
	name = s;
	score = n;
}

my_stack::my_stack()
{
	head = NULL;
	tail = NULL;
}

void my_stack::push(node t)
{
	node* new_node;
	new_node = new node;

	*new_node = t;

	new_node->link = head;
	head = new_node;

	if (tail == NULL)
		tail = new_node;
}
/*
void my_stack::add_to_tail(node t)
{
	node* new_node;
	new_node = new node;

	*new_node = t;
	new_node->link = NULL;

	if (tail != NULL)
		tail->link = new_node;
	else
		head = new_node;
	tail = new_node;
}
*/

node my_stack::pop()
{
	node* t = head;
	node temp = *head;

	head = head->link;
	delete t;

	if (head == NULL)
		tail = NULL;

	return temp;
}

bool my_stack::list_empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}