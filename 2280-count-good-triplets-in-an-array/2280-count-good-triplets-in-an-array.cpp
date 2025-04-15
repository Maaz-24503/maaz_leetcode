class Solution {
private:
    vector<long long> fen;

    void initFen(int n){
        fen.assign(n + 2, 0);
    }

    void update(int i, long long val){
        i++; 
        while(i < fen.size()){
            fen[i] += val;
            i += (i & -i);
        }
    }

    long long query(int i){
        i++; 
        long long res = 0;
        while(i > 0){
            res += fen[i];
            i -= (i & -i);
        }
        return res;
    }

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for(int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }
        vector<int> gucci(n);
        for(int i = 0; i < n; i++) {
            gucci[i] = pos2[nums1[i]];
        }
        
        // In this new array, we now find for each element
        // the number of elements smaller than it to its left,
        // the number of elements larger than it to its right.
        // Then its a matter of summing up smallLeft*largeRight.
        
        // Jst realized how long thats gonna take, so switching it 
        // to a fenwick tree approach, for every number we encounter,
        // we add one on that index to the fenwick tree array (1 - indexed)
        // this way when we go to take the prefix sum we know the numbers smaller 
        // than the current number weve seen so far

        for(int i = 0; i < n; i++) cout << gucci[i] << " ";
        cout << endl;
        
        initFen(n);
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            long long left = query(gucci[i]);
            long long right = (n - 1 - gucci[i]) - (i - left);
            ans += left * right;
            update(gucci[i] + 1, 1);
        }
        
        return ans;
    }
};