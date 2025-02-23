class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int, int>> pile;
        vector<bool> isDead(asteroids.size(), false);
        for(int i = 0; i<asteroids.size(); i++){
            if(asteroids[i] < 0 && !pile.empty()){
                while(!pile.empty() && pile.top().first <= abs(asteroids[i])){
                    if(pile.top().first == abs(asteroids[i])){
                        isDead[pile.top().second] = true;
                        isDead[i] = true;
                        pile.pop();
                        break;
                    }
                    isDead[pile.top().second] = true;
                    pile.pop();
                }
                if(!pile.empty()) isDead[i] = true;
            }
            else if(asteroids[i] > 0) pile.push({asteroids[i], i});
        }
        vector<int> ans;
        for(int i = 0; i<asteroids.size(); i++) 
            if(!isDead[i]) ans.push_back(asteroids[i]);
        return ans;
    }
};