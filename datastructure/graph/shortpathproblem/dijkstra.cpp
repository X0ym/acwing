#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N]; // 邻接矩阵
int dist[N]; // 记录距离
bool st[N]; // 记录点的最短路径是否已经确定

/*
    朴素Dijkstra算法
        1. 初始化距离和已确定最短距离集合S（用bool数组st[N]表示，全为false),dist[1] = 0,dist[i] = INF
        2. N次迭代 for (int i = 0; i < n; i ++)
            2.1 int t = 找到不在S中距离最近的点           O(N)    --- 堆优化 找最小的数 
            2.2 t 加入集合S : st[t] = true              O(1)
            2.3 用t更新其他点的距离  时间复杂度取决于t的边   O(M) 
                for (int j = 1;j <= n; j ++) {
                    dist[j] = min(dist[j], dist[t] + g[t][j])
*/

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; // 1 到 n 
    
    for (int i = 0;i < n; i ++)
    {
        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) 
                t = j;        
        st[t] = true;
        if (t == n) break;

        for (int j = 1;j <= n; j ++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    
    //初始化
    memset(g, 0x3f, sizeof g);
    
    while (m --) 
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c); // 处理重边
    }
    
    int t = dijkstra();
    
    printf("%d\n", t);
    
    return 0;
}