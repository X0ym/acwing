#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int h[N], e[N], ne[N], idx; // h 的下标是节点编号，值是节点在e中的下标
// e存的是节点编号，下标通过h和ne来得到
int d[N],q[N]; // d存距离，q代表队列，存节点编号，初始为节点1

void add (int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx ++;
}

int bfs ()
{
    int hh = 0, tt = 0;
    q[0] = 1; // 队列初始化

    memset(d, -1 , sizeof d);// d初始化
    d[1] = 0;

    while (hh <= tt)
    {
        int t = q[hh ++];
        for (int i = h[t]; i != -1 ; i = ne[i]) // 遍历节点t的下一层节点
        {
            int j = e[i]; // 得到节点 j
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[ ++ tt] = j; // 下一层节点 j 入队
            }
        }
    }
}

int main ()
{
    cin >> n >> m;
    memset(h, -1 ,sizeof h);

    for (int i = 0; i < m; i ++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }

    cout << bfs() << endl;

    return 0;
}