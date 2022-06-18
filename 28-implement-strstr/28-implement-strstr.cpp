class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int nsize = needle.size();
        if(!nsize)
            return 0;
        if(nsize > haystack.size())
            return -1;
        for(int i = 0;i<=haystack.size()-nsize;++i)
        {
            if(haystack.substr(i,nsize) == needle)
                return i;
        }
        return -1;
    }
};