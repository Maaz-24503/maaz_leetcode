class Solution {
private:
    bool isValid(vector<vector<int>>& intrvls){
        int n = intrvls.size();
        int end = intrvls[0][1];
        int count = 0;
        for(int i = 0; i<n; i++){
            if(intrvls[i][0] >= end){
                count++;
                if(count == 2) return true;
            }
            end = max(end, intrvls[i][1]);
        }
        return false;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        if(rectangles.size() < 2) return false;
        vector<vector<int>> x;
        vector<vector<int>> y;
        for(int i = 0; i<rectangles.size(); i++){
            x.push_back({rectangles[i][0], rectangles[i][2]});
            y.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(x.begin(), x.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        sort(y.begin(), y.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        if(isValid(x)) return true;
        return isValid(y);
    }
};