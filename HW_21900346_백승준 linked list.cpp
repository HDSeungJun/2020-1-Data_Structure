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
};

int main(void)
{
	my_list    a;
	node   tmp;
	tmp.set_data("Kim", 83.5);
		a.add_to_head(tmp);
	tmp.set_data("Lee", 78.2);
		a.add_to_head(tmp);           // head 위치로 2개의 원소 추가
	cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검
	tmp.set_data("Park", 91.3);  
		a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
	cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검
	tmp = a.delete_from_head();
	cout << tmp.name << " is deleted.\n";   // 3단계 점검
	tmp.set_data("Choi", 85.1);  
		a.add_to_tail(tmp);
	tmp.set_data("Ryu", 94.3);  
		a.add_to_head(tmp);             // 2개의 원소 추가

	cout << a.num_nodes() << " : " << a.score_sum() << "\n";
	cout << "Park’s score : " << a.get_score("Park") << "\n";  // 4단계 점검
	if (a.remove_a_node("Kim") == 1)
		cout << "Kim is deleted from the list. \n";     // 5단계 점검
	cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 최종 점검      
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
