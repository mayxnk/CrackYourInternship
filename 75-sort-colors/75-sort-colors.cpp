#include<climits>
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        //*** Brute Force Approach *//
       /* if(nums.size()==0 || nums.size()==1)
            return;
        int *temp = new int[nums.size()];
        int zero = 0,two = nums.size()-1,count = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                temp[zero] = 0;
                zero++;
            }
            else if(nums[i] == 2)
            {
                temp[two] = 2;
                two--;
            }
            else
                count++;
        }
        if(count>0)
            while(zero<=two)
                temp[zero++] = 1;
        for(int i = 0;i<nums.size();i++)
            nums[i] = temp[i];
        delete []temp;
       */
        
       /****More Optimised Approach - O(2*n) */
       /* int z = 0,one = 0,two = 0,i=0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(nums[i]==0)
                z++;
            else if(nums[i]==1)
                one++;
            else
                two++;
        }
        while(i<n)
        {
            if(i<z)
            {
                nums[i] = 0;
                i++;
            }
            else if(i<one + z)
                nums[i++] = 1;
            else
                nums[i++] = 2;
        }
        */
        /*** Optimal Solution - O(n) time,O(1) space */
        int n = nums.size();
        int low = 0,mid = 0,high = n-1;
        while(mid<=high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid],nums[low]);
                low++;mid++;
            }
            else if(nums[mid] == 1)
                mid++;
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};