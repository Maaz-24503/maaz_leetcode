class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<int>> hrs(11);
        vector<vector<int>> mins(11);
        function<int(int)> countBits = [&](int a) -> int {
            int mask = 1, ans = 0;
            while(mask <= a){
                if((mask & a) != 0) ans++;
                mask <<= 1;
            }
            return ans;
        };
        for(int i = 0; i < 12; i++)
            hrs[countBits(i)].push_back(i);
        
        for(int i = 0; i < 60; i++)
            mins[countBits(i)].push_back(i);
        
        vector<string> ans;

        for(int i = 0; i <= turnedOn; i++){
            int hrBits = i, minBits = turnedOn - i;
            for(int &hr : hrs[hrBits]){
                for(int &min: mins[minBits]){
                    string strHour = to_string(hr);
                    string strMin = min > 9 ? to_string(min) : "0" + to_string(min);
                    ans.push_back(strHour + ":" + strMin);
                }
            }
        }
        return ans;
    }
};