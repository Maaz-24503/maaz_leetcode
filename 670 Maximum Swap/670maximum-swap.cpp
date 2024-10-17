class Solution {
public:
    int maximumSwap(int num) {
        string numb = to_string(num);
        int maxi = -1;
        int maxiP = -1;
        int maxInd = -1;
        int last = -1;
        if(numb.size()<2) return num;
        for(int i = numb.size()-1; i>=0; i--){
            if(numb[i] < maxi){
                maxiP = maxInd;
                last = i;
            }
            if(numb[i] > maxi){
                maxi = numb[i];
                maxInd = i;
            }
        }
        if(last == -1) return num;
        char temp = numb[last];
        numb[last] = numb[maxiP];
        numb[maxiP] = temp;
        return stoi(numb);
    }
};