class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        function<long long(long long)> countProductsLessEqual = [&](long long target) -> long long {
            long long count = 0;
            for (int i = 0; i < n; i++) {
                if (nums1[i] > 0) {
                    // For positive nums1[i], we want nums2[j] <= target/nums1[i]
                    // Use binary search to find the rightmost valid position
                    int left = 0, right = m - 1;
                    while (left <= right) {
                        int mid = (left + right) / 2;
                        if ((long long)nums1[i] * nums2[mid] <= target) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                    count += right + 1;
                } else if (nums1[i] < 0) {
                    // For negative nums1[i], we want nums2[j] >= target/nums1[i]
                    // Use binary search to find the leftmost valid position
                    int left = 0, right = m - 1;
                    while (left <= right) {
                        int mid = (left + right) / 2;
                        if ((long long)nums1[i] * nums2[mid] <= target) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }
                    }
                    count += m - left;
                } else {
                    // nums1[i] == 0, product is always 0
                    if (target >= 0) {
                        count += m;
                    }
                }
            }
            return count;
        };
        
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProductsLessEqual(mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};