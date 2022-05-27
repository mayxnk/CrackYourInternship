class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //Brute Force Approach
        /*vector<int> v;
        for(int i = 0;i<nums.size()-1;i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
        */
        //Optimal Approach 
        int sum = 0,i = 0;
        vector<int> v;
        unordered_map<int,int> ourmap;
        for(int i = 0;i<nums.size();i++)
            ourmap[nums[i]] = i;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(ourmap.count(target-nums[i]) && i != ourmap[target - nums[i]])
            {
                v.push_back(i);
                v.push_back(ourmap[target - nums[i]]);
                ourmap.erase(nums[i]);
                ourmap.erase(target - nums[i]);
            }
        }
        return v;
    }
};