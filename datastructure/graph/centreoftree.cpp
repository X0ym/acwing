#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx; // 邻接表结构
bool st[N]; // 标记数组
int ans;

// 返回以 u 为根的子树中点的数量
int dfs (int u)
{
    st[u] = true; // 标记节点

    int sum = 1, res = 0; // res 存除该节点外 各连通块的节点数量的最大值，sum记录该节点上面的点数
    for (int i = h[u]; i != -1 ; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) 
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }

    // 比较该节点上的部分
    res = max(res, n - sum);

    ans = min(ans, res);
    return sum;
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
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0;i < n - 1; i ++)
    {
        int a, b;
        cin >> a >> b;
        add(a,b),add(b,a); // 加入无向边 a -> b , b -> a
    }

    dfs(1); // 以节点1为根
    cout << ans << endl;
    return 0;
}