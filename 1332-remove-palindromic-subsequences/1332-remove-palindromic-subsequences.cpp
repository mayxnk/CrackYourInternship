class Solution {
public:
    bool isPalindrome(string s,int i , int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int removePalindromeSub(string s) 
    {
        if(s.size()==0)
            return 0;
        if(isPalindrome(s,0,s.size()-1))
            return 1;
        else
            return 2;
        //String will always contain two palindromic subsequence if there
        //are only two characters in it,one containing all a and other all b
        
    }
};