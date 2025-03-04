class Solution {
public:
    int ans;
    int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void backtrack(vector<vector<int>>& grid, int i, int j, int& curr) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || !grid[i][j])
            return;
        int temp = grid[i][j];
        curr += temp;
        grid[i][j] = 0;
        ans = max(ans, curr);
        for(int k=0; k<4; ++k) {
            int x = i + moves[k][0], y = j + moves[k][1];
            backtrack(grid, x, y, curr);
        }
        curr -= temp;
        grid[i][j] = temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); ans = 0;
        int curr = 0;
        for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) if(grid[i][j]) {
            backtrack(grid, i, j, curr);
        }
        return ans;
    }
};
