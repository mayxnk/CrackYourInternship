class Solution {
public:
    bool checkvalid(string s)
    {
        // stack<char> ch;
        // for(int i = 0;i<s.size();++i)
        // {
        //     if(s[i] == '(')
        //         ch.push(s[i]);
        //     else if(s[i] == ')' and ch.empty())
        //         return false;
        //     else
        //     {
        //         ch.pop();
        //     }
        // }
        // if(ch.empty())
        //     return true;
        // return false;
        bool flag = true;
        int count = 0;
        for(int i = 0;i<s.size();++i)
        {
            if(s[i] == '(')
                ++count;
            else
                --count;
            if(count < 0)
                flag = false;
        }
        if(flag and count == 0)
            return true;
        return false;
    }
//     void helper(int n,string& str,vector<string>& ans)
//     {
//         if(str.size() == (2*n))
//         {                       
//             if(checkvalid(str)) 
//                 ans.push_back(str);       
//             return;             
//         }
// //         helper(n,str + '(',ans);
        
// //         helper(n,str + ')',ans);
//         helper(n,str.append("("),ans);
//         helper(n,str.append(")"),ans);
//     }
    void helper(int n,int start,int close,string str,vector<string>& ans)
    {
        if(str.size() == (2*n))
        {
            ans.push_back(str);
            return;
        }
        if(start < n)
            helper(n,start + 1,close,str + '(',ans);
        if(close < start)
            helper(n,start,close + 1,str + ')',ans);
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string str = "";
        //helper(n,str,ans);
        int start = 0,close = 0;
        helper(n,start,close,str,ans);
        return ans;
    }
};