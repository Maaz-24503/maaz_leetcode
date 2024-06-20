class Solution {
public:
    bool helper(string s, int i, unordered_set<string> dict, vector<int>& memo){
        if(i == s.length()) return true;
        if(memo[i]!=-1) return memo[i];
        int done = 0;
        for(int k = i+1; k<=s.length(); k++){
            bool check = false;
            if(dict.find(s.substr(i, k-i)) != dict.end()){
                bool check = helper(s,k,dict,memo);
                if(check) return memo[i] = 1;
            }
        }
        memo[i] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> memo(s.size()+1, -1);
        for(int i = 0; i<wordDict.size(); i++){
            dict.insert(wordDict[i]);
        }
        return helper(s, 0, dict, memo);
    }
};