class Solution {
public:
    int concatenatedBinary(int n) {
        function<string(int)> numToBin = [](int k) -> string {
            string ans = "";
            while(k > 0){
                if(k % 2) ans += "1";
                else ans += "0";
                k /= 2;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        };
        string completeNum = "";
        for(int i = 1; i <= n; i++) completeNum += numToBin(i);
        long long res = 0LL;
        for(char &d : completeNum){
            int dig = d - '0';
            res = (res<<1) + dig;
            res %= (long long) 1e9 + 7;
        }
        return static_cast<int>(res);
    }
};