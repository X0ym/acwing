#include<iostream>
using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];
    
void dfs (int u) 
{
    if (u == n)
    {
        // 遍历到第 n 个位置，输出即可
        for (int i = 0;i < n;i ++) puts(g[i]);
        puts("");
        return;
    }
    
    for (int i = 0;i < n;i ++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1); // 递归到最深处
            col[i] = dg[u + i] = udg[n - u + i] = false; // 恢复现场
            g[u][i] = '.';
        }
    }
}

int main ()
{
    scanf("%d", &n);
    for (int i = 0;i < n;i ++)
        for (int j = 0;j < n;j ++)
            g[i][j] = '.';

    dfs(0);
    
    return 0;
}