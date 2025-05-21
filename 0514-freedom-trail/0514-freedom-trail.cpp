class Solution {
private:
    int n, m;
    vector<vector<int>> memo;
    string ring, key;

    int nearestLeft(int i, int j){
        int count = 0;
        while(ring[i] != key[j]){
            i = (i - 1 + n) % n;
            count++;
        }
        return count;
    }
    
    int nearestRight(int i, int j){
        int count = 0;
        while(ring[i] != key[j]){
            i = (i + 1) % n;
            count++;
        }
        return count;
    }

    int helper(int i, int j){
        if(j == m) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(ring[i] == key[j]) return memo[i][j] = 1 + helper(i, j + 1);
        int countLeft = nearestLeft(i, j);
        int countRight = nearestRight(i, j);
        return memo[i][j] = min(countLeft + 1 + helper((i - countLeft + n) % n, j + 1), countRight + 1 + helper((i + countRight) % n, j + 1));
    }
public:
    int findRotateSteps(string ring, string key) {
        n = ring.size(), m = key.size();
        this->ring = ring;
        this->key = key;
        memo.resize(n, vector<int> (m, -1));
        return helper(0, 0);
    }
};