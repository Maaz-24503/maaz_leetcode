class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, set<int>> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]].insert(i);
        queue<pair<int, int>> bfs;
        vector<int> isVisited(n, false); isVisited[0] = true;
        bfs.push({0, 0});
        while(bfs.size()){
            auto [moves, curr] = bfs.front(); bfs.pop();
            if(curr == n - 1) return moves;
            if(curr != 0 && !isVisited[curr - 1]) {
                isVisited[curr - 1] = true;
                bfs.push({moves + 1, curr - 1});
                mp[arr[curr - 1]].erase(curr - 1);
            }
            if(!isVisited[curr + 1]) {
                isVisited[curr + 1] = true;
                bfs.push({moves + 1, curr + 1});
                mp[arr[curr + 1]].erase(curr + 1);
            }
            if(mp.find(arr[curr]) != mp.end())
                for(const int &nxt : mp[arr[curr]]){
                    if(!isVisited[nxt]){
                        isVisited[nxt] = true;
                        bfs.push({moves + 1, nxt});
                    }
                }
            mp.erase(arr[curr]);
        }
        return -1;
    }
};