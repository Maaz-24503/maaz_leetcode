class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students,
                            vector<vector<int>>& mentors) {
        int n = students[0].size(), m = students.size();
        vector<vector<int>> scores(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < n; k++)
                    if (students[i][k] == mentors[j][k])
                        scores[i][j]++;

        function<int(int, long long)> helper = [&](int i, long long mask) -> int {
            if (i == m)
                return 0;
            int ans = 0;
            for (int j = 0; j < m; j++) {
                long long curr = 1 << j;
                if ((curr & mask) != 0) {
                    long long newMask = mask - curr;
                    ans = max(ans, scores[i][j] + helper(i + 1, newMask));
                }
            }
            return ans;
        };
        long long t = (1LL << m) - 1LL;
        return helper(0, t);
    }
};