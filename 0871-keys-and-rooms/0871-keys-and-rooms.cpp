class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> isVisited(n, false);
        function<void(int)> dfs = [&](int u){
            if(isVisited[u]) return;
            isVisited[u] = true;
            for(int& v : rooms[u]) dfs(v);
        };
        dfs(0);
        for(int i = 0; i<n; i++) if(!isVisited[i]) return false;
        return true;
    }
};