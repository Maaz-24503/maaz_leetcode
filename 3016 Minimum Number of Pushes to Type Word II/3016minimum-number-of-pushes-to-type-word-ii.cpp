class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26, 0);
        for(int i = 0; i<n; i++) freq[word[i] - 'a']++;
        sort(freq.begin(), freq.end());
        int ans = 0;
        for(int i = 0; i<26; i++){
            if(i>=18) ans += freq[i];
            else if(i>=10) ans += freq[i]*2;
            else if(i>=2) ans += freq[i]*3;
            else ans += freq[i]*4;
        }
        return ans;
    }
};