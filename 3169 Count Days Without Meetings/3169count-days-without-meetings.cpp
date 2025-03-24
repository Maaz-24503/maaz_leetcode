class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int end = 0;
        int count = 0;
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        for(int i = 0; i<meetings.size(); i++){
            if(meetings[i][1] >= end){
                int endTime = min(meetings[i][1], days);
                // cout<<endTime<<" "<<end<<endl;
                if(end >= meetings[i][0]) count += endTime - end;
                else count += endTime - meetings[i][0] + 1;
                end = endTime;
                if(endTime == days) break;
            }
        }
        return days - count;
    }
};