class Solution {
public:
   vector<vector<string>> ret;
   bool isPossible(int n,int row,int col, vector<string>& ans)
    {
        //Upper column
        for(int i = row-1;i>=0;i--)
            if(ans[i][col] == 'Q')
                return false;
        //Upper right column
        for(int i = row-1,j = col-1;i>=0 && j>=0;i--,j--)
            if(ans[i][j]=='Q')
               return false;
        //Upper left column
        for(int i = row-1,j = col+1;i>=0 && j<n;i--,j++)
            if(ans[i][j] == 'Q')
                return false;
        
        return true;
    }
    void nQueenHelper(int n,int i, vector<string>& ans)
    {
        if(i == n)
        {
            // for(int i = 0;i<n;i++)
            // {
            //     vector<string> t;
            //     for(int j = 0;j<)
            // }
            ret.push_back(ans);
            return;
        }
        for(int j = 0;j<n;j++)
        {
            if(isPossible(n,i,j,ans))
            {
                ans[i][j] = 'Q';
                nQueenHelper(n,i+1,ans);
                ans[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> ans(n,string(n,'.'));
        nQueenHelper(n,0,ans);
        return ret;
    }
};