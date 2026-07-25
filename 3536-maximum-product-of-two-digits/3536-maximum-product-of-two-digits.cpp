class Solution {
public:
    int maxProduct(int n) {
        string k = to_string(n);
        sort(k.begin(), k.end(), [](char a, char b) { return a > b; });
        return (k[0] - '0') * (k[1] - '0');
    }
};