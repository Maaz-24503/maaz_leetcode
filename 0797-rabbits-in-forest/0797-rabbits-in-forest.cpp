class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for(int& num : answers) cnt[num]++;
        int ans = 0;
        for(auto [num, freq] : cnt) ans += (((freq + num)/(num+1))*(num+1));
        return ans;
    }
};