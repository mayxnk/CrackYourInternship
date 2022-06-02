class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> transpose(m,vector<int>(n,0));
        
        int t2 = 0;
        for(int i = 0;i<n;i++)
        {
            int t1 = 0;
            for(int j = 0;j<m && t1 < m;j++)
            {
                transpose[t1][t2] = matrix[i][j];
                t1++;
            }
            ++t2;
        }
        return transpose;
    }
};