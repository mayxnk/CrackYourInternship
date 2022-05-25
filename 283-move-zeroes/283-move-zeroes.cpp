class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int nzero = 0;
        for(int i = 0;i<nums.size();i++)
            if(nums[i] == 0)
                nzero++;
        int i = 0;
        for(int j = 0;j<nums.size();j++)
        {
            if(nums[j] != 0)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        for(int j = nums.size()-nzero;j<nums.size();j++)
        {
            nums[j] = 0;
        }
    }
};