class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        //*** Brute Force Approach //
        if(nums.size()==0 || nums.size()==1)
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
    }
};