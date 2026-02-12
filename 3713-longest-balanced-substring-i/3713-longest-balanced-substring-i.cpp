class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> window(26);
        function<bool(int)> check = [&](int curr) -> bool {
            for(int i = 0; i < 26; i++) 
                if(window[i] != curr && window[i] != 0) return false;
            return true;
        };

        int ans = 0;

        for(int i = 0; i < n; i++){
            fill(window.begin(), window.end(), 0);
            for(int j = i; j >= 0; j--){
                window[s[j] - 'a']++;
                if(check(window[s[j] - 'a'])) ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};