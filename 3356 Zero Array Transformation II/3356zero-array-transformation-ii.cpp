class Solution {
private:
    vector<int> nums;
    vector<vector<int>> queries;
    int n;

    bool isValid(int k){
        vector<int> diff(n, 0);
        for(int i = 0; i<=k; i++){
            diff[queries[i][0]] -= queries[i][2];
            if(queries[i][1] != n-1) diff[queries[i][1] + 1] += queries[i][2];
        }
        for(int i = 1; i<n; i++) diff[i] += diff[i-1];
        for(int i = 0; i<n; i++) if(diff[i] + nums[i] > 0) return false;
        return true;
    }

    int bs(){
        int l = 0, r = queries.size() - 1;
        while(l<r){
            int mid = (l + r)/2;
            // cout<<mid<<endl;
            bool check = isValid(mid);
            if(check) r = mid;
            else l = mid + 1;
        }
        bool check = isValid(l);
        return check?l+1:-1;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        this->nums = nums;
        this->queries = queries;
        this->n = nums.size();
        bool valid = true;
        for(int i = 0; i<n; i++){
            if(nums[i] > 0){
                valid = false;
                break;
            }
        }
        if(valid) return 0;
        return bs();
    }
};