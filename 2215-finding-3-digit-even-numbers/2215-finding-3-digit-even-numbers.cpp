class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n = digits.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(i == j || j == k || k == i || !digits[i]) continue;
                    if(digits[k] % 2 == 0) ans.insert(digits[k] + (10*digits[j]) + (100*digits[i]));
                }
            }
        }
        vector<int> vecAns(ans.begin(), ans.end());
        return vecAns;
    }
};