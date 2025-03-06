class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> vis;
        long long count = 0, curr = -1;
        pq.push(1);
        while(count < n){
            curr = pq.top();
            // cout<<curr<<" ";
            pq.pop();
            count++;
            if(vis.find(2LL*curr) == vis.end()){
                pq.push(2LL*curr);
                vis.insert(2LL*curr);
            }
            if(vis.find(3LL*curr) == vis.end()){
                pq.push(3LL*curr);
                vis.insert(3LL*curr);
            }
            if(vis.find(5LL*curr) == vis.end()){
                pq.push(5LL*curr);
                vis.insert(5LL*curr);
            }
        }
        return static_cast<int>(curr);
    }
};