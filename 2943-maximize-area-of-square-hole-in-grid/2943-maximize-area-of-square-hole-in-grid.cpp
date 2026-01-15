class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxH = 1, maxV = 1, curr = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] == hBars[i - 1] + 1) curr++;
            else curr = 1;
            maxH = max(curr, maxH);
        }
        curr = 1;
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] == vBars[i - 1] + 1) curr++;
            else curr = 1;
            maxV = max(curr, maxV);
        }
        int k = min(maxH, maxV);
        return (k + 1) * (k + 1);
    }
};