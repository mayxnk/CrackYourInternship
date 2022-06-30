class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        //Median and Sorting Approach,Time - O(n^2)
        sort(nums.begin(),nums.end());
        if(nums[0] == nums[nums.size()-1])
            return 0;
        int n = nums.size(),mid = nums[n/2];
        int minm = 0;
        for(int i = 0;i<n;++i)
            minm += abs(nums[i]-mid);
        return minm;
    }
};