class Solution {
public:
    int mirrorDistance(int n) {
        string curr = to_string(n);
        reverse(curr.begin(), curr.end());
        return abs(n - stoi(curr));
    }
};