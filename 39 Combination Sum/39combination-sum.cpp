class Solution {
public:
    int n;
    vector<int> candidates;
    vector<vector<vector<vector<int>>>> memo;
    vector<vector<bool>> isDone;

    vector<vector<int>> helper(int i, int j) {
        if (j == 0)
            return {{}};
        if (i == -1)
            return {};
        if (isDone[i][j])
            return memo[i][j];
        vector<vector<int>> top = helper(i - 1, j);
        vector < vector<int>> ans;
        for (int k = 0; k < top.size(); k++) {
            ans.push_back(top[k]);
        }
        if (j - candidates[i] >= 0) {
            vector<vector<int>> left = helper(i, j - candidates[i]);
            for (int k = 0; k < left.size(); k++) {
                ans.push_back(left[k]);
                ans[k + top.size()].push_back(candidates[i]);
            }
        }
        isDone[i][j] = true;
        return memo[i][j] = ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->n = candidates.size();
        this->memo = vector<vector<vector<vector<int>>>> (n+1, vector<vector<vector<int>>>(target+1));
        this->isDone = vector<vector<bool>> (n+1, vector<bool>(target+1, false));
        return helper(n-1, target);
    }
};