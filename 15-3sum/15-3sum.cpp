class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size()<3)
            return {};
        //Brute force
        sort(nums.begin(),nums.end());
        
        int start = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        // if(nums.size()>=3 && nums[0]==nums[nums.size()-1] && nums[0]==0)
        // {
        //     temp.push_back(0);
        //     temp.push_back(0);
        //     temp.push_back(0);
        //     ans.push_back(temp);
        //     return ans;
        // }
        while(start < nums.size()-2 && nums[start] <= 0)
        {
            int mid = start + 1,high = nums.size() - 1;
            if(nums[start] > 0)
                break;
            while(mid < high)
            {
                int sum = nums[start] + nums[mid] + nums[high];
                if(sum < 0)
                    mid++;
                else if(sum > 0)
                    high--;
                else
                {
                    if(nums[mid] == nums[high])
                    {
                        temp.push_back(nums[start]);
                        temp.push_back(nums[mid]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        temp.clear();
                        break;
                    }
                    else
                    {
                        temp.push_back(nums[start]);
                        temp.push_back(nums[mid]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        temp.clear();
                        while(mid < nums.size() - 2 && nums[mid] == nums[mid+1])
                            mid++;
                        while(nums[high] == nums[high-1])
                            high--;
                         mid++;
                         high--;
                    }
                   
                }

            }
            while(start<nums.size()-2 && nums[start] == nums[start+1])
                start++;
            start++;
        }
        return ans;
    }
};