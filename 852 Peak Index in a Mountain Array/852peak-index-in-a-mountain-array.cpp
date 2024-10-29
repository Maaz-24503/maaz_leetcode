class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        while(l<r){
            if(r-l<=10){
                while(arr[l+1]>arr[l]) l++;
                return l;
            }
            int mid = (l+r)/2;
            if(arr[mid]<arr[mid+1]) l = mid;
            else r = mid; 
        }
        return -1;
    }
};