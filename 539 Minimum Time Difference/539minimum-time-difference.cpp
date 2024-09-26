class Solution {
public:
    int diff(string smaller, string larger){
        int sm_hrs = stoi(smaller.substr(0,2));
        int sm_mnts = stoi(smaller.substr(3,2));
        int lr_hrs = stoi(larger.substr(0,2));
        int lr_mnts = stoi(larger.substr(3,2));
        return ((lr_hrs - sm_hrs)*60) + (lr_mnts - sm_mnts);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int mini = diff(timePoints[timePoints.size()-1], "24:00") + diff("00:00", timePoints[0]);
        for(int i = 0; i<timePoints.size()-1; i++){
            mini = min(mini, diff(timePoints[i], timePoints[i+1]));
        }
        return mini;
    }
};