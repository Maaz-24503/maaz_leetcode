class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = ((int)height.size()) - 1;
        int ans = 0;
        while(l < r){
            ans = max(min(height[l], height[r]) * (r - l), ans);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};