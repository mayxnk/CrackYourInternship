class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        bool flag = true;
        int ans;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] != i)
            {
                flag = false;
                ans = i;
                break;
            }
        }
        if(flag)
            return n;
        return ans;   
    }
};