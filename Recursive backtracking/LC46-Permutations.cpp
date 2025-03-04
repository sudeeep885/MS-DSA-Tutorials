class Solution {
public:
    vector<vector<int>> allPerm;
    void backtrack(vector<int>& nums, int i, vector<bool>& visited, vector<int>& curr) {
        if(i == nums.size()) {
            allPerm.push_back(curr);
            return;
        }
        for(int j=0; j<(int)nums.size(); ++j) if(!visited[j]) {
            visited[j] = 1;
            curr.push_back(nums[j]);
            backtrack(nums, i+1, visited, curr);
            visited[j] = 0;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);
        vector<int> curr;
        backtrack(nums, 0, visited, curr);
        return allPerm;
    }
};


