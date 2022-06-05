class Solution {
public:
    bool check(int index,int i,int j,vector<vector<char>>& board,string word)
    {
        if(index == word.size())
            return true;
        
        if(i >= board.size() || j >= board[0].size() || i<0 || j<0 || board[i][j] == '.')
            return false; //Checking Boundary conditions
        
        if(board[i][j] != word[index])
            return false;
        
        char saved = board[i][j];
        board[i][j] = '.';//Marking it visited
        
        //We can move up,down,left and right
        if(check(index+1,i-1,j,board,word) || check(index+1,i+1,j,board,word) ||
            check(index+1,i,j+1,board,word) || check(index+1,i,j-1,board,word))
            return true;
        
        board[i][j] = saved;//Backtrack if false
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
                if(check(0,i,j,board,word))
                    return true;
        }
        return false;
    }
};