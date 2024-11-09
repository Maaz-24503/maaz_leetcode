class Solution {
public:
    long long fixIncr(long long ans, int inc, int jump){
        long long mask2 = 1;
        for(long long mask = 1; mask<=ans; mask <<= 1){
            while((mask2 & ans) != 0) mask2 <<= 1;
            if((inc & mask) != 0) ans |= mask2;
            mask2 <<= 1;
        }
        // cout<<ans;
        return ans;
    }
    long long minEnd(int n, int x) {
        int highestBit;
        for(highestBit = 1<<30; highestBit>0; highestBit >>= 1)
            if((highestBit & x) != 0) break;
        int highestBitCount = 0;
        for(int mask = 1; mask<highestBit; mask <<= 1) highestBitCount++;
        // cout<<highestBitCount<<endl;
        int jump = 0;
        int temp = 0;
        for(int mask = 1; mask<highestBit; mask <<= 1){
            if((mask & x) == 0){
                jump |= mask;
                temp++; 
            }
        }
        long long ones = (n-1);
        long long incr = 0;
        if(temp != 0){
            int count = 1<<temp;
            // cout<<"count: "<<count<<endl;
            ones = (n-1)/count;
            incr = (n-1)%count;
        }
        long long ans = 0;
        ans |= x;
        // cout<<incr<<" "<<ones<<endl;
        if(temp != 0) ans = fixIncr(ans, incr, jump);
        ones <<= (highestBitCount+1);
        return ans|ones;
    }
};