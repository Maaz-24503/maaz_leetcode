class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        function<bool(long long)> check = [&](long long guess) -> bool {
            // timeTaken = w[i] * h(h + 1)/2
            // just binary search for h as well
            int total = 0;
            for(int &t : workerTimes){
                int l = 0, r = mountainHeight, ans = 0;
                while(l <= r){
                    long long h = l + (r - l) / 2;
                    if(t*(h*(h + 1)) / 2 <= guess){
                        ans = h;
                        l = h + 1;
                    } else {
                        r = h - 1;
                    }
                } 
                total += ans;
                if(total >= mountainHeight) return true;
            }
            return total >= mountainHeight;
        };
        long long l = 1, r = 1e16, ans = 1;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};