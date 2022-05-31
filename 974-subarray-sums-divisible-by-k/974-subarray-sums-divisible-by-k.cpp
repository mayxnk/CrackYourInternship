class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        //Brute force Approach : Time : O(n^2),
       /* int n = nums.size();
        if(n == 0)
            return 0;
        if(n==1)
        {
            if(nums[0] % k == 0)
                return 1;
            else if(nums[0] < k)
                return 0;
            else
                return 0;
        }
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            int sum = nums[i];
            if(sum%k==0)
                ++count;
            for(int j = i+1;j<n;j++)
            {
                sum += nums[j];
                if(sum%k==0)
                    ++count;
            }
        }
        return count;
      */
        //Optimal Approach
        vector<int> pf(k);
        int psum = 0;
        pf[psum]++;
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            psum = (psum + nums[i]);//Calculating prefix sum
            
            int rem = psum % k; //Calculating remaider of sum
            
            if(rem < 0) rem = rem + k;//if rem becomes negative,make it positive by adding k
            
            ans += pf[rem]; //adding count to answer if it visited,otherwise 0 will be added                                 to it
            pf[rem]++; //Making this sum visited,increasing by 1
            
        }
        return ans;
    }
};