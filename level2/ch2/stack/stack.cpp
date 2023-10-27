#include <iostream>

using namespace std;

/*
stack

FILO

数组模拟栈

*/

const int N = 1e5 + 10;
int stk[N];
int tt; // 栈顶下标，栈底默认为0

//
void push(int x)
{
    stk[++tt] = x;
}

int pop()
{
    return stk[tt--];
}

bool isEmpty()
{
    if (tt > 0)
        return false;
    else
        return true;
}

int peek()
{
    return stk[tt];
}

int main()
{
    push(1); // 1
    cout << tt << endl;
    push(2); // 1 2
    cout << tt << endl;

    cout << "stk empty()= " << isEmpty() << endl;
    cout << "stk peek()= " << peek() << endl;
    pop(); // 1
    cout << tt << endl;

    cout << "stk empty()= " << isEmpty() << endl;
    cout << "stk peek()= " << peek() << endl;

    cout << "stk pop()= " << pop() << endl;
    cout << "stk empty()= " << isEmpty() << endl;

    return 0;
}