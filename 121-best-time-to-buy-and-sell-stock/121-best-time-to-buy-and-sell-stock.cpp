class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        //Brute Force Approach
        /*int maxm = 0;
        for(int i = 0;i<prices.size()-1;i++)
        {
            for(int j = i+1;j<prices.size();j++)
            {
                if(j > i)
                maxm = max(maxm,prices[j] - prices[i]);
            }
        }
        return maxm;*/
        //Optimal Approach
        int minm = INT_MAX,profit = 0;
        for(int i = 0;i<prices.size();i++)
        {
            minm = min(minm,prices[i]);
            profit = max(profit, prices[i] - minm);
        }
        return profit;
    }
};