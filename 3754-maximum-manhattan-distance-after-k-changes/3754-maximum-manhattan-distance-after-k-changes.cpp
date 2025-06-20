class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> pos{0, 0};
        int n = s.size(), maxi = 0;
        for(int i = 0; i<n; i++){
            char &c = s[i];
            if(c == 'N') pos[1]++;
            else if(c == 'E') pos[0]++;
            else if(c == 'W') pos[0]--;
            else pos[1]--;
            maxi = max(maxi, min(abs(pos[0]) + abs(pos[1]) + (2*k), i + 1));
        }
        return maxi;
    }
};