class Solution {
public:
    bool check(vector<int>& digits, int i, int curr, int sum, int& target) {
        if(sum > target) return false; 
        if(i == digits.size()) return (curr + sum) == target;
        if(check(digits, i+1, curr*10+digits[i], sum, target)) return true;
        if(check(digits, i+1, digits[i], sum+curr, target)) return true;
        return false;
    }
    vector<int> make_(int t) {
        vector<int> digits;
        while(t > 0) {
            int d = t%10;
            t = t / 10;
            digits.push_back(d);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; ++i) {
            vector<int> digits = make_(i*i);
            if(check(digits, 0, 0, 0, i)) ans += i*i;
        }
        return ans;
    }
};
