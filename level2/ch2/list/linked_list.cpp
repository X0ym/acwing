#include<iostream>

using namespace std;

/*

head    表示头节点，不存储信息

e[N]    实际存储数据的结构，每个元素通过下标在 ne[N] 中其找到下一个节点
ne[N]   表示链表中节点的下一个节点下标
idx     表示实际存储数据的数组下一个可存放数据的下标

*/
const int N = 1e5 + 10;
int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

// 插入头节点 head 后
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

// 插入到下标为 k 的结点后
void insert(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

// 移除下标为 k 的节点
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{

    return 0;
}