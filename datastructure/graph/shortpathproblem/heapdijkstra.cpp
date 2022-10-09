#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 150010;

typedef pair<int, int> PII;

int n, m;      // n为点的数量
int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储所有边 w为权重
int dist[N];        // 存储所有点到1号点的距离
bool st[N];     // 存储每个点的最短距离是否已确定

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

/*
朴素Dijkstra算法
        1. 初始化距离和已确定最短距离集合S（用bool数组st[N]表示，全为false),dist[1] = 0,dist[i] = INF
        2. N次迭代 for (int i = 0; i < n; i ++)
            2.1 int t = 找到不在S中距离最近的点           O(N)    --- 堆优化 找最小的数 
            2.2 t 加入集合S : st[t] = true              O(1)
            2.3 用t更新其他点的距离  时间复杂度取决于t的边   O(M)        O(MlogM)
                for (int j = 1;j <= n; j ++) {
                    dist[j] = min(dist[j], dist[t] + g[t][j])
*/

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});      // first存储距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    
    //初始化
    memset(h, -1, sizeof h);
    
    while (m --) 
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c); // 不处理重边
    }
    
    int t = dijkstra();
    
    printf("%d\n", t);
    
    return 0;
}