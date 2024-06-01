class Solution {
public:
    int N;
    bool isValid(int i, int j, vector<string>& board) {
        int row=i;
        int col=j;
        while(row>=0 && col>=0){   // checking if there is any queen in left diagonal
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        col=j;
        row=i;
        while(col<N && row>=0){    // checking if there is any queen in right diagonal
            if(board[row][col]=='Q')return false;
            col++;
            row--;
        }
        col=j;
        row=i;
        while(row>=0){  // checking if there is any queen in colmn
            if(board[row][col]=='Q')return false;
            row--;
        }
        return true;
    }
    void helper(int row,vector<string>& board,vector<vector<string>>& ans)
    {
        if(row == N){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<N;col++){
            if(isValid(row,col,board) == true){
                board[row][col]='Q';
                helper(row+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
        N=n;
        vector<string> arr(n);
        string s(n,'.');
        for(int i=0;i<n;i++) arr[i]=s;
        helper(0,arr,ans);
        return ans;
    }
};