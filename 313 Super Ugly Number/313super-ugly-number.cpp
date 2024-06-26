class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ind(primes.size(), 0);
        vector<long long> memo(n, 1);
        for(int i = 1; i<n; i++){
            int minInd = 0;
            long long minVal = LLONG_MAX;
            for(int j = 0; j<primes.size(); j++){
                // if(i>42) cout<<primes[j]<<" "<<memo[ind[j]] * primes[j]<<endl;
                long long curr = memo[ind[j]] * primes[j]; 
                if(curr == memo[i-1]){
                    ind[j]++;
                    curr = memo[ind[j]] * primes[j];
                }
                if(curr<minVal){
                    minVal = curr;
                    minInd = j;
                }
            }
            memo[i] = minVal;
            ind[minInd]++;
        }
        // for(int i = 0; i<n; i++) cout<<memo[i]<<" ";
        return memo[n-1];
    }
};