#include<bits/stdc++.h>
using namespace std;
void printDuplicates(string s)
{
    //Time - O(2*n),Space - O(n)
    unordered_map<char,int> mp;
    for(auto &ch : s)
    mp[ch]++;
    for(int i = 0;i<s.size();++i)
    {
        if(mp[s[i]] >= 2)
        {
            cout<<s[i]<<" count - "<<mp[s[i]]<<endl;
            mp[s[i]] = 0;
        }
    }
}
int main()
{
    string str = "string check";
    printDuplicates(str);
    return 0;
}
