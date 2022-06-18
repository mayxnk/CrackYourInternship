class Solution {
public:
    int getLiveCells(vector<vector<int>>& curr,int m,int n,int i,int j)
    {
        int live = 0;
        //1.Check the upper neighbour
        if(i > 0)
            if(curr[i-1][j] == 1)
                ++live;
        //2.Check the lower neighbour
        if(i < m-1)
            if(curr[i+1][j] == 1)
                ++live;
        //3.Check left neighbour
        if(j > 0)
            if(curr[i][j-1] == 1)
                ++live;
        //4.Check the right neighbour
        if(j < n-1)
            if(curr[i][j+1] == 1)
                ++live;
        //5.Check upper left neighbour
        if(i > 0 and j > 0)
            if(curr[i-1][j-1] == 1)
                ++live;
        //6.Check upper right neighbour
        if(i > 0 and j < n-1)
            if(curr[i-1][j+1] == 1)
                ++live;
        //7.Check the lower left neighbour
        if(i < m-1 and j > 0)
            if(curr[i+1][j-1] == 1)
                ++live;
        //8.Check the lower right neighbour
        if(i < m-1 and j < n-1)
            if(curr[i+1][j+1] == 1)
                ++live;
        
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) 
    {
        //Brute Force : Time - O(m*n),Space - O(m*n)
        vector<vector<int>> curr = board;
        int m = board.size(),n = board[0].size();
        
        for(int i = 0;i<m;++i)
        {
            for(int j = 0;j<n;++j)
            {
                int nLives = getLiveCells(curr,m,n,i,j);
                if(board[i][j] == 0)
                {
                    if(nLives == 3)
                        board[i][j] = 1;
                }
                else
                {
                    if(nLives < 2 || nLives > 3)
                        board[i][j] = 0;
                }
            }
        }
    }
};