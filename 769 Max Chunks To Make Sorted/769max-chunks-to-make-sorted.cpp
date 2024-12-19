class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<arr.size(); i++){
            maxi = max(maxi, arr[i]);
            if(maxi == i) chunks++;
        }
        return chunks;
    }
};