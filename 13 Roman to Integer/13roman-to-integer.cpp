class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> num;
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;
        int prev = 1;
        int total = 0;
        for(int i = s.size()-1; i>=0; i--){
            if(num[s[i]] < prev) total -= num[s[i]];
            else{
                total += num[s[i]];
                prev = num[s[i]];
            }
        }
        return total;
    }
};