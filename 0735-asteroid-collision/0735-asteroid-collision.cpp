class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> sim;
        for(int& num: asteroids){
            if(num>0) sim.push_back(num);
            else{
                while(sim.size() && sim[sim.size()-1]>0 && sim[sim.size()-1] < abs(num)){
                    sim.pop_back();
                }
                if(!sim.size()) sim.push_back(num);
                else if(sim[sim.size()-1] == -num) sim.pop_back();
                else if(sim[sim.size()-1] < 0) sim.push_back(num);
            }
        }
        return sim;
    }
};