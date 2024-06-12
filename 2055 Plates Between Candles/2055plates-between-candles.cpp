class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        vector<int> candles;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '|') candles.push_back(i);
        }
        unordered_map<int, int> left;
        int l = -1; 
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '|') l = i;
            left[i] = l;
        }
        unordered_map<int, int> right;
        int r = -1;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == '|') r = i;
            right[i] = r;
        }
        unordered_map<int, int> count;
        int stars = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '*') stars++;
            else count[i] = stars;
        }
        for(int i = 0; i<queries.size(); i++){
            l = queries[i][0];
            r = queries[i][1];
            if(left[r] == -1 || right[l] == -1) ans[i] = 0;
            else if(left[r]<l) ans[i] = 0;
            else ans[i] = count[left[r]] - count[right[l]];
        }
        return ans;
    }
};