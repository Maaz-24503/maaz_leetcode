class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> updatedList(edges.size());
        vector<vector<pair<int, double>>> edgeList(n, vector<pair<int, double>>(0));

        for(int i = 0; i<edges.size(); i++){
            updatedList[i] = log10(succProb[i]) ;
        }

        for(int i = 0; i<edges.size(); i++){
            edgeList[edges[i][0]].push_back({edges[i][1], updatedList[i]});
            edgeList[edges[i][1]].push_back({edges[i][0], updatedList[i]});
        }

        // for(int i = 0; i< edgeList.size(); i++){
        //     for(int j = 0; j< edgeList[i].size(); j++){
        //         cout<<edgeList[i][j].first<<": "<<edgeList[i][j].second<<", ";
        //     }
        //     cout<<endl;
        // }

        priority_queue<pair<double, int>> ucs;
        vector<bool> isVisited(n ,false);
        for(int i = 0; i< edgeList[start_node].size(); i++){
            ucs.push({edgeList[start_node][i].second, edgeList[start_node][i].first});
        }
        while(!ucs.empty()){
            pair<double, int> curr = ucs.top();
            // cout<<"the top is: "<<curr.second<<", "<<curr.first<<endl;
            ucs.pop();
            if(curr.second == end_node) return pow(10, curr.first);
            if(!isVisited[curr.second]){
                isVisited[curr.second] = true;
                for(int i = 0; i < edgeList[curr.second].size(); i++){
                    if(!isVisited[edgeList[curr.second][i].first]){
                        ucs.push({curr.first + edgeList[curr.second][i].second, edgeList[curr.second][i].first});
                    }
                }
            }
        }
        return 0;
    }
};