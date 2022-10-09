#include<iostream>
#include<algorithm>
#include<cstring>
//#include<queue>

using namespace std;

const int N = 110;
typedef pair<int,int> PII;

int n,m;
int g[N][N];// 存地图
int d[N][N];// 到起点的距离 , 初始为 -1，即还未访问过
PII q[N * N];
PII Prev[N][N]; // 记录路径

int bfs () 
{
    int hh = 0,tt = 0;
    q[0] = {0,0};
    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (hh <= tt)
    {
        auto t = q[hh ++]; // 出队
        // 上下左右四个方向
        for (int i = 0;i < 4;i ++)
        {
            // 得到四个方向下一步的坐标
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                Prev[x][y] = t;
                q[++ tt] = {x,y}; // 下一步坐标进队
            }
        }
    }

    // 输出路径
    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << ' ' << y << endl;
        auto t = Prev[x][y];
        x = t.first , y = t.second;
    }

    return d[n - 1][m - 1];
}

int main ()
{
    cin >> n >> m;
    for (int i = 0;i < n;i ++)
        for (int j = 0;j < m;j ++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}