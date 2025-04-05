class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size();
        for(int i = 0; i<k; i++){
            if((i == 0 || flowerbed[i-1] == 0) && (i == k-1 || flowerbed[i+1] == 0) && (flowerbed[i] == 0)) {
                cout<<i<<" ";
                n--;
                i++;
            }
        }
        return n <= 0;
    }
};