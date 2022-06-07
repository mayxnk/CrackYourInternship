class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Brute Force Approach - Time:O(n),Space : O(n)
        /*unordered_map<int,int> freq;
        int ans = -1;
        for(int i = 0;i<nums.size();i++)
        {
            if(freq[nums[i]] >=(nums.size()/2))
            {
                ans = nums[i];
                break;
            }
            freq[nums[i]]++;
        }
        return ans;
        */
        //Optimal Approach - Time:O(n)
        int count = 0,major = nums[0];
        for(int i = 0;i<nums.size();i++)
        {
            if(count == 0)
            {
                major = nums[i];
                count++;
            }
            else if(major == nums[i])
                count++;
            else
                count--;
        }
        return major;
    }
};