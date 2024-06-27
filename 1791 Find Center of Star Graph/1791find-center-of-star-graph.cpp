class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> track;
        for(int i = 0; i<edges.size(); i++){
            if(track.find(edges[i][0]) == track.end()){
                track.insert(edges[i][0]);
            }
            else return edges[i][0];
            if(track.find(edges[i][1]) == track.end()){
                track.insert(edges[i][1]);
            }
            else return edges[i][1];
        }
        return edges[0][0];
    }
};