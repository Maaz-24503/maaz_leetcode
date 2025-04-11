class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int l = low; l<=high; l++){
            int a = l%10, b = (l%100)/10, c = (l%1000)/100, d = (l%10000)/1000;
            if(c == 0 && d == 0) count += a == b;
            else if(d != 0) count += ((c + d) == (a + b));
        }
        return high == 1e4 ? count-1 : count;
    }
};