// 3. 주어진 string이 palindrome(좌우대칭) 여부를 판단하는 프로그램
#include <iostream>
#include <string>
using namespace std;

#define   SIZE   100

class mystack
{
    char s[SIZE];
    int top;

public:
    mystack();
    void push(char x);
    char pop();
    bool stack_full();
    bool stack_empty();
};

int main()
{
    mystack s1;

    string str;
    bool check = false;
    int i;

    cout << "Palindrome check: ";
    cin >> str;

    if (str.size() % 2 == 0)
    {
        for (i = 0; i < str.size() / 2; i++)
        {
            s1.push(str[i]);
        }
        for (i = str.size() / 2; i < str.size(); i++)
        {
            if (str[i] == s1.pop())
                check = true;
            else
            {
                check = false;
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < (str.size() / 2); i++)
        {
            s1.push(str[i]);
        }
        for (i = str.size() / 2 + 1; i < str.size(); i++)
        {
            if (str[i] == s1.pop())
                check = true;
            else
            {
                check = false;
                break;
            }
        }
    }

    if (check)
        cout << "Palindrome!";
    else
        cout << "Not palindrome!";

    return 0;
}

mystack::mystack()
{
    top = 0;
}

void mystack::push(char x)
{
    if (stack_full())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        s[top] = x;
        top++;
    }
}

char mystack::pop()
{
    if (stack_empty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        top--;
        return s[top];
    }
}

bool mystack::stack_full()
{
    if (top >= SIZE)
        return true;
    else
        return false;
}

bool mystack::stack_empty()
{
    if (top == 0)
        return true;
    else
        return false;
}