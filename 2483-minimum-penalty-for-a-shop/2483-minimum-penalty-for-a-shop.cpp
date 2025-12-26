class Solution {
public:
    int bestClosingTime(string customers) {
        int ansVal = 0, sum = 0, ansInd = -1, n = customers.size();
        for(int i = 0; i<n; i++){
            char curr = customers[i];
            sum += curr == 'Y' ? 1 : -1;
            if(sum > ansVal){
                ansVal = sum;
                ansInd = i;
            }
        }
        return ansInd + 1;
    }
};