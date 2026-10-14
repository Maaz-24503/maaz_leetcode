class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num < (sum + 8) / 9) return "";
        string ans = string(sum / 9, '9');
        if(sum % 9) ans += string(1, '0' + sum % 9);
        ans += string(num - ans.size(), '0');
        return ans;
    }
};