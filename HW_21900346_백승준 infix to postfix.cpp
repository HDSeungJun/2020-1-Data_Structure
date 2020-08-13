// 1. Infix to Postfix
#include <iostream>
#include <string>
using namespace std;

#define SIZE    100
#define EOS     '$'       

class op_stack
{
    char s[SIZE];
    int top;

public:
    op_stack();
    void push(char x);
    char pop();
    bool stack_full();
    bool stack_empty();
    char top_element();
};

class infix_to_postfix : public op_stack
{
public:
    bool is_operand(char ch);
    int get_precedence(char op);
};

int main()
{
    string input, output;
    infix_to_postfix itp;
    int i;
    char token;

    cout << "Input an Infix expression to convert: ";
    cin >> input;

    itp.push(EOS);
    for (i = 0; i < input.size(); i++)
    {
        token = input[i];

        if (itp.is_operand(token))
            output += token;
        else
        {
            if (token == '(')
                itp.push(token);
            else if (token == ')')
            {
                while (itp.top_element() != '(')
                {
                    output += itp.pop();
                }
                itp.pop();
            }
            else
            {
                while (itp.get_precedence(itp.top_element()) >= itp.get_precedence(token))
                    output += itp.pop();
                itp.push(token);
            }
        }
    }

    if (!itp.stack_empty())
        while (itp.top_element() != EOS)
            output += itp.pop();

    cout << output << endl;

    return 0;
}

op_stack::op_stack()
{
    top = 0;
}

void op_stack::push(char x)
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

char op_stack::pop()
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

bool op_stack::stack_full()
{
    if (top >= SIZE)
        return true;
    else
        return false;
}

bool op_stack::stack_empty()
{
    if (top == 0)
        return true;
    else
        return false;
}

char op_stack::top_element()
{
    return s[top - 1];
}

bool infix_to_postfix::is_operand(char ch)
{
    if (ch == '(' || ch == ')' ||
        ch == '+' || ch == '-' ||
        ch == '*' || ch == '/' ||
        ch == '%' || ch == '$')
        return false;
    else
        return true;
}

int infix_to_postfix::get_precedence(char op)
{
    if (op == '$' || op == '(')
        return 0;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
}