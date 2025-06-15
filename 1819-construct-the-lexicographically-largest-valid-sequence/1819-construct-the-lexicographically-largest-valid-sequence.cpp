class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n - 1, 0);
        int lim = (1<<n) - 1;
        auto printList = [&]() -> void {
            for(int i = 0; i<2*n-1; i++) cout<<ans[i]<<" ";
            cout<<endl;
        };
        function<bool(int, int)> helper = [&](int i, int mask) -> bool {
            // printList();
            if(i == 2 * n - 1) return true;
            if(ans[i] != 0) return helper(i + 1, mask);
            int k = n;
            for(int curr = 1; curr <= lim; curr <<= 1){
                if((curr & mask) == 0){
                    if(k == 1){
                        ans[i] = 1;
                        if(helper(i + 1, mask | curr)) return true;
                        ans[i] = 0;
                    }
                    else if(i + k < 2 * n - 1 && ans[i + k] == 0){
                        ans[i] = k;
                        ans[i + k] = k;
                        if(helper(i + 1, mask | curr)) return true;
                        ans[i] = 0;
                        ans[i + k] = 0;
                    }
                }
                k--;
            }
            return false;
        };
        helper(0, 0);
        return ans;
    }
};