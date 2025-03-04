class Solution {
public:
    int getBoxNo(int& i, int& j) {
        return (i/3)*3 + (j/3);
    }
    bool backtrack(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& cube) {
        if(i == 9) return true;
        if(board[i][j] != '.') {
            if(backtrack(board, (i + (j==8)), ((j==8)?0:(j+1)), row, col, cube)) return true;
        }
        else {
            int b_ = getBoxNo(i, j);
            for(int k=1; k<=9; ++k) {
                if(row[i][k] || col[j][k] || cube[b_][k]) continue;
                row[i][k] = 1;
                col[j][k] = 1;
                cube[b_][k] = 1;
                board[i][j] = k + '0';
                if(backtrack(board, (i + (j==8)), ((j==8)?0:j+1), row, col, cube)) return true;
                row[i][k] = 0;
                col[j][k] = 0;
                cube[b_][k] = 0;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<vector<bool>> row(9, vector<bool>(10, 0)), col(9, vector<bool>(10, 0));
        vector<vector<bool>> cube(9, vector<bool>(10, 0));
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(board[i][j] != '.') {
            int d = board[i][j] - '0';
            row[i][d] = 1;
            col[j][d] = 1;
            cube[getBoxNo(i, j)][d] = 1;
        }
        backtrack(board, 0, 0, row, col, cube);
    }
};
