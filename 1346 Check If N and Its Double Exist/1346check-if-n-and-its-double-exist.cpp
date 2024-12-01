class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> vis;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]%2 == 0 && (vis.find(arr[i]/2) != vis.end())) return true;
            else if(vis.find(arr[i]*2) != vis.end()) return true;
            else vis.insert(arr[i]);
        }
        return false;
    }
};