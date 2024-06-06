class Solution {
public:
    bool removing(vector<int> &helper, int gs, int prev){
        if(gs==0) return true;
        int i = 0;
        while(helper[i]<=prev){
            // cout<< helper[i]<<":"<<i << " ";
            if(i<helper.size())i++;
            else return false;
        }
        // cout<< helper[i]<<":"<<i << " ";
        if(helper[i]!= prev+1) return false;
        helper.erase(helper.begin()+i);
        return removing(helper, gs-1, prev+1);
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        vector<int> helper = hand;
        sort(helper.begin(), helper.end());
        while(helper.size()>0){
            int prev = helper[0];
            helper.erase(helper.begin()+0);
            if(!removing(helper, groupSize-1, prev)) return false;
        }
        return true;
    }
};