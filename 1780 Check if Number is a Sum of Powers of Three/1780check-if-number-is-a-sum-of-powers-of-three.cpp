class Solution {
public:
    unordered_set<int> used;
    bool checkPowersOfThree(int n) {
        if(n == 0) return true;
        if(n == 2) return false;
        int pw = 1;
        while(3*pw<=n) pw *= 3;
        if(used.find(pw) != used.end()) return false;
        used.insert(pw);
        return checkPowersOfThree(n - pw);
    }
};