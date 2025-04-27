class Solution {
public:
    int tribonacci(int n) {
        if(n <= 2) return n == 2 ? 1 : n;
        int a0 = 0, a1 = 1, a2 = 1;
        for(int i = 0; i<n-2; i++){
            int temp = a2;
            a2 = a1 + a0 + a2;
            a0 = temp;
            swap(a0, a1);
        }
        return a2;
    }
};