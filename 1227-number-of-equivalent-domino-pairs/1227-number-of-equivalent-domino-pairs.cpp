class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> freq;
        int n = dominoes.size();
        for(int i = 0; i<n; i++){
            string key = to_string(max(dominoes[i][0], dominoes[i][1])) + "," + to_string(min(dominoes[i][0], dominoes[i][1]));
            freq[key]++;
        }
        int ans = 0;
        for(auto [key, occ] : freq){
            ans += ((occ-1)*occ)/2; 
        }
        return ans;
    }
};