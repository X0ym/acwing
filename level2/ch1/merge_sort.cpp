#include<iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N], tmp[N];

/*
归并排序 - 分治思想
算法步骤：
1. 确定分界点 mid = (l + r) / 2
2. 递归处理左右两边：处理左右两边，使得左右两边有序
3. 归并 - 合二为一

归并排序 
*/

void merge(int q[], int l, int r)
{
    int mid = l + r >> 1;
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];

    // 
    for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];
}

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    merge(q, l, r);
}


int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    
    merge_sort(q, 0, n - 1);
    
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
}