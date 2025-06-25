class Solution {
public:
    int lastRemaining(int n) {
        function<int(int,bool)> helper = [&](int k, bool right) -> int {
            if(k == 1) return 1;
            if(right) return 2 * helper(k/2, false);
            return k%2 ? 2 * helper(k/2, true) : 2 * helper(k/2, true) - 1;
        };
        return helper(n, true);
    }
};