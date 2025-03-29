class Solution {
private:
    int MOD = 1e9 + 7;

    int power(int b, long long p){
        if(p == 0) return 1;
        long long rec = power(b, p/2);
        if(p % 2 == 1){
            return static_cast<int>((((rec * rec)%MOD) * b)%MOD);
        }
        else return static_cast<int>(((rec * rec)%MOD));
    }

    vector<int> computeLeftBounds(const vector<int>& primeScore) {
    int n = primeScore.size();
    vector<int> L(n, 1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && primeScore[s.top()] < primeScore[i]) {
            s.pop();
        }
        L[i] = (s.empty() ? i + 1 : i - s.top());
        s.push(i);
    }
    return L;
}

vector<int> computeRightBounds(const vector<int>& primeScore) {
    int n = primeScore.size();
    vector<int> R(n, 1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && primeScore[s.top()] <= primeScore[i]) {
            s.pop();
        }
        R[i] = (s.empty() ? n - i : s.top() - i);
        s.push(i);
    }
    return R;
}
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScore(n, 0);
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int fact = 2;
            int count = 0;
            while (curr > 1 && fact*fact <= curr) {
                bool div = false;
                while (curr % fact == 0) {
                    curr /= fact;
                    div = true;
                }
                if(div) count++;
                fact++;
            }
            if(curr > 1) count++;
            primeScore[i] = count;
            // cout<<count<<" "; 
        }
        long long score = 1;
        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i<n; i++) maxHeap.push({nums[i], i});
        vector<int> L = computeLeftBounds(primeScore);
        vector<int> R = computeRightBounds(primeScore);
        while(k > 0 && !maxHeap.empty()){
            auto [val, ind] = maxHeap.top();
            maxHeap.pop();
            // cout<<val<<endl;
            int l = L[ind], r = R[ind];
            long long arrs = (r+0LL) * (l+0LL);
            arrs = min(k + 0LL, arrs);
            k -= static_cast<int>(arrs);
            // cout<<l<<" "<<r<<" "<<val<<endl;
            score *= power(val, arrs);
            score %= MOD;
        }
        return static_cast<int>(score);
    }
};