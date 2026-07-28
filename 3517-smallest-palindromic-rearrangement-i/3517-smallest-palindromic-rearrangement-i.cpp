class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        bool isOdd = n % 2;
        string half = s.substr(0, n / 2);
        sort(half.begin(), half.end());
        string rev = half;
        reverse(rev.begin(), rev.end());
        return half + (isOdd ? string(1, s[n/2]) : "") + rev;
    }
};