class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> temp(n);
        for(int i = 0; i<n; i++) temp[i] = {arr[i], i};
        sort(temp.begin(), temp.end());
        for(int i = 0; i<n; i++) arr[temp[i].second] = i;
        int chunks = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, arr[i]);
            if(maxi == i) chunks++;
        }
        return chunks;
    }
};