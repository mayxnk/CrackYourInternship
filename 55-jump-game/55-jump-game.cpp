class Solution {
public:
    bool helper(vector<int>&nums,int i,int *mark)
    {
        if(i == nums.size()-1)
            return true;
        if(mark[i]!=-1)
            return mark[i] ;
        int maxdist = i+nums[i];
        
        for(int j = i+1;j<=maxdist;j++)
        {
            if(helper(nums,j,mark))
            {
                mark[j] = 1;
                return true;
            }
        }
        mark[i] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        if(nums[0] == 0 && n!=1)
            return false;
        if(nums[0] == n-1)
            return true;
//         unordered_map<int,int> ourmap;
//         for(int i = 0;i<n;i++)
//         {
//             if(ourmap.find(nums[i]) != ourmap.end())
//             {
//                 if(n-i == nums[i])
//                     ourmap[nums[i]] = i;
//                 continue;
//             }
//             ourmap[nums[i]] = i;
//         }
        
//         for(int i = 0;i<n;i++)
//         {
//             int val = n - nums[i];
//             if(ourmap.find(val)!=ourmap.end() && (ourmap[val] + val == n-1) )
//                 return true;
//         }
//         return false;
        //Recursive - TLE
        //return helper(nums,0);
        
        //Memoization
        int *mark = new int[n+1];
        for(int i = 0;i<=n;i++)
            mark[i] = -1;
        
        return helper(nums,0,mark);
    }
};