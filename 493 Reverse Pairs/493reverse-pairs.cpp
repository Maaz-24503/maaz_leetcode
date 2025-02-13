class Solution {
public:
    vector<int> nums;
    int n;

    int merge(int i, int j){
        int mid = (i+j)/2;
        int l = mid;
        int r = j;
        int count = 0;
        for(r = j; r>=mid+1; r--){
            while(l>=i && (nums[l]/2.0) > nums[r]) l--;
            count += mid - l;
        }

        l = i, r = mid + 1;

        vector<int> temp;
        while(l<=mid || r<=j){
            if(l > mid){
                temp.push_back(nums[r]);
                r++;
            }
            else if(r > j){
                temp.push_back(nums[l]);
                l++;
            }
            else if(nums[l] <= nums[r]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[r]);
                r++;
            }
        }
        for(int t = i; t<=j; t++){
            nums[t] = temp[t - i];
        }
        return count;
    }

    int mergeSort(int i, int j){
        if(j <= i) return 0;
        int mid = (i+j)/2;
        return mergeSort(i, mid) + mergeSort(mid + 1, j) + merge(i, j);
    }

    int reversePairs(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        return mergeSort(0, n-1);
    }
};