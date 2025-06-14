class Solution {
public:
    int minMaxDifference(int num) {
        string maxi = to_string(num);
        string mini = maxi;
        int dig = -1, n = maxi.size();
        for(int i = 0; i<n; i++){
            if(dig == -1 && maxi[i] != '9'){
                dig = maxi[i] - '0';
                maxi[i] = '9';
            }
            else if(maxi[i] - '0' == dig) maxi[i] = '9';
        }
        dig = mini[0] - '0';
        for(int i = 0; i<n; i++){
            if(mini[i] - '0' == dig) mini[i] = '0';
        }
        return stoi(maxi) - stoi(mini);
    }
};