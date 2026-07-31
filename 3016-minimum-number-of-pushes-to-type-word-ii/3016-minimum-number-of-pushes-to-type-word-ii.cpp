class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(const char &c : word) freq[c - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int ans = 0, layer = 0;
        for(int i = 0; i < 26; i++){
            if(i % 8 == 0) layer++;
            ans += freq[i] * layer;
        }
        return ans;
    }
};