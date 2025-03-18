class Solution {
private:
    int n, maxi;
    double totalArea;
    vector<vector<int>> squares;

    double area(double x){
        double ans = 0;
        for(int i = 0; i<n; i++) ans += squares[i][2] * max(0.0, min(squares[i][2] + 0.0, x - squares[i][1]));
        return ans;
    }

    double binarySearch(){
        double l = 0, r = maxi;
        double target = totalArea/2;
        while(r - l > 0.00001){
            double mid = r - (r - l)/2;
            double deb = area(mid);
            // cout<<mid<<" "<<deb<<endl;
            if(deb >= target) r = mid;
            else l = mid;
        }
        return l;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        totalArea = 0;
        this->squares = squares;
        this->n = squares.size();
        for(int i = 0; i<n; i++){ 
            totalArea += (squares[i][2] + 0.0) * (squares[i][2] + 0.0);
            maxi = max(maxi, squares[i][1] + squares[i][2]);
        }
        return binarySearch();
    }
};