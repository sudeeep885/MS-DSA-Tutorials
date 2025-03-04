class Solution {
public:
    
    vector<vector<int>> ans;
    
    void helper(int n, int k, int idx, int start, vector<int>& curr) {
        if(idx == k) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=start; i<=n; ++i) {
            curr.push_back(i);
            helper(n, k, idx+1, i+1, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        helper(n, k, 0, 1, curr);
        return ans;
    }
};
