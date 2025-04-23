class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int guessIndex = rand() % n;
        int pivot = nums[guessIndex];

        vector<int> larger, equal, smaller;

        for (int& num : nums) {
            if (num > pivot) larger.push_back(num);
            else if (num == pivot) equal.push_back(num);
            else smaller.push_back(num);
        }

        if (k <= larger.size()) return findKthLargest(larger, k);
        else if (k <= larger.size() + equal.size()) return pivot;
        return findKthLargest(smaller, k - larger.size() - equal.size());
    }
};
