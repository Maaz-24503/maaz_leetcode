class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        if(n != target.size()) return false;
        int st = 0, tar = 0;
        while(st<n && tar<n){
            while(st<n && start[st] == '_') st++;
            while(tar<n && target[tar] == '_') tar++;
            if(tar == n || st == n) break;
            if(target[tar] != start[st]) return false;
            if(target[tar] == 'L' && st<tar) return false;
            if(target[tar] == 'R' && st>tar) return false;
            st++; tar++;
        }
        while(st<n) {
            if(start[st] != '_') return false;
            st++;
        }
        while(tar<n) {
            if(target[tar] != '_') return false;
            tar++;
        }
        return true;
    }
};