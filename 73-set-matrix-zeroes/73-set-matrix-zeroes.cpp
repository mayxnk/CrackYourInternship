class Solution {
public:
    void makeZero(vector<vector<int>>& matrix, vector<vector<bool>>& check,int i,int j)
    {
        //Making entire column as zeroes
        for(int x = 0;x<matrix.size();x++)
        {
            if(x == i || matrix[x][j] == 0)
                continue;
            matrix[x][j] = 0;
            check[x][j] = true;
        }
        //Making entire row as zeroes
        for(int y = 0;y<matrix[0].size();y++)
        {
            if(y == j || matrix[i][y] == 0)
                continue;
            matrix[i][y] = 0;
            check[i][y] = true;
        }
        
    }
    void setZeroes(vector<vector<int>>& matrix) 
    {
        //Using space O(m*n) , Time - O(n^3) in worst case
        // vector<vector<bool>> check(matrix.size(), vector<bool> (matrix[0].size()));
        // for(int i = 0;i<matrix.size();i++)
        // {
        //     for(int j = 0;j<matrix[0].size();j++)
        //         check[i][j] = false;
        // }
        // for(int i = 0;i<matrix.size();i++)
        // {
        //     for(int j = 0;j<matrix[0].size();j++)
        //     {
        //         if(!matrix[i][j] && !check[i][j])
        //         {
        //             makeZero(matrix,check,i,j);
        //         }
        //     }
        // }
        /*Optimsed */
        int m = matrix.size(),n = matrix[0].size();
        int col = 1;
        for(int i = 0;i<m;i++)
        {
            if(matrix[i][0] == 0)
                col = 0;
            for(int j = 1;j<n;j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        for(int i = m-1;i>=0;i--)
        {
            for(int j = n-1;j>=1;j--)
               if(matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
            if(col == 0 )
                matrix[i][0] = 0;
        }
        
    }
};