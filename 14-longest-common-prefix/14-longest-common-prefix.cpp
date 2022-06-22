class Solution {
public:
    string longestCommonPrefix(vector<string>& str) 
    {
        sort(str.begin(),str.end());
        
        string ans = "";
        string a = str[0],b = str[str.size()-1];
        
        for(int i = 0;i<a.size();++i)
        {
            if(a[i] == b[i])
                ans += a[i];
            else
                break;
        }
        return ans;
    }
};