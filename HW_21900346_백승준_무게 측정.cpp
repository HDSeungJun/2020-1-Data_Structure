#include <iostream>
using namespace std;

class weight
{
	int kilogram;
	int gram;
public:
	void set_weight(int k, int g);
	int get_weight();
};

weight add_weight(weight w1, weight w2);
bool less_than(weight w1, weight w2);

int main(void)
{
	weight w1, w2, w3;

	w1.set_weight(3, 400);
	w2.set_weight(2, 700);
	w3 = add_weight(w1, w2);

	cout << w3.get_weight() << "grams\n";

	if (less_than(w1, w2))
		cout << "yes.\n";
	else
		cout << "no. \n";

	return 0;
}

void weight::set_weight(int k, int g)
{
	kilogram = k;
	gram = g;
}

int weight::get_weight()
{
	return kilogram * 1000 + gram;
}

weight add_weight(weight w1, weight w2)
{
	weight w;

	w.set_weight(0, w1.get_weight() + w2.get_weight());

	return w;
}

bool less_than(weight w1, weight w2)
{
	if (w1.get_weight() < w2.get_weight())
		return true;
	else
		return false;
}
