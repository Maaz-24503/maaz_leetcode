class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] == goal[0]){
                bool done = true;
                for(int j = 0; j<n; j++){
                    if(s[(i+j)%n] != goal[j]){
                        done = false;
                        break;
                    }
                }
                if(done) return true;
            }
        }
        return false;
    }
};