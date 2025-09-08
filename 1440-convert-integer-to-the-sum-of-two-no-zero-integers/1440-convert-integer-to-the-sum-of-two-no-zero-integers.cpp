class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        function<bool(int)> isValid = [](int k){
            while(k > 0){
                if(k % 10 == 0) return false;
                k /= 10;
            }
            return true;
        };
        for(int k = 1; k < n; k++){
            if(isValid(k) && isValid(n - k)) return vector<int> {k, n - k};
        }
        return vector<int>{};
    }
};