class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(),
             [](const int a, const int b) { return a > b; });
        int n = happiness.size();
        long long ans = 0LL;
        for(int i = 0; i<k; i++) ans += max(0, happiness[i] - i);
        return ans;
    }
};