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
	void peek();
	bool list_empty();
};

class menu_stack
{
public:
	int select_menu();
	void push(my_stack& stack);
	void pop(my_stack& stack);
	void peek(my_stack stack);
};

int main(void)
{
	int menu;
	int count = 0;
	menu_stack m;
	my_stack stack;

	do
	{
		menu = m.select_menu();

		switch (menu)
		{
		case 1:
			m.push(stack);
			count++;
			break;
		case 2:
			if (count > 0)
			{
				m.pop(stack);
				count--;
			}
			else
				cout << "No saved data!" << endl;
			break;
		case 3:
			if (count > 0)
				m.peek(stack);
			else
				cout << "No saved data!" << endl;
			break;
		case 4:
			cout << "Bye~" << endl;
			break;
		default:
			continue;
		}
	} while (menu != 4);
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

void my_stack::peek()
{
	cout << "Name : " << head->name << endl;
	cout << "Score : " << head->score << endl;
}

int menu_stack::select_menu()
{
	int menu;

	cout << "=================" << endl;
	cout << "[ MENU ]" << endl;
	cout << "1. PUSH" << endl;
	cout << "2. POP" << endl;
	cout << "3. PEEK" << endl;
	cout << "4. QUIT" << endl;
	cout << "=================" << endl;

	cout << "\nSelet a command : ";
	cin >> menu;

	return menu;
}

void menu_stack::push(my_stack& stack)
{
	string tname;
	int tscore;
	node new_node;

	cout << "Name : ";
	cin >> tname;
	cout << "Score : ";
	cin >> tscore;
	new_node.set_data(tname, tscore);

	stack.push(new_node);
}

void menu_stack::pop(my_stack& stack)
{
	node r_node;
	r_node=stack.pop();

	cout << "Name : " << r_node.name << endl;
	cout << "Score : " << r_node.score << endl;
}

void menu_stack::peek(my_stack stack)
{
	stack.peek();
}