class Solution {
private:
    vector<vector<int>> helper(int k, int n, int j){
        if(n == 0 && k == 0) return vector<vector<int>> {{}};
        if(n < 0 || k == 0 || j == 0) return vector<vector<int>> {};
        int comp = 1;
        vector<vector<int>> pick = helper(k - 1, n - j, j - 1);
        for(int i = 0; i<pick.size(); i++) pick[i].push_back(j);
        vector<vector<int>> notPick = helper(k, n, j - 1);
        for(int i = 0; i<notPick.size(); i++) pick.push_back(notPick[i]);
        return pick;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return helper(k, n, 9);
    }
};