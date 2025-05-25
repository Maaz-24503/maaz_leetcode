class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> asym;
        unordered_map<string, int> sym;
        int ans = 0;
        for(string& s : words){
            if(s[0] == s[1]){
                sym[s]++;
            }
            else {
                string rev = string(1, s[1]) + string(1, s[0]);
                if(asym.find(rev) != asym.end() && asym[rev] != 0){
                    asym[rev]--;
                    ans += 4;
                }
                else asym[s]++;
            }
        }
        bool oddTaken = false;
        for(auto [_, freq] : sym){
            if(freq % 2){
                if(!oddTaken){
                    oddTaken = true;
                    ans += freq * 2;
                }
                else{
                    ans += (freq - 1) * 2;
                }
            }
            else ans += freq * 2;
        }
        return ans;
    }
};