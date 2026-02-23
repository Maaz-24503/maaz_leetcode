class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> seen;
        int n = s.size();
        int mask = ~(1 << (k - 1));
        if(n <= k) return false;
        function<int(string)> binToDec = [&](string num) -> int {
            int res = 0;
            for(int i = 0; i < num.size(); i++){
                if(num[i] == '1') res += 1;
                res <<= 1;
            }
            return res>>1;
        };
        int curr = binToDec(s.substr(0, k));
        seen.insert(curr);
        for(int l = 0, r = k; r < n; r++){
            if(s[l] == '1') curr &= mask;
            curr <<= 1;
            if(s[r] == '1') curr++;
            seen.insert(curr);
            l++;
        }
        return seen.size() == (1 << k);
    }
};