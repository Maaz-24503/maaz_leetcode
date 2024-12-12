class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> g;
        for(int i = 0; i<gifts.size(); i++) g.push(gifts[i]);
        for(int i = 0; i<k; i++){
            int curr = g.top();
            g.pop();
            curr = (int)sqrt(curr);
            g.push(curr);
        }
        long long ans = 0;
        while(!g.empty()){
            ans += g.top();
            g.pop();
        }
        return ans;
    }
};