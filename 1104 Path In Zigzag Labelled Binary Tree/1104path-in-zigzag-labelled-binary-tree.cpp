class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        unordered_map<int, int> prev;
        vector<int> ans;
        prev[1] = -1;
        int parent = 1;
        int jump = 2;
        for(int i = 2; i<label+1; i++){
            if((i+1)%jump == 0) {
                jump = jump<<1;
                prev[i] = parent;
                parent = i;
            }
            else{
                prev[i] = parent;
                if(i%2 == 1) parent--;
            }
        }
        int node = label;
        stack<int> track;
        while(node != -1){
            track.push(node);
            node = prev[node];
        }
        while(!track.empty()){
            ans.push_back(track.top());
            track.pop();
        }
        return ans;
    }
};