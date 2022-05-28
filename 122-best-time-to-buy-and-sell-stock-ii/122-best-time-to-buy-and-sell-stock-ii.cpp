class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        //Optimal Approach - O(n),we can also use maxima and minima appraoch 
        //in this question
        int profit = 0,n = prices.size();
        for(int i = 1;i<n;i++)
        {
            if(prices[i] > prices[i-1]) //Checking if next day prices is more ot not
                profit += (prices[i] - prices[i-1]);
        }
        return profit;

        //Maxima and Minima Approach
        
    }
};