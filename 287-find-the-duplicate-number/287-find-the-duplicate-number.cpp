#include<algorithm>
#include<unordered_map>
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // // O(nlogn) solution
        // sort(nums.begin(),nums.end()); //Sorting the given array
        // int ans = 0;
        // for(int i = 0;i<nums.size()-1;i++)
        // {
        //     if(nums[i] == nums[i+1]) //Now,checking which element is repeated in this order
        //     {
        //         ans = nums[i];
        //         break;
        //     }
        // }
        // return ans;
        
        //O(n) approach,space - O(n)
        /*unordered_map<int,int> freq;
        int ans;
        for(int i = 0;i<nums.size();i++)
            freq[nums[i]]++;
        for(int i = 0;i<nums.size();i++)
        {
            if(freq[nums[i]] >= 2)
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
        */
        //Constant space and O(n) time method
        int slow = nums[0],fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};