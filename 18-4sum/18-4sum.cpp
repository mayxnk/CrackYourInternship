class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if(nums.size()==0)
            return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        //Four pointers
        for(int i = 0;i<n;i++)
        {
            int target3 = target - nums[i];
            for(int j = i+1;j<n;j++)
            {
                int target2 = target3 - nums[j];
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    int twosum = nums[left] + nums[right];
                    if(twosum < target2)
                        left++;
                    else if(twosum > target2)
                        right--;
                    else
                    {
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        ans.push_back(temp);
                        while(left < right && nums[left] == temp[2])
                            ++left;
                        while(left < right && nums[right] == temp[3])
                            --right;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1])
                    ++j;
            }
           while(i+1 < n && nums[i]==nums[i+1])
               ++i;
        }
        return ans;
    }
};