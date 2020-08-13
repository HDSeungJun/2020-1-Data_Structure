#include <iostream>
using namespace std;

#define HSIZE 100

class element
{
public:
	string name;
	double score;

	void set_data(string n, double s);
};

class my_heap
{
	element h[HSIZE];
	int csize;
	void adjust(int t_root);

public:
	my_heap();
	my_heap(element a[], int n);
	int h_size();
	void insert_heap(element t);
	element delete_heap();
	bool heap_full();
	bool heap_empty();
	double score_sum();
	double score_average();
	int node_delete_by_name(string name);
};

double summation(element a[], int troot, int n);
int delete_node(element a[], int troot, string tname, int n);
void heap_adjust(element a[], int troot, int size);


void element::set_data(string n, double s)
{
	name = n;
	score = s;
}

my_heap::my_heap()
{
	csize = 0;
}
my_heap::my_heap(element a[], int n)
{
	int k;

	for (k = 1; k <= n; k++)
		h[k] = a[k - 1];
	csize = n;

	for (k = n / 2; k >= 1; k--)
		adjust(k);
}
bool my_heap::heap_empty()
{
	return (csize == 0);
}
bool my_heap::heap_full()
{
	return (csize >= HSIZE - 1);
}
int my_heap::h_size()
{
	return csize;
}
void my_heap::insert_heap(element t)
{
	int k;

	csize++;
	k = csize;

	while ((k != 1) && (t.score > h[k / 2].score))
	{
		h[k] = h[k / 2];
		k /= 2;
	}
	h[k] = t;
}
element my_heap::delete_heap()
{
	element t;
	element tmp;
	int parent, child;

	t = h[1];
	tmp = h[csize--];
	parent = 1;
	child = 2;

	while (child <= csize)
	{
		if ((child < csize) && (h[child].score < h[child + 1].score))
			child++;
		if (tmp.score >= h[child].score)
			break;

		h[parent] = h[child];
		parent = child;
		child *= 2;
	}
	h[parent] = tmp;

	return t;
}
void my_heap::adjust(int t_root)
{
	double tmpkey;
	int child;
	element tmp;

	tmp = h[t_root];
	tmpkey = h[t_root].score;
	child = t_root * 2;

	while (child <= csize)
	{
		if ((child < csize) && (h[child].score < h[child + 1].score))
			child++;
		if (tmpkey > h[child].score)
			break;

		h[child / 2] = h[child];
		child *= 2;

	}
	h[child / 2] = tmp;
}

double my_heap::score_sum()
{
	return summation(h, 1, csize);
}
double summation(element a[], int troot, int n)
{
	if (troot > n)
		return 0;

	return (a[troot].score + summation(a, 2 * troot, n) + summation(a, 2 * troot + 1, n));
}

double my_heap::score_average()
{
	if (csize == 0)
		return 0;

	return score_sum() / csize;
}

int my_heap::node_delete_by_name(string tname)
{
	if (csize == 0)
		return 0;

	if (delete_node(h, 1, tname, csize) == 1)
	{
		csize--;
		return 1;
	}

	return 0;
}

int delete_node(element a[], int troot, string tname, int n)
{
	if (troot > n)
		return 0;

	if (a[troot].name == tname)
	{
		a[troot] = a[n];
		n--;
		heap_adjust(a, troot, n);

		return 1;
	}
	else
	{
		if (delete_node(a, 2 * troot, tname, n))
			return 1;
		else
			return delete_node(a, 2 * troot + 1, tname, n);
	}
}
void heap_adjust(element a[], int troot, int size)
{	
	double tmpkey;
	int child;
	element tmp;

	tmp = a[troot];
	tmpkey = a[troot].score;
	child = troot * 2;

	while (child <= size)
	{
		if ((child < size) && (a[child].score < a[child + 1].score))
			child++;
		if (tmpkey > a[child].score)
			break;

		a[child / 2] = a[child];
		child *= 2;

	}
	a[child / 2] = tmp;
}

int main(void)
{
	element      a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85} };
	my_heap   h1(a, 6);
	element temp;

	cout << "Number of nodes : " << h1.h_size() << endl;
	cout << "Score Sum = " << h1.score_sum() << endl;
	cout << "Score average = " << h1.score_average() << endl;
	h1.node_delete_by_name("Kim");
	cout << "\n-- After the deletion operation. --\n\n";
	cout << "Number of nodes : " << h1.h_size() << endl;
	cout << "Score Sum = " << h1.score_sum() << endl;
	cout << "Score average = " << h1.score_average() << endl;
	while (h1.h_size() > 0) {
		temp = h1.delete_heap();
		cout << temp.name << " : " << temp.score << "\n";
	}
	return 0;
}