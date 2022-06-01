class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        //Brute approach - Time : O(n^2)
        // int maxm = 0;
        // for(int i = 0;i<height.size()-1;i++)
        // {    
        //     int currHeight = height[i];
        //     for(int j = i+1;j<height.size();j++)
        //     {
        //         if(height[i] < currHeight)
        //             continue;
        //         else
        //             maxm = max((j-i)*min(currHeight,height[j]), maxm);
        //     }
        // }
        // return maxm;
        
        //Optimal Approach - O(n):Two pointers
        int i = 0,j = height.size()-1,maxm = 0;
        while(i<j)
        {
            maxm = max((j-i)*min(height[i],height[j]),maxm);
            if(height[i] < height[j]) //Moving the lower height container pointer,as we want                                          max valume of water
                i++;
            else
                j--;
        }
        return maxm;
    }
};