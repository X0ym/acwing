#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "abcd";
    for (int i = 0; i < s.length(); i ++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << s.substr(j, i - j + 1) << endl;
        }
        
    }
    /*
        a

        ab
        b

        abc
        bc
        c
        
        abcd
        bcd
        cd
        d
    */

    for (int i = 0; i < s.length(); i ++)
    {
        for (int j = i; j < s.length(); j ++)
        {
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
    /*
        a
        ab
        abc
        abcd

        b
        bc
        bcd

        c
        cd

        d
    */

    return 0;
}