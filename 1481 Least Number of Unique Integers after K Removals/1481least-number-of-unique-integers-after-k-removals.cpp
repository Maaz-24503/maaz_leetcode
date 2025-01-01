class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++) freq[arr[i]]++;
        vector<pair<int, int>> inv;
        for(auto [key, val] : freq){
            inv.push_back({val, key});
        }
        sort(inv.begin(), inv.end());
        int rem = 0;
        while(rem < inv.size() && k >= inv[rem].first)
            k -= inv[rem++].first;
        return inv.size() - rem;
    }
};