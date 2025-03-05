class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i<k; i++){
            pq.push({((points[i][0] * points[i][0]) + (points[i][1] * points[i][1])), i});
        }
        vector<vector<int>> ans;
        for(int i = k; i<points.size(); i++){
            int dist = ((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            if(pq.top().first > dist){
                pq.pop();
                pq.push({dist, i});
            }
        }
        for(int i = 0; i<k; i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};