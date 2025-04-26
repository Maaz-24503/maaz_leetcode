class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        function<int(int)> helper = [&](int i){
            if(i == n) return 1;
            if(s[i] == '0') return 0;
            if(i == n-1) return 1;
            if(memo[i] != -1) return memo[i];
            int ans = helper(i+1);
            int curr = stoi(s.substr(i, 2));
            if(curr < 27) ans += helper(i+2);
            return memo[i] = ans;
        };
        return helper(0);
    }
};