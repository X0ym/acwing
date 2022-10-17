#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

// 
int partition(int q[], int l, int r) 
{
    int pivot = q[l + r >> 1];
    swap(q[l], q[l + r >> 1]);

    int i = l;
    for (int j = l + 1; j <= r; j ++) 
    {
        if (q[j] < pivot) 
        {
            swap(q[++ i], q[j]);
        }
    }
    swap(q[l], q[i]);
    return i;
}

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int j = partition(q, l, r);
    
    /*
    
        递归处理时
            1）递归 q[l,j] 和 q[j + 1, r] 时，分区函数的返回值不能取到右端点
            不然递归左半部分时，无限递归
            2）递归  q[l, j - 1] 和 q[j, r] 时，分区函数返回值不能取到左

    */
    quick_sort(q, l, j - 1);
    quick_sort(q, j + 1, r);

    return;
}

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n ; i ++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);
    
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    
    return 0;
}