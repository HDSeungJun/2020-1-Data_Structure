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

class my_queue
{
	node* head, * tail;
	
public:
	my_queue();
	//void push(node t);
	void insert_q(node t);
	node delete_q();
	bool list_empty();
};

int main(void)
{
	my_queue  a;

	node tmp;

	tmp.set_data("KIM", 22.2);

	a.insert_q(tmp);

	tmp.set_data("LEE", 33.3);

	a.insert_q(tmp);

	tmp.set_data("PARK", 44.4);

	a.insert_q(tmp);

	tmp.set_data("CHIO", 55.5);

	a.insert_q(tmp);

	tmp = a.delete_q();

	cout << tmp.name << " : " << tmp.score<< "\n";

		tmp = a.delete_q();

	cout << tmp.name << " : " << tmp.score<< "\n";

		return 0;
}

void node::set_data(string s, double n)
{
	name = s;
	score = n;
}

my_queue::my_queue()
{
	head = NULL;
	tail = NULL;
}
/*
void my_queue::push(node t)
{
	node* new_node;
	new_node = new node;

	*new_node = t;

	new_node->link = head;
	head = new_node;

	if (tail == NULL)
		tail = new_node;
}
*/

void my_queue::insert_q(node t)
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


node my_queue::delete_q()
{
	node* t = head;
	node temp = *head;

	head = head->link;
	delete t;

	if (head == NULL)
		tail = NULL;

	return temp;
}

bool my_queue::list_empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}