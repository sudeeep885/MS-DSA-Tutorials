class Solution {
public:
    
    vector<vector<string>> ans; vector<bool> col, up, down;
    
    bool isUnderAttack(int r, int c, int n) {
        return (col[c] || up[r+c] || down[r-c+n]);
    }
    
    void pickThisPos(int r, int c, int n, vector<string>& curr) {
        col[c] = true; up[r+c] = true; down[r-c+n] = true;
        
        string temp = "";
        for(int i=0; i<n; ++i) temp += (i==c)? 'Q' : '.';
        curr.push_back(temp);
    }
    
    void removeThisPos(int r, int c, int n, vector<string>& curr) {
        col[c] = false; up[r+c] = false; down[r-c+n] = false;
        curr.pop_back();
    }
    
    void dfs(int n, int idx, vector<string>& curr) {
        
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=0; i<n; ++i) {
            if(isUnderAttack(idx, i, n)) continue;
            pickThisPos(idx, i, n, curr);
            dfs(n, idx+1, curr);
            removeThisPos(idx, i, n, curr);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> curr;
        col.resize(n, 0); up.resize(2*n, 0); down.resize(3*n, 0);
        
        dfs(n, 0, curr);
        
        return ans;
    }
};
