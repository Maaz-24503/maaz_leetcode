class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n-1;
        while(l<r){
            int curr = min(height[l], height[r]);
            ans = max(ans, (r - l)*curr);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};