class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        int curr = -1;
        for(int i = 0; i<n; i++)
            if(curr != groups[i]){
                curr = groups[i];
                ans.push_back(words[i]);
            }
        return ans;
    }
};