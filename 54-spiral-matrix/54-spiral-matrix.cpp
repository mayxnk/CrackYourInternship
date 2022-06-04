class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int row1 = 0,row2 = matrix.size()-1;
        int col1 = 0,col2 = matrix[0].size()-1;
        vector<int> ans;
        while(row1 <= row2 && col1 <= col2)
        {
            for(int c = col1;c <= col2;c++)
                if(row1>=0 && c>=0 && row1<=row2)
                ans.push_back(matrix[row1][c]);
            ++row1;
            for(int r = row1;r <= row2;r++)
                if(r>=0 && col2>=0 && col2>=col1)
                ans.push_back(matrix[r][col2]);
            --col2;
            for(int c = col2;c >=col1;--c)
                if(row2>=0 && c>=0 && row2>=row1)
                ans.push_back(matrix[row2][c]);
            row2--;
            for(int r = row2;r >= row1;r--)
                if(r>=0 && col1>=0 && col1<=col2)
                ans.push_back(matrix[r][col1]);
            ++col1;
        }
        return ans;
    }
};