#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);

    return;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}

/*

快速排序思想：
    1. 在待排序表 p[1...n] 中确定分界点 x ：可选左端点，中间点，右端点，或者随机选取分界点
    2. 调整区间（一般 partition 函数）：使得 p[1...k-1] 都是小于x 的，p[k+1...n] 都是大于等于 x 的
    3. 递归处理左右两段，直至每部分内只有一个元素或为空为止


快排不稳定，想要稳定可以让排序的元素都不相同，如果元素都相同，可以让元素
均不同即可，比如使用 pair

*/