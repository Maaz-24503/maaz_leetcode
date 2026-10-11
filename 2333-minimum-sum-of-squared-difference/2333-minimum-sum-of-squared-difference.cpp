class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<long long> diff(n);
        long long total = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, (int)diff[i]);
        }

        if (total <= k) return 0;

        auto cost = [&](long long m) -> long long {
            long long uses = 0;
            for (long long p : diff) uses += max(0LL, p - m);
            return uses;
        };

        long long l = 0, r = mx;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (cost(mid) <= k) r = mid;
            else l = mid + 1;
        }
        long long top = l;

        long long leftover = k - cost(top);

        long long ans = 0;
        for (long long p : diff) {
            long long v = min(top, p);
            ans += v * v;
        }

        ans -= leftover * (2 * top - 1);
        return ans;
    }
};