class Solution {
public:
    bool valid(int i,int j,vector<vector<char>>& board,char c){
        for(int k=0;k<9;k++){
            if(board[k][j]== c || board[i][k]==c)return false;
        }
        for(int ki = i - i%3 ; ki < (i-i%3) + 3 ;ki++){
            for(int kj = j - j%3 ; kj < (j-j%3) + 3 ;kj++){
                if(board[ki][kj] == c)return false;
            }
        }
        return true;
    }
    bool solve(int i , int j , vector<vector<char>> &board)
    {
        if(i==9) return true;
        if(j==9) return solve(i+1,0,board);
        if(board[i][j]!='.') return solve(i,j+1,board);
        for(char c='1';c<='9'; c++){
            if(valid(i,j,board,c)==false)continue;
            board[i][j]=c;
            bool result = solve(i,j+1,board);
            if (result==true)return true;
            board[i][j]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};