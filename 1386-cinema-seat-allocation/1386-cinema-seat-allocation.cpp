class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int total = 2 * n;
        int i = 0;
        while(i < reservedSeats.size()){
            set<int> curr;
            int currRow = reservedSeats[i][0];
            while(i < reservedSeats.size() && reservedSeats[i][0] == currRow) {
                curr.insert(reservedSeats[i][1]);
                i++;
            }
            bool leftDenied = false, middleDenied = false, rightDenied = false;
            if(
                curr.count(2) ||
                curr.count(3) ||
                curr.count(4) ||
                curr.count(5) 
            ) leftDenied = true;
            if(
                curr.count(4) ||
                curr.count(5) ||
                curr.count(6) ||
                curr.count(7) 
            ) middleDenied = true;
            if(
                curr.count(6) ||
                curr.count(7) ||
                curr.count(8) ||
                curr.count(9) 
            ) rightDenied = true;
            if(leftDenied && middleDenied && rightDenied) total -= 2;
            else if(leftDenied || middleDenied || rightDenied) total -= 1;
        }
        return total;
    }
};