class Solution {
public:
    bool isPalindrome(string s)
    {
        int i = 0,j = s.size() - 1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        //Brute Force Approach : Time - O(n^2)
        if(isPalindrome(s))
            return true;
        // else
        // {
        //     for(int i = 0;i<s.size();++i)
        //     {
        //         string temp = s;
        //         s.erase(i,1);
        //         if(isPalindrome(s))
        //             return true;
        //         s = temp;
        //     }
        // }
        
        //Better Approach 
        int n = s.size();
        int i = 0,j = n-1;
        while(i<j)
        {
            if(s[i] == s[j])
            {
                ++i;
                --j;
            }
            else
            {
                if(s[j-1] == s[i])
                {
                    string temp = s;
                    s.erase(j,1);
                    if(isPalindrome(s))
                        return true;
                    s = temp;
                }
                if(s[i+1] == s[j])
                {
                    string temp = s;
                    s.erase(i,1);
                    if(isPalindrome(s))
                        return true;
                    s = temp;
                }
                return false;
            }
        }
        return false;
       
    }
};