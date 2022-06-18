class Solution {
public:
    bool isValid(string s) 
    {
        // if(s.size() == 1)
        //     return false;
        stack<char> check;
        
        for(int i = 0;i<s.size();++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                check.push(s[i]);
            else if((s[i] == ']' || s[i] == '}' || s[i] == ')') and check.empty())
                return false;
            else
            {
                char temp = check.top();
                check.pop();
                if(s[i] == ')' and temp != '(')
                    return false;
                else if(s[i] == '}' and temp != '{')
                    return false;
                else if(s[i] == ']' and temp != '[')
                    return false;
            }
        }
        if(check.size() != 0)
            return false;
        return true;
    }
};