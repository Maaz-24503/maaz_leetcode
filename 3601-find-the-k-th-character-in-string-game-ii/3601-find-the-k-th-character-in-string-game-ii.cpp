class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        function<char(long long)> helper = [&](long long curr) -> char {
            if (curr == 1) {
                return 'a';
            }
            int turn = -1;
            long long p = 1;
            while (p < curr) {
                p <<= 1;
                turn++;
            }
            p >>= 1;
            if (operations[turn] == 1) {
                char c = helper(curr - p);
                return (c == 'z') ? 'a' : c + 1;
            } else {
                return helper(curr - p);
            }
        };
        return helper(k);
    }
};