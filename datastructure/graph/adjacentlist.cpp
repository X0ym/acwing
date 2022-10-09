#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, M = N * 2;

int h[N], e[M], ne[M], idx;
bool st[N];

void dfs (int u)
{
    st[u] = true;
    for (int i = h[u]; i != -1 ; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

// 添加一条 a 到 b 的边
void add (int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int main ()
{
    memset(h, -1, sizeof h); // 初始化

    // 注释
}