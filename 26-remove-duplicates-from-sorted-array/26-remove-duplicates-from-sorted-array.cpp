#include<unordered_set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        //Brute Force Approach : Time - O(nlogn + n), Space - O(1)
        /*unordered_set<int> freq;
        for(int i = 0;i<nums.size();i++)
        {
            freq.insert(nums[i]);
        }
        int i = freq.size()-1;
    
        unordered_set<int> :: iterator itr;
        for(itr = freq.begin();itr!=freq.end();itr++)
        {
            nums[i--] = *itr;
        }
        sort(nums.begin(),nums.begin() + freq.size());
        return freq.size();
        */
        //Optimal Approach :Time - O(n)
        int i = 0,j = 1;
        for(;j<nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
;    }
};