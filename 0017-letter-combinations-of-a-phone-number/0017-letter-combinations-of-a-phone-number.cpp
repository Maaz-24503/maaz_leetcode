class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return vector<string>{};
        vector<string> keys {" ","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        function<vector<string>(int)> helper = [&](int i){
            if(i == -1) return vector<string>{""};
            vector<string> rec = helper(i-1);
            vector<string> ans;
            for(int k = 0; k<rec.size(); k++){
                for(int j = 0; j<keys[digits[i] - '0'].size(); j++) ans.push_back(rec[k] + keys[digits[i] - '0'][j]);
            }
            return ans;
        };
        return helper(n-1);
    }
};