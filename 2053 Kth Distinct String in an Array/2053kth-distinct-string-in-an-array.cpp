class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> once;
        unordered_set<string> twice;
        int count = 0;
        for(int i = 0; i<arr.size(); i++){
            if(once.find(arr[i]) == once.end()) once.insert(arr[i]);
            else twice.insert(arr[i]);
        }
        for(int i = 0; i<arr.size(); i++){
            if(twice.find(arr[i]) == twice.end()) count++;
            if(count == k) return arr[i];
        }
        return "";
    }
};