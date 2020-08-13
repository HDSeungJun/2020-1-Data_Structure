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

    void nonrecursive_inorder();
    void print_data_levelorder();
};

int node_insert_left(node* p, string tname, node t);
int node_insert_right(node* p, string tname, node t);
double sum_all_nodes(node* p);
void inorder_print(node* p);
void preorder_print(node* p);
void postorder_print(node* p);
void copy_tree(tree& t1, tree t2);
node* make_copy(node* p);
bool equal_tree(tree t1, tree t2);
bool equal_test(node* p1, node* p2);

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

    cout << "\nNon-recursive Inorder Result \n";
        thetree.nonrecursive_inorder();
    cout << "\nLevel-Order traversal Result \n";
        thetree.print_data_levelorder();

    tree tree2;
    copy_tree(tree2, thetree);
    cout << "\nThe inorder traversal Result of the new tree \n";
    tree2.print_data_inorder();
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else
        cout << "No\n";
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

class s_node
{
public:
    node* data;
    s_node* link;
};

class my_stack
{
    s_node* top;

public:
    my_stack();
    void push(node* t);
    node* pop();
    bool stack_empty();
};

class q_node
{
public :
    node* data;
    q_node* link;
};

class my_queue
{
    q_node* front, * rear;

public:
    my_queue();
    void insert_q(node* t);
    node* delete_q();
    bool queue_empty();
};

my_queue::my_queue()
{
    front = NULL;
    rear = NULL;
}

void my_queue::insert_q(node* t)
{
    q_node* new_node = new q_node;

    new_node->data = t;
    new_node->link = NULL;

    if (rear != NULL)
        rear->link = new_node;
    else
        front = new_node;
    rear = new_node;
}

node* my_queue::delete_q()
{
    q_node* t = front;
    node* temp = t->data;

    front = front->link;
    delete[] t;

    if (front == NULL)
        rear = NULL;

    return temp;
}

bool my_queue::queue_empty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

my_stack::my_stack()
{
    top = NULL;
}

void my_stack::push(node* t)
{
    s_node* new_node = new s_node;

    new_node->data = t;

    if (top == NULL)
        new_node->link = NULL;
    new_node->link = top;

    top = new_node;
}

node* my_stack::pop()
{
    s_node* t = top;
    node* temp = t->data;

    top = top->link;

    delete[] t;

    return temp;
}

bool my_stack::stack_empty()
{
    if (top == NULL)
        return true;
    else
        return false;
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
    return (sum_all_nodes(root) / node_count + 1);
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

void tree::nonrecursive_inorder()
{
    my_stack s = my_stack();
    node* t;

    t = root;
    while (1)
    {
        while (t != NULL)
        {
            s.push(t);
            t = t->left;
        }
        while (t == NULL)
        {
            if (s.stack_empty())
                return;
            t = s.pop();
        }

        cout << t->name << " : " << t->score << endl;
        t = t->right;
    }
}

void tree::print_data_levelorder()
{
    my_queue q;
    node* t;

    if (root == NULL)
        return;
    q.insert_q(root);
    while (1)
    {
        if (q.queue_empty())
            return;
        t = q.delete_q();
        cout << t->name << " : " << t->score << endl;

        if (t->left != NULL)
            q.insert_q(t->left);
        if (t->right != NULL)
            q.insert_q(t->right);
    }
}
void copy_tree(tree& t1, tree t2)
{
    t1.node_count = t2.node_count;
    t1.root = make_copy(t2.root);
}
node* make_copy(node* p)
{
    node* t;

    if (p == NULL)
        return NULL;

    t = new node;
    *t = *p;
    t->left = make_copy(p->left);
    t->right = make_copy(p->right);

    return t;
}

bool equal_tree(tree t1, tree t2)
{
    if (t1.node_count != t2.node_count)
        return false;
    return equal_test(t1.root, t2.root);
}

bool equal_test(node* p1, node* p2)
{
    if ((p1 == NULL) && (p2 == NULL))
        return true;
    if (p1 == NULL)
        return false;
    if (p2 == NULL)
        return false;
    if (p1->name != p2->name)
        return false;
    if (p1->score != p2->score)
        return false;

    if (equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right))
        return true;
    else
        return false;
}