//
// Created by Xieym on 2022/11/1.
//
#include "iostream"

using namespace std;

/*
 *  整数二分
 *      有单调性一定可以二分，但可以二分的题不一定需要单调性
 *      二分的本质是边界，一个区间可划分为满足某条件和不满足某条件的两个区间
 *  场景1 条件A将区间 [l, r] 分为两部分，左半区间符合条件，右半区间不满足条件
 *      mid = l + r + 1 >> 1
 *      check(mid) - check mid 是否满足条件A
 *          - true 分界点在 [mid, r] l = mid
 *          - false 分界点在 [l, mid -  1] r = mid - 1
 *
 *      分界点在
 *  场景2 条件B将区间 [l, r] 分为两部分，左半区间不满足条件，右半区间满足条件
 *      mid = l + r >> 1
 *      check(mid) - check mid 是否满足条件B
 *          - true 分界点在左半边 [l, mid] r = mid
 *          - false 分界点在右半边 [mid + 1, r] l = mid + 1
 *
 *
 */

bool check_right(int q[], int mid)
{

}

int b_search_1(int q[], int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check_right(q, mid)) r = mid;
        else l  = mid + 1;
    }
    return l;
}

int main()
{

}