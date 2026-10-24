class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        pair<string, string> early, late;
        if(arriveAlice < arriveBob) {
            early = {arriveAlice, leaveAlice};
            late = {arriveBob, leaveBob};
        } else {
            late = {arriveAlice, leaveAlice};
            early = {arriveBob, leaveBob};
        }
        int ans = 0;
        int startMonth, startDay, endMonth, endDay;
        if(early.second >= late.second){
            // the entire late duration counts;
            startMonth = stoi(late.first.substr(0, 2)), startDay = stoi(late.first.substr(3, 2));
            endMonth = stoi(late.second.substr(0, 2)), endDay = stoi(late.second.substr(3, 2));
        } else {
            startMonth = stoi(late.first.substr(0, 2)), startDay = stoi(late.first.substr(3, 2));
            endMonth = stoi(early.second.substr(0, 2)), endDay = stoi(early.second.substr(3, 2));
        }
        cout<<startMonth<<" - "<<startDay<<endl;
        cout<<endMonth<<" - "<<endDay<<endl;
        if(startMonth == endMonth) return max(endDay - startDay + 1, 0);
        for(int currMonth = startMonth; currMonth <= endMonth; currMonth++) {
            if(currMonth == endMonth) ans += endDay;
            else if(currMonth == startMonth) ans += months[currMonth] - startDay + 1;
            else ans += months[currMonth];
        }
        return ans;
    }
};