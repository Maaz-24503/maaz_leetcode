class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> track(pairs.size(), 1);
        for(int i = 0; i<pairs.size(); i++){
            for(int j = i+1; j<pairs.size(); j++){
                if(pairs[i][0]>pairs[j][0]){
                    vector<int> temp = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = temp;
                }
            }
        }
        int globMax = 1;
        for(int i = 0; i<pairs.size(); i++){
            int max = 1;
            for(int j = 0; j<i; j++){
                if(i!=j){
                    if(pairs[i][0]>pairs[j][1]){
                        if(track[i]+track[j]>max) 
                            max = track[i] + track[j];
                    }
                }
            }
            track[i]=max;
            if(globMax<max) globMax = max;
        }
        return globMax;
    }
};