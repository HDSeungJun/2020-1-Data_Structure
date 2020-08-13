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

class my_list
{
	node* head, * tail;

public:
	my_list();
	void add_to_head(node t);
	void add_to_tail(node t);
	node delete_from_head();
	int num_nodes();
	bool list_empty();
	double score_sum();
	double get_score(string t_name);
	int remove_a_node(string t_name);
	void invert();
	friend bool list_equal(my_list a, my_list b);
};

bool is_equal(node* a, node* b);
bool equal_data(node a, node b);

int main(void)
{
	my_list    a, b;

	node   tmp;

	tmp.set_data("Kim", 83.5);

	a.add_to_head(tmp);

	tmp.set_data("Lee", 78.2);

	a.add_to_head(tmp);

	tmp.set_data("Park", 91.3);

	a.add_to_head(tmp);

	tmp.set_data("Choi", 85.1);

	a.add_to_head(tmp);

	tmp.set_data("Choi", 85.1);

	b.add_to_head(tmp);

	tmp.set_data("Park", 91.3);

	b.add_to_head(tmp);

	tmp.set_data("Lee", 78.2);

	b.add_to_head(tmp);

	tmp.set_data("Kim", 83.5);

	b.add_to_head(tmp);

	b.invert();

	if (list_equal(a, b))

		cout << "Yes, the two lists are identical. \n";

	else

		cout << "No, They are not identical.\n";

	tmp = b.delete_from_head();

	cout << tmp.name << " : " << tmp.score << "\n";

	return 0;
}

void node::set_data(string s, double n)
{
	name = s;
	score = n;
}

my_list::my_list()
{
	head = NULL;
	tail = NULL;
}

void my_list::add_to_head(node t)
{
	node* new_node;
	new_node = new node;

	*new_node = t;

	new_node->link = head;
	head = new_node;

	if (tail == NULL)
		tail = new_node;
}

void my_list::add_to_tail(node t)
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

node my_list::delete_from_head()
{
	node* t = head;
	node temp = *head;

	head = head->link;
	delete t;

	if (head == NULL)
		tail = NULL;

	return temp;
}

int my_list::num_nodes()
{
	int count = 0;
	node* t = head;

	while (t != NULL)
	{
		t = t->link;
		count++;
	}

	return count;
}

bool my_list::list_empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

double my_list::score_sum()
{
	double sum = 0.0;
	node* t = head;

	while (t != NULL)
	{
		sum += t->score;
		t = t->link;
	}

	return sum;
}

double my_list::get_score(string t_name)
{
	node* t = head;

	while (t != NULL)
	{
		if (t_name == t->name)
			break;
		t = t->link;
	}

	return t->score;
}

int my_list::remove_a_node(string t_name)
{
	node* t = head;
	node* h = t;

	while (t != NULL)
	{
		if (t_name == t->name)
			break;
		h = t;
		t = t->link;
	}

	if (t == NULL)
		return 0;

	h->link = t->link;
	delete t;

	return 1;
}

void my_list::invert()
{
	node* new_head = NULL;
	node* old_head = head;
	node* temp;

	do
	{
		temp = new_head;
		new_head = old_head;
		old_head = old_head->link;
		new_head->link = temp;
	} while (old_head != NULL);

	tail = head;
	head = new_head;
}

bool list_equal(my_list a, my_list b)
{
	return is_equal(a.head, b.head);
}

bool is_equal(node* a, node* b)
{
	if (a == NULL && b == NULL)
		return true;
	else if (a == NULL || b == NULL)
		return false;
	else if (equal_data(*a, *b))
		is_equal(a->link, b->link);
}

bool equal_data(node a, node b)
{
	if (a.name != b.name)
		return false;
	else if (a.score != b.score)
		return false;

	return true;
}
