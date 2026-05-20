class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n + 1, 0), ans(n, 0);
        for(int i = 0; i < n; i++){
            int a = A[i], b = B[i];
            count[a]++;
            count[b]++;
            if(i != 0) ans[i] = ans[i - 1];
            if(count[a] == 2) ans[i]++;
            if(count[b] == 2 && a != b) ans[i]++;
        }
        return ans;
    }
};