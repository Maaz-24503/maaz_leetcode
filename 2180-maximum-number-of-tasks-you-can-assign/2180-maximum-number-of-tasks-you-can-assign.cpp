class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto isPossible = [&](int k) -> bool {
            multimap<int, int> availableWorkers;
            int remainingPills = pills;
            for (int i = m - k; i < m; ++i) {
                availableWorkers.insert({workers[i], 1});
            }

            for (int i = k - 1; i >= 0; i--) {
                int requiredStrength = tasks[i];
                auto strongestIt = prev(availableWorkers.end());
                if (strongestIt->first >= requiredStrength) {
                    if (--strongestIt->second == 0)
                        availableWorkers.erase(strongestIt);
                } else {
                    if (remainingPills == 0) return false;
                    int minStrengthNeeded = requiredStrength - strength;
                    auto boostedIt = availableWorkers.lower_bound(minStrengthNeeded);
                    if (boostedIt == availableWorkers.end()) return false;
                    if (--boostedIt->second == 0)
                        availableWorkers.erase(boostedIt);
                    remainingPills--;
                }
            }
            return true;
        };

        int l = 0, r = min(n, m), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isPossible(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
