class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if(nums2.size() == 0)
            return;
        if(m == 0 && n!=0)
        {
            for(int i = 0;i<n;i++)
                nums1[i] = nums2[i];
            return;
        }
        //Move the elements of nums1 by n
        int t = nums1.size()-1;
        for(int i = m-1;i>=0;--i)
            nums1[t--] = nums1[i];
        
        int i = n,j = 0, k =0;
        while(i<nums1.size() && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                nums1[k] = nums1[i];
                ++i;
                ++k;
            }
            else
            {
                nums1[k] = nums2[j];
                ++j;
                ++k;
            }
        }
        while(i<nums1.size())
        {
            nums1[k++] = nums1[i++];
        }
        while(j<n)
        {
            nums1[k++] = nums2[j++];
        }
    }
};