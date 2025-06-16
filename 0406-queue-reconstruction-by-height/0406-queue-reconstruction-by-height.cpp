class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int n = people.size();
        vector<vector<int>> ans(n, {-1, -1});
        for(int i = 0; i<n; i++){
            int count = people[i][1];
            for(int j = 0; j<n; j++){
                if(ans[j][0] != -1 && ans[j][0] < people[i][0]) continue;
                if(count == 0) {
                    ans[j] = people[i];
                    break;
                }
                count--;
            }
        }
        return ans;
    }
};