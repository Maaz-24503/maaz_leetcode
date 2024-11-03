class Solution {
public:

    void mergeSort(int l, int r, vector<int>& ans, vector<pair<int, int>>& tbs){
        if(r - l <= 1) return;
        int mid = (l+r)/2;
        mergeSort(l, mid, ans, tbs);
        mergeSort(mid, r, ans, tbs);

        int i = l;
        int j = mid;
        vector<pair<int, int>> aux(r-l+1);
        int curr = 0;

        while(i < mid || j < r){
            if(j == r){
                // cout<<(r - mid )<<endl;
                aux[curr] = tbs[i];
                ans[tbs[i].second] += r - mid ;
                i++;
            }
            else if(i == mid){
                aux[curr] = tbs[j];
                // ans[tbs[j].second] += mid - l - 1;
                j++;
            }
            else if(tbs[j].first >= tbs[i].first){
                // cout<<(j - mid)<<endl;
                aux[curr] = tbs[i];
                ans[tbs[i].second] += j - mid ;
                i++;
            }
            else{
                aux[curr] = tbs[j];
                // ans[tbs[j].second] += i - l - 1;
                j++;
            }
            curr++;
        }
        for(int i = l, j = 0; i<r; i++, j++) tbs[i] = aux[j];
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> temp(nums.size());
        for(int i = 0; i<nums.size(); i++){
            temp[i] = {nums[i], i};
        }
        vector<int> ans(nums.size(), 0);
        mergeSort(0, nums.size(), ans, temp);
        return ans;
    }
};