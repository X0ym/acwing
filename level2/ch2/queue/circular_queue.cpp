#include <iostream>

using namespace std;

/*

hh 表示队头，tt 表示队尾后的一个位置

*/

const int N = 1e5 + 10;
int q[N], hh = 0, tt = 0;

// hh = (hh + 1) % N
void push_back(int x)
{
    q[tt++];
    if (tt == N)
        tt = 0;
}

// tt = (tt + 1) % N
int pop_front()
{
    int ans;
    // 队列不为空，出队
    if (hh != tt)
    {
        ans = q[hh++];
        if (hh == N)
            hh = 0;
    }
}

int front()
{
    return q[hh];
}

int size()
{
    return (tt - hh + N) % N;
}

/**
 *
 *
 *  hh == tt 时，队列为空或队满。区分队空和队满有三种方式：
 *  1. 牺牲一个单元来区分队空和队满，入队时少用一个队列单元。
 *  2. 增加一个记录元素个数的成员。
 *      队空：size == 0, 队满：size == N，两者都存在 hh == tt
 *  3. 增加标记以区分队空还是队满
 *      因插入导致 hh==tt，则是队满，因删除导致 hh==tt，则为队空
 *
 *
 */

bool empty()
{
    return hh == tt;
}

int main()
{

    return 0;
}