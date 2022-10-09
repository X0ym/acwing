#include <iostream>
using namespace std;

const int N = 10010;
int son[N][26],cnt[N],idx;//下标0是根节点且为空节点，cnt 记录以该节点结尾的单词数
char str[N];

void insert (string str)
{
    int p = 0;
    for (int i = 0; i < str.size() ; i ++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query (string str)
{
    int p = 0;
    for (int i = 0; i < str.size() ; i ++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main () 
{   
    insert("ababb");
    insert("ab");
    insert("ab");
    printf("%d\n",query("a"));
    printf("%d",query("ab"));
}