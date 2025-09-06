class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto calc = [&](int limit) -> long long {
            long long total = 0;
            int step = 1, power = 1;
            while (power <= limit) {
                int upper = min(power * 2 - 1, limit);
                total += 1LL * ((step + 1) / 2) * (upper - power + 1);
                step++;
                power *= 2;
            }
            return total;
        };

        long long result = 0;
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            result += (calc(right) - calc(left - 1) + 1) / 2;
        }
        return result;
    }
};
