class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> store;
        int count = 0;
        for(int i = 0; i<time.size(); i++){
            int curr = time[i]%60;
            if(store.find((60 - curr)%60) != store.end()){
                count += store[(60 - curr)%60];
            }
            if(store.find(curr) == store.end()) store[curr] = 1;
            else store[curr]++;
        }
        return count;
    }
};