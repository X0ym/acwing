#include<iostream>
using namespace std;

const int N = 10;

int n,path[N];
bool st[N]; // true表示该数已经用过了
    
void dfs (int u) 
{
    if (u == n)
    {
        // 遍历到第 n 个位置，输出即可
        for (int i = 0;i < n;i ++) printf("%d", path[i]);
        puts("");
        return;
    }
    
    for (int i = 1;i <= n;i ++) {
        if (!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1); // 递归到最深处
            st[i] = false; // 恢复现场
        }
    }
}

int main ()
{
    scanf("%d", &n);
    
    dfs(0);
    return 0;
}
