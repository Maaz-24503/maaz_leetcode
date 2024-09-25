class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        vector<string> ans(score.size());
        for(int i = 0; i<score.size(); i++) pq.push(make_pair(score[i], i));
        int rank = 1;
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            if(rank == 1) ans[ind] = "Gold Medal"; 
            else if(rank == 2) ans[ind] = "Silver Medal";
            else if(rank == 3) ans[ind] = "Bronze Medal";
            else ans[ind] = to_string(rank);
            rank++;
        }
        return ans;
    }
};