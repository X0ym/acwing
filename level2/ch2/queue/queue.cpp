#include <iostream>

using namespace std;

/*
hh 表示队头，tt 表示队尾
hh <= tt 队列不为空
*/
const int N = 1e5 + 10;
int q[N], hh = 0, tt = -1;

// 队尾入队
void push_back(int x)
{
    q[++tt] = x;
}

// 队头出队
int pop_front()
{
    return q[hh++];
}

// 取队首
int front()
{
    return q[hh];
}

bool empty()
{
    return hh > tt;
}

int main()
{

    return 0;
}