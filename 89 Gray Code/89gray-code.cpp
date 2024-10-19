class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return vector<int>{0,1};
        else{
            vector<int> prev = grayCode(n-1);
            int mask = 1<<(n-1);
            for(int i = prev.size()-1; i>=0; i--) prev.push_back(mask | prev[i]);
            return prev;
        }
    }
};