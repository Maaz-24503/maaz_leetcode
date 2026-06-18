class Solution {
public:
    int maxProduct(string s) {
        function<bool(string)> isPalindrome = [](string p) -> bool {
            for(int i = 0; i < p.size()/2; i++) 
                if(p[i] != p[p.size() - i - 1]) return false;
            return true;
        };
        int ans = 0;
        int lim = 1<<s.size();

        vector<bool> palindrome(lim, false);

        for(int i = 0; i < lim; i++){
            int mask = 1, p = 0;
            string curr = "";
            while(mask < lim){
                if((mask & i) != 0) curr += string(1, s[p]);
                mask <<= 1;
                p++; 
            }
            palindrome[i] = isPalindrome(curr);
        }

        for(int i = 1LL; i < lim; i++){
            for(int j = 1LL; j < lim; j++){
                if((j & i) == 0LL){
                    if(palindrome[i] && palindrome[j]) ans = max(ans, __builtin_popcount(i) * __builtin_popcount(j));
                }
            }
        }

        return ans;
    }
};