class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> seen(n + 1, 0);
        
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                seen[i + 1] = max(seen[i + 1], seen[i]) + (1LL * mana[j] * skill[i]);
            }
            for (int i = n - 1; i > 0; i--) {
                seen[i] = seen[i + 1] - (1LL * mana[j] * skill[i]);
            }
        }
        
        return seen[n];
    }
};