class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        //Brute foce approach - Time Complexity :O(nlogn),Space - O(1)
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
        //Optimal Approach - Time Complexity - O(n)
    }
};