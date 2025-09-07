class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        int l = (n / 2) - 1, r = n % 2 ? n / 2 + 1 : n / 2;
        int num = 1;
        while(l >= 0 && r < n){
            ans[l--] = -num;
            ans[r++] = num++;
        }
        return ans;
    }
};