class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban;
        int curr = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i<banned.size(); i++) ban.insert(banned[i]);
        while(sum<maxSum && curr<=n){
            if(ban.find(curr) == ban.end()){
                sum += curr;
                if(sum>maxSum) break;
                count++;
            }
            curr++;
        }
        return count;
    }
};