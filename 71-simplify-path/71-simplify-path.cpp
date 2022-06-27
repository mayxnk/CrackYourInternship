class Solution {
public:
    string simplifyPath(string path) 
    {
        string str = "";
        stack<string> st;
        //Optimal Approach - Time : O(n), Space - O(1)
        
        for(int i = 0;i<path.size();++i)
        {
            if(path[i] == '/')
                continue;
            string temp;
            while(i < path.size() and path[i] != '/')//Adding until we find /
            {
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
            else if(temp == "..")
            {
                if(st.size()!=0)
                    st.pop();
            }
            else
                st.push(temp);
        }
        while(!st.empty())
        {
            str = "/" + st.top() + str;
            st.pop();
        }
        if(str.size() == 0)
            return "/";
        return str;
    }
};