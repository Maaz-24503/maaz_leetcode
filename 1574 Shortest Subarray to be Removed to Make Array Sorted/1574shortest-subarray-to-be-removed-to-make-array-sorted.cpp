class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int top = 0, bottom  = n-1;
        while(top<n-1 && arr[top] <= arr[top+1]) top++;
        if(top == n-1) return 0;
        while(bottom > 0 && arr[bottom] >= arr[bottom-1]) bottom--;
        int maxi = max(top+1, n-bottom);
        int right = bottom;
        for(int i = 0; i<=top; i++){
            while(right<n && arr[right] < arr[i]) right++;
            maxi = max(maxi, (i+1) + (n-right));
        }
        return n - maxi;
    }
};