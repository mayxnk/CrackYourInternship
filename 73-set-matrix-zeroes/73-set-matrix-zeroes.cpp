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
        //Using space O(m*n)
        vector<vector<bool>> check(matrix.size(), vector<bool> (matrix[0].size()));
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
                check[i][j] = false;
        }
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(!matrix[i][j] && !check[i][j])
                {
                    makeZero(matrix,check,i,j);
                }
            }
        }
    }
};