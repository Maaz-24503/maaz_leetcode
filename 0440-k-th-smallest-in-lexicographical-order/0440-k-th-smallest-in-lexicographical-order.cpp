class Solution {
public:
    int findKthNumber(int n, int k) {
        function<int(long long)> segment = [&](long long pre){
            long long beg = pre, end = pre+1;
            int count = 0;
            while(beg <= n){
                count += min(n + 1LL, end) - beg;
                beg *= 10;
                end *= 10;
            }
            return count;
        };
        
        int ans = 1;
        k--;
        while(k > 0){
            int curr = segment(ans);
            if(curr <= k){
                ans++;      // because this prefix doesnt contain answer
                k -= curr;
            }
            else{
                ans *= 10;      // Answer exists in this prefix
                k--;
            }
        }

        return ans;
    }
};