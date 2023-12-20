#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
// 下标0是根节点且为空节点，cnt 记录以该节点结尾的单词数
int son[N][26], cnt[N], idx; // 数组模拟链表
char str[N];

void insert(string str)
{
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string op, str;
        cin >> op >> str;
        if (op == "Q")
            cout << query(str) << endl;
        else
            insert(str);
    }
    return 0;
}