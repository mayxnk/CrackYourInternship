class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size();
        if(k == 0)
            return 0;
        // if(k == cardPoints.size())
        // {
        //     int sum = 0;
        //     for(int i=0;i<n;i++)
        //         sum+=cardPoints[i];
        //     return sum;
        // }
        // int i = 0,j = cardPoints.size()-1,maxm = 0;
        // while(k!=0)
        // {
        //     if(cardPoints[i] > cardPoints[j])
        //     {
        //         maxm += cardPoints[i];
        //         i++;
        //     }
        //     else if(cardPoints[i] < cardPoints[j])
        //     {
        //         maxm += cardPoints[j];
        //         --j;
        //     }
        //     else
        //     {
        //         maxm += cardPoints[i];
        //         if(cardPoints[i+1] >= cardPoints[j-1])
        //             i++;
        //         else 
        //             j--;
        //     }
        //     --k;
        // }
        int windSum = 0;
        for(int i = n-k;i<n;i++)
            windSum += cardPoints[i];
        
        int ans = windSum,j = 0,i = n-k;
        while(j<k && i<n)
        {
            windSum += cardPoints[j++];
            windSum -= cardPoints[i++];
            ans = max(ans,windSum);
        }
        return ans;
    }
};