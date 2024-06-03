class Solution {
public:
int n,m;
    bool helper(int index, int row,int col,vector<vector<char>>& board,string word){
        if( index == word.size()) return true;
        if(row<0||row>=n|| col<0|| col>=m|| word[index]!=board[row][col])return false;
        char temp = board[row][col];
        board[row][col]='$';
        bool ans= false;
        ans |= helper(index+1,row+1,col,board,word);
        ans |= helper(index+1,row-1,col,board,word);
        ans |= helper(index+1,row,col+1,board,word);
        ans |= helper(index+1,row,col-1,board,word);
        board[row][col]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    flag = helper(0,i,j,board,word);
                    if(flag)return true;    
                }
            }
        }
        return false;
    }
};