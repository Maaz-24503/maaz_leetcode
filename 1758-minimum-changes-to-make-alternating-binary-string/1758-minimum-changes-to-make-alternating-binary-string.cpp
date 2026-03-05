class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string p1 = "1", p2 = "0";
        for(int i = 0; i < n - 1; i++){
            p1 += (p1[i] == '1') ? "0" : "1";
            p2 += (p2[i] == '1') ? "0" : "1";
        }
        int a1 = 0, a2 = 0;
        for(int i = 0; i < n; i++){
            if(p1[i] != s[i]) a1++;
            if(p2[i] != s[i]) a2++;
        }
        return min(a1, a2);
    }
};