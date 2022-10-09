#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;

int h[N], s;
int n,m;

// 时间复杂度 O(log N)
void down (int u) 
{
    int t = u;
    if (u * 2 <= s && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        swap(h[u] , h[t]);
        down(t);
    }
}

// 时间复杂度 O(log N)
void up (int u) 
{
    while (u / 2 > 0 && h[u] < h[u / 2]) 
    {
        swap(h[u],h[u / 2]);
        u = u / 2;
    }
}

int main ()
{
    
    
    return 0;
}