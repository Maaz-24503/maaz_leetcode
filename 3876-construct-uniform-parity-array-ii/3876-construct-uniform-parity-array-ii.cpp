class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestEven = INT_MAX, smallestOdd = INT_MAX;
        for(int &num : nums1){
            if(num % 2) smallestOdd = min(smallestOdd, num);
            else smallestEven = min(smallestEven, num);
        }
        return smallestEven == INT_MAX || smallestOdd == INT_MAX || smallestOdd < smallestEven;
    }
};