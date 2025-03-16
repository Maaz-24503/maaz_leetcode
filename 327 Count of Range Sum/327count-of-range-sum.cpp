class Solution {
private:
    vector<long long> preSums;
    int lower, upper, n;

    long long diff(int i, int mid, int j, int hi){
        int r1 = mid, r2 = j;
        long long count = 0;
        while(r1 >= i && r2 > mid){
            while(r1 >= i && preSums[r2] - preSums[r1] < hi) r1--;
            if(r1 >= i) count += r1 - i + 1;
            r2--;
        }
        return count;
    }

    int merge(int i, int mid, int j){
        vector<long long> aux(j - i + 1);
        int tbr = static_cast<int>(diff(i, mid, j, lower) - diff(i, mid, j, upper+1));
        int l1 = i, l2 = mid+1;
        int curr = 0;
        while(l1 <= mid || l2 <= j){
            if(l1>mid){
                aux[curr] = preSums[l2++];
            }
            else if(l2>j){
                aux[curr] = preSums[l1++];
            }
            else if(preSums[l1] <= preSums[l2]){
                aux[curr] = preSums[l1++];
            }
            else{
                aux[curr] = preSums[l2++];
            }
            curr++;
        }
        for(int ii = 0; ii<aux.size(); ii++) preSums[i + ii] = aux[ii];
        return tbr;
    }

    int mergeSort(int i, int j){
        if(i >= j) return 0;
        int mid = (i + j)/2;
        int left = mergeSort(i, mid);
        int right = mergeSort(mid+1, j);
        int mg = merge(i, mid, j);
        return left + right + mg;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n = nums.size();
        preSums.resize(n + 1, 0);
        this->upper = upper, this->lower = lower;
        n++;
        for(int i = 1; i<n; i++) preSums[i] = preSums[i - 1] + nums[i - 1];
        // for(int i = 0; i<n; i++) cout<<preSums[i]<<" ";
        // cout<<endl;
        int ans = mergeSort(0, n - 1);
        // for(int i = 0; i<n; i++) cout<<preSums[i]<<" ";
        return ans;
    }
};