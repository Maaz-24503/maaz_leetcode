class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        for(int i = 1; i<n; i++){
            left[i] = max(left[i-1], height[i-1]);
            right[n - i - 1] = max(right[n - i], height[n - i]);
        }
        int water = 0;
        for(int i = 0; i<n; i++){
            int level = min(left[i], right[i]);
            if(level > height[i]) water += level - height[i];
        }
        return water;
    }
};