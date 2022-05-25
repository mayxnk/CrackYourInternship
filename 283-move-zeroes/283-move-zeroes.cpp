class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        //Brute Force Approach - O(2*n)
        /*int i = 0;
        for(int j = 0;j<nums.size();j++)
        {
            if(nums[j] != 0)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        while(i<nums.size())
        {
            nums[i] = 0;
            i++;
        }
        */
        //Optimised - O(n),two pointer approach
        int i = 0,j = 0;
        while(i<nums.size())
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else
                i++;
        }
        
    }
};