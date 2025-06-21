class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        unordered_map<char, int> freq;
        for(char &c : word) freq[c]++;
        int ans = n;
        for(auto [c, f] : freq){
            int moves = 0;
            for(auto [cc, ff] : freq){
                if(cc == c) continue;
                if(f > ff) moves += ff;
                else if(ff - f > k) moves += ff - f - k;
            }
            ans = min(ans, moves);
        }
        return ans;
    }
};