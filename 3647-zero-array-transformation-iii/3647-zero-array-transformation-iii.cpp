class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> track(n + 1, 0);    // To keep track of how many to reduce
        sort(queries.begin(), queries.end());
        int counted = 0, done = 0;
        int q = 0;
        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            done -= track[i];
            while(q < m && queries[q][0] == i) pq.push(queries[q++][1]);
            while(done < nums[i]){
                if(pq.empty() || pq.top() < i) return -1;
                done++;
                counted++;
                track[pq.top() + 1]++;
                pq.pop();
            }
        }
        return m - counted;
    }
};