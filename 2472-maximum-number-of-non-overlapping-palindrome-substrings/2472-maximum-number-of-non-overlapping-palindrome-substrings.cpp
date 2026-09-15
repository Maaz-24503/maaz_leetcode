class Solution {
public:
    int maxPalindromes(string s, int k) {
        int l = 0, r = k, n = s.size();
        function<bool(int, int)> isPalindrome = [&s](int i, int j) -> bool {
            for(int p = i; p < (i + j) / 2; p++){
                if(s[p] != s[j - (p - i) - 1]) return false;
            }
            return true;
        };
        int ans = 0;
        while(r <= n){
            // cout<<l<<" "<<r<<endl;
            if(isPalindrome(l, r)){
                // cout<<l<<" "<<r<<endl;
                ans++;
                l = r;
                r = l + k;
                continue;
            }
            if(r < n && isPalindrome(l, r + 1)){
                ans++;
                l = r + 1;
                r = l + k;
                continue;
            }
            l++; r++;
        }
        return ans;
    }
};