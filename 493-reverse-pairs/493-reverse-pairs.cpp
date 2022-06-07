class Solution {
public:
    int merge(vector<int>& nums,int l,int m,int h)
    {
        int j = m+1;
        int count = 0;
        for(int i = l;i<=m; i++)
        {
            while(j<=h && nums[i] > (long)2*nums[j])
                j++;
            count += (j - (m+1));
        }
        //Merge the sorted array
        vector<int> temp;
        int i = l;
        j = m + 1;
        while(i<=m && j<=h)
        {
            if(nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m) temp.push_back(nums[i++]);
        while(j<=h) temp.push_back(nums[j++]);
        
        for(int i = l;i<=h;i++)
            nums[i] = temp[i-l];
        
        return count;
    }
    int mergeSort(vector<int>& nums,int l,int h)
    {
        int count = 0;
        if(l < h)
        {
            int mid = (l+h)/2;
            
            count += mergeSort(nums,l,mid);
            count += mergeSort(nums,mid+1,h);
            count += merge(nums,l,mid,h);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) 
    {
        //Brute Force - Time-O(n^2)-TLE 
        // int count = 0;
        // for(int i = 0;i<nums.size();i++)
        // {
        //     for(int j = i+1;j<nums.size();j++)
        //     {
        //         if(nums[i] > (long)2*nums[j])
        //             count++;
        //     }
        // }
        // return count;
        //Optimal Approach - Time:O(nlogn),Space - O(n)
        
        return mergeSort(nums,0,nums.size()-1);
        
        
        
    }
};