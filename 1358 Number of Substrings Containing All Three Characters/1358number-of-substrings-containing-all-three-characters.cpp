class Solution {
private:
    bool validFreq(vector<int>& freq){
        for(int i = 0; i<3; i++) if(!freq[i]) return false;
        return true;
    }
public:
    int numberOfSubstrings(string s) {
        vector<int> freq{0, 0, 0};
        int l = 0, r = 0, ans = 0;
        freq[s[l] - 'a']++;
        while(r < s.size()){
            if(!validFreq(freq)){
                r++;
                if(r < s.size()) freq[s[r] - 'a']++;
            }
            while(validFreq(freq)){
                ans += s.size() - r;
                freq[s[l] - 'a']--;
                l++;
            }
        }
        return ans;
    }
};