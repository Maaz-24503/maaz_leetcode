class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> elems;
        for(int i = 0; i<arr.size(); i++){
            if(elems.find(arr[i]) == elems.end()) elems[arr[i]] = 1;
            else elems[arr[i]]++;
        }
        for(int i = 0; i<arr.size(); i++){
            if(elems.find(target[i]) == elems.end() || elems[target[i]] == 0) return false;
            else elems[target[i]]--;
        }
        return true;
    }
};