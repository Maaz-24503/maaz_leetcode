class Solution {
public:
    bool isValid(string s, unordered_set<string>& valid){
        return valid.find(s) != valid.end();
    }

    int numDecodings(string s) {
        int n = s.length();
        unordered_set<string> valid;
        for(int i = 1; i<27; i++){
            valid.insert(to_string(i));
        }
        vector<int> memo(n+1, 0);
        memo[n] = 1;
        if(isValid(s.substr(n-1), valid)) memo[n-1] = 1;
        for(int i = n-2; i>=0; i--){
            if(isValid(s.substr(i, 1), valid)) memo[i] += memo[i+1];
            if(isValid(s.substr(i, 2), valid)) memo[i] += memo[i+2];
        }
        return memo[0];
    }
};