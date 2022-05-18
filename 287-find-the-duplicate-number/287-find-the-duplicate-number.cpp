#include<algorithm>
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // O(nlogn) solution
        sort(nums.begin(),nums.end()); //Sorting the given array
        int ans = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1]) //Now,checking which element is repeated in this order
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
   
};