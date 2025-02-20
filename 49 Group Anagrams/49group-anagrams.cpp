class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        for(int i = 0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            freq[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto [an, arr] : freq){
            ans.push_back(arr);
        }
        return ans;
    }
};