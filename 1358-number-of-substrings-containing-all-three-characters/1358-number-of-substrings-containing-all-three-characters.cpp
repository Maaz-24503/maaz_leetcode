class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> f{0, 0, 0};
        function<bool()> isFine = [&f]() -> bool {
            for(int i = 0; i < 3; i++) 
                if(!f[i]) 
                    return false;
            return true;
        };
        int r = 0, l = 0, valid = 0;
        while(r < n){
            while(r < n && !isFine()){
                f[s[r] - 'a']++;
                r++;
            }
            while(isFine()){
                valid += n - r + 1;
                f[s[l] - 'a']--;
                l++;
            }
        }
        return valid;
    }
};