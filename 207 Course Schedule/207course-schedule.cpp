class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> state;

    bool DFS(int u){
        // cout<<u<<"  ";
        if(state[u] == 1) return false;
        if(state[u] == 2) return true;
        state[u] = 1;
        bool isValid = true;
        for(auto& v : adjList[u]){
            isValid = isValid && DFS(v);
        }
        state[u] = 2;
        return isValid;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        state.resize(numCourses, 0); //0 -> unvisited
        adjList.resize(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // for(int i = 0; i<adjList.size(); i++){
        //     cout<<i<<" : ";
        //     for(int j = 0; j<adjList[i].size(); j++) cout<<adjList[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int u = 0; u<numCourses; u++){
            if(state[u] == 0) if(!DFS(u)) return false;
        }
        return true;
    }
};