class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int l = 0, r = 0;
        int lState = -1; 
        while(r<n){
            if(lState == -1){
                if(dominoes[r] == '.') {
                    r++;
                    continue;
                }
                else if(dominoes[r] == 'R'){
                    lState = 0;
                    l = r;
                    r++;
                }
                else if(dominoes[r] == 'L'){
                    lState = 1;
                    while(l<=r) dominoes[l++] = 'L';
                    r++;
                }
            }
            else if(lState == 0){
                if(dominoes[r] == '.') {
                    r++;
                    continue;
                }
                else if(dominoes[r] == 'R'){
                    while(l<=r) dominoes[l++] = 'R';
                    l--;
                    r++;
                }
                else if(dominoes[r] == 'L'){
                    lState = 1;
                    int lt = l+1, rt = r-1;
                    while(lt<rt){ 
                        dominoes[lt++] = 'R';
                        dominoes[rt--] = 'L';
                    }
                    l = r;
                    r++;
                }
            }
            else{
                if(dominoes[r] == '.') {
                    r++;
                    continue;
                }
                else if(dominoes[r] == 'R'){
                    lState = 0;
                    l = r;
                    r++;
                }
                else{
                    while(l<r) dominoes[l++] = 'L';
                    l = r;
                    r++;
                }
            }
        }
        while(l<n && lState == 0) dominoes[l++] = 'R';
        return dominoes;
    }
};