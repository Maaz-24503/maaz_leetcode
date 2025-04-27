class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        function<int(int)> timeTaken = [&](int sp){
            int ans = 0;
            for(int i = 0; i<n; i++) ans += (piles[i] + sp - 1) / sp;
            return ans;
        };
        int l = 1, r = INT_MAX, ans = INT_MAX;
        while(l <= r){
            int mid = l + (r - l)/2;
            int time = timeTaken(mid);
            if(time > h) l = mid + 1;
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};