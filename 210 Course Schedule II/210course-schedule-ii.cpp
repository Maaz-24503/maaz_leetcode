class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> state;
    vector<bool> isVisited;
    queue<int> top;

    void DFS(int u){
        if(isVisited[u]) return;
        isVisited[u] = true;
        for(auto &v : adjList[u]){
            DFS(v);
        }
        top.push(u);
    }

    bool isValid(int u){
        if(state[u] == 1) return false;
        if(state[u] == 2) return true;
        state[u] = 1;
        bool ret = true;
        for(auto &v: adjList[u]){
            ret = ret && isValid(v);
        }
        state[u] = 2;
        return ret;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjList.resize(numCourses);
        state.resize(numCourses, 0);
        isVisited.resize(numCourses, false);
        for(int i = 0; i<prerequisites.size(); i++) adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for(int i = 0; i<numCourses; i++) if(!isValid(i)) return {};
        for(int i = 0; i<numCourses; i++) DFS(i);
        vector<int> ans;
        while(!top.empty()){
            ans.push_back(top.front());
            top.pop();
        }
        return ans;
    }
};