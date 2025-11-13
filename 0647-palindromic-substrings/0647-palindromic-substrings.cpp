class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        function<int()> countOdd = [&]() -> int {
            int ans = 0;
            for(int i = 0; i < n; i++){
                int l = i, r = i;
                while(l >= 0 && r < n && s[l] == s[r]){
                    ans++;
                    r++;
                    l--;
                }
            }
            return ans;
        };
        function<int()> countEven = [&]() -> int {
            int ans = 0;
            for(int i = 0; i < n - 1; i++){
                int l = i, r = i + 1;
                while(l >= 0 && r < n && s[l] == s[r]){
                    ans++;
                    r++;
                    l--;
                }
            }
            return ans;
        };
        return countEven() + countOdd();
    }
};