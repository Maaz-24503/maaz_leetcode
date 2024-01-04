class Solution {
public:
    bool isPalindrome(int x) {
        string pal = to_string(x);
        for(int i = 0; i<pal.size()/2; i++){
            if(pal[i] != pal[pal.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};