class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;
        for(int i = 0; i<n; i++){
            char c = senate[i];
            if(c == 'D') d.push(i);
            else r.push(i);
        }
        while(!r.empty() && !d.empty()){
            if(r.front() < d.front()) r.push(n++);
            else d.push(n++);
            r.pop();
            d.pop();
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};