class Solution {
public:
    int helper(int k) {
        int count = 0;
        while (k % 5 == 0) {
            k /= 5;
            count++;
        }
        return count;
    }

    int trailingZeroes(int n) {
        int five = 0;
        long long curr = 5;
        while (curr <= n) {
            five += helper(curr);
            curr += 5;
        }
        return five;
    }
};