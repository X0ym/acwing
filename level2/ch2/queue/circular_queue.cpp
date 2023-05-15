#include<iostream>

using namespace std;

/*

hh 表示队头，tt 表示队尾后的一个位置

*/

const int N = 1e5 + 10;
int q[N], hh = 0, tt = 0;

void push_back(int x)
{
    q[tt ++];
    if (tt == N) tt = 0;
}

int pop_front()
{
    // 队列不为空，出队
    if (hh != tt) {
        q[hh ++];
        if (hh == N) hh = 0;
    }
}

int front()
{
    return q[hh];
}

bool empty()
{
    return hh == tt;
}

int main()
{

    return 0;
}