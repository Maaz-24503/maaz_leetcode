class Solution {
private:
    int n;

    vector<vector<int>> helper(int i, int k){
        if(k == 0) return vector<vector<int>> {{}};
        if(i > n) return vector<vector<int>> {};
        vector<vector<int>> pick = helper(i + 1, k - 1);
        for(int j = 0; j<pick.size(); j++) pick[j].push_back(i);
        vector<vector<int>> notPick = helper(i + 1, k);
        for(int j = 0; j<notPick.size(); j++) pick.push_back(notPick[j]);
        return pick;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        return helper(1, k);
    }
};