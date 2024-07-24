class Solution {
public:
    int helper1(int left, int right, vector<vector<int>>& matrix, int target){
        if(right-left<=1) return matrix[right][0]>target?left:right;
        int mid = (right+left) / 2;
        if(matrix[mid][0] > target) return helper1(left, mid, matrix, target);
        else if(matrix[mid][0] < target) return helper1(mid, right, matrix, target);
        else return -1;
    }
    bool bs(int left, int right, vector<int>& arr, int target){
        if(right-left<3){
            for(int i = left; i<=right; i++){
                // cout<<arr[i];
                if(arr[i] == target) return true;
            }
            return false;
        }
        int mid = (left+right)/2;
        if(arr[mid] > target) return bs(left, mid, arr, target);
        else if(arr[mid] < target) return bs(mid, right, arr, target);
        else return true;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int row = helper1(0, n-1, matrix, target);
        if(row == -1) return true;
        return bs(0, matrix[row].size() - 1, matrix[row], target);
    }
};