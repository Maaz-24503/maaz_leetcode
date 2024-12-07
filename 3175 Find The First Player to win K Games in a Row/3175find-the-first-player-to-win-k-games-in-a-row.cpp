class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        queue<pair<int, int>> q;
        for(int i = 0; i<skills.size(); i++){
            q.push({skills[i], i});
        }
        int curr = 0;
        auto [plrScore, plr] = q.front();
        q.pop();
        while(true){
            auto [score, idx] = q.front();
            q.pop();
            if(k == curr || curr == skills.size()) return plr;
            if(score<plrScore){ 
                curr++;
                q.push({score, idx});
            }
            else{
                q.push({plrScore, idx});
                curr = 1;
                plrScore = score;
                plr = idx;
            }
        }
        return -1;
    }
};