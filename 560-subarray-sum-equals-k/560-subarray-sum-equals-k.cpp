class Solution {
public:
   
    int subarraySum(vector<int>& nums, int k) 
    {
        //Brute Force Approach - Time:O(n^2) , Space:O(1)
        /*int sum,count= 0,n = nums.size();
        for(int i = 0;i<n;i++)
        {
            sum = 0;
            for(int j = i;j<n;j++)
            {
                sum += nums[j];
                if(sum == k)
                {
                    count++;
                }
            }
        }
        return count;
        */
        //Optimal Approach - Time:O(n),Space:(2*n) -> Prefix sum and map
        int count = 0,sum = 0,n = nums.size();
        vector<int> psum;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            psum.push_back(sum);
        }
        unordered_map<int,int> map;
        for(int i = 0;i<n;i++)
        {
            if(psum[i] == k) //Check if prefix sum itself is equal to K or not
                ++count;
            if(map.find(psum[i]-k) != map.end()) //Check if psum[i]-k exist in map or not,if                                                  yes,that means there exist a subarray of sum=K
                count += map[psum[i]-k];
            
            map[psum[i]]++;
        }
        
        return count;
    }
};