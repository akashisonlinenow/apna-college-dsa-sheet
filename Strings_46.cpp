// using hashmap method
#include <bits/stdc++.h>
using namespace std;

void printdups(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > 1)
            cout << it.first << "count=" << it.second << endl;
    }
}

int main()
{
    string str = "hii hello bye";
    printdups(str);
    return 0;
}