class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> isVisited(n, false);
        queue<int> bfs;
        bfs.push(start);
        isVisited[start] = true;
        while(bfs.size()){
            int curr = bfs.front(); bfs.pop();
            if(arr[curr] == 0) return true;
            if(curr >= arr[curr] && !isVisited[curr - arr[curr]]){
                isVisited[curr - arr[curr]] = true;
                bfs.push(curr - arr[curr]);
            }
            if(curr + arr[curr] < n && !isVisited[curr + arr[curr]]){
                isVisited[curr + arr[curr]] = true;
                bfs.push(curr + arr[curr]);
            }
        }
        return false;
    }
};