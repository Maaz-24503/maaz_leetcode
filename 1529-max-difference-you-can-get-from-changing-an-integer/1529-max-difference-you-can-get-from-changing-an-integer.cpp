class Solution {
public:
    int maxDiff(int num) {
        string maxi = to_string(num), mini = to_string(num);
        int n = maxi.size();
        int dig = -1;
        for(int i = 0; i<n; i++){
            if(dig != -1 && maxi[i] - '0' == dig) maxi[i] = '9';
            else if(maxi[i] != '9' && dig == -1){
                dig = maxi[i] - '0';
                maxi[i] = '9';
            }
        }
        dig = -1;
        bool one = false;
        if(mini[0] - '0' > 1){
            dig = mini[0] - '0';
            one = true;
            mini[0] = '1';
        }
        for(int i = 1; i<n; i++){
            if(dig != -1 && mini[i] - '0' == dig) mini[i] = one ? '1' : '0';
            else if(dig == -1 && mini[i] != '0' && !(mini[i] == '1' && mini[0] == '1')){
                dig = mini[i] - '0';
                mini[i] = '0';
            }
        }
        return stoi(maxi) - stoi(mini);
    }
};