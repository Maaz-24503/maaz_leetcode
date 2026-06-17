class Solution {
public:
    char processStr(string s, long long k) {
        long long n = 0;
        for(char &c : s){
            if(c == '*') n = max(0LL, n - 1);
            else if(c == '#') n <<= 1;
            else if(c != '%') n++;
        }
        if(k >= n || k < 0) return '.';
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '*'){
                n++;
            } 
            else if(s[i] == '#'){
                n >>= 1;
                if(k >= n) k -= n;
            }
            else if(s[i] == '%'){
                k = n - k - 1;
            }
            else {
                if(k + 1 == n) return s[i];
                n--;
            }
        }
        return s[static_cast<int> (k)];
    }
};