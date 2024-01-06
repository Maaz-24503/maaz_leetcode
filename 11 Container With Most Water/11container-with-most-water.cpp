class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left<right){
            int curr = min(height[left], height[right]) * (right - left);
            printf("%d\n",curr);
            if(curr>maxArea) maxArea = curr;
            if(height[left]>height[right]) right--;
            else left++;
        }
        return maxArea;
    }
};