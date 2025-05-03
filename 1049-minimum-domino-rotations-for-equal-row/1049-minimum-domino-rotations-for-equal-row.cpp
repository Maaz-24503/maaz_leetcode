class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int num = -1;
        for(int i = 1; i<=6; i++){
            for(int j = 0; j <= n; j++){
                if(j == n){
                    num = i;
                    break;
                }
                if(tops[j] != i && bottoms[j] != i) break;
            }
            if(num != -1) break;
        }
        if(num == -1) return -1;
        int countTop = 0, countBottom = 0;
        for(int i = 0; i<n; i++){
            if(tops[i] == num) countTop++;
            if(bottoms[i] == num) countBottom++;
        }
        return n - max(countTop, countBottom);
    }
};