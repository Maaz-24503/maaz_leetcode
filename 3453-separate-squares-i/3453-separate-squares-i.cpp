class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total = 0;
        int n = squares.size();
        sort(squares.begin(), squares.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });
        for(int i = 0; i<n; i++) total += (squares[i][2] + 0LL) * squares[i][2];
        function<double(double)> areaBelow = [&](double y) -> double {
            double sum = 0;
            for(int i = 0; i<n; i++){
                if(squares[i][1] > y) break;
                sum += squares[i][2] * min(squares[i][2]*1.0, y - squares[i][1]);
            }
            return sum;
        };
        double l = 0, r = 1e9, target = (total*1.0)/2.0;
        while(r - l > 1e-6){
            double mid = r - (r - l)/2;
            if(areaBelow(mid) >= target) r = mid;
            else l = mid;
        }
        return l;
    }
};