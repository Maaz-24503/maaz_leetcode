struct comp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        int l = 0, r = n-1;
        
        for(int i = 0; i < candidates && l <= r; i++) {
            pq.push({costs[l], l});
            l++;
        }
        
        for(int i = 0; i < candidates && l <= r; i++) {
            pq.push({costs[r], r});
            r--;
        }

        long long ans = 0;
        for(int i = 0; i<k; i++){
            auto [num, ind] = pq.top();
            pq.pop();
            ans += num;
            if(l <= r){
                if(ind < l){
                    pq.push({costs[l], l}); l++;
                }
                else{
                    pq.push({costs[r], r}); r--;
                }
            }
        }
        return ans;
    }
};