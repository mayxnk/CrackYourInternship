class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        //Brute foce approach - Time Complexity :O(nlogn),Space - O(1)
        //vector<int> ans;
        /*sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
        */
        //Better Approach - Time Complexity - O(n),Space -O(n)
        /*
        unordered_map<int,int> freq;
        for(int i = 0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]] == 2)
                ans.push_back(nums[i]);
        }
        return ans;
        */
        //Optimal Approach - Time Complexity - O(n),Space - O(1)
        int j = 0;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++)
        {
            int index = abs(nums[i]) - 1; //Calculating index by by element - 1
            if(nums[index] > 0)
                nums[index] = -(nums[index]);//Negating the element which is positive
            else
                ans.push_back(abs(nums[i])); //If found that element is negative,then add in                                         answer,because that means that element is again visited
        }
        return ans;
    }
};