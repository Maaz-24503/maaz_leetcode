class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occ(2001, 0);
        for(auto &num:arr) occ[num + 1000]++;
        unordered_set<int> seen;
        for(auto &num:occ){
            if(num != 0 && seen.find(num) != seen.end()) return false;
            seen.insert(num);
        }
        return true;
    }
};