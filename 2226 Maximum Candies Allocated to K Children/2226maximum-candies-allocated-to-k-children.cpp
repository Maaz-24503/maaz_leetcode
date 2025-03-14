class Solution {
private:
    vector<int> candies;
    long long k;
    int n;

    bool isValid(int x){
        if(x == 0) return true;
        long long temp = 0;
        for(int i = 0; i<n; i++) temp += candies[i]/x;
        return temp>=k;
    }

    int binarySearch(){
        int l = 0, r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(l<=r){
            if(l == r){
                if(isValid(l)) return l;
                else return ans;
            }
            int mid = (l+r)/2;
            bool possible = isValid(mid);
            if(possible){
                l = mid+1;
                ans = mid;
            }
            else r = mid-1;
        }
        return ans;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        this->candies = candies;
        this->k = k;
        this->n = candies.size();
        return binarySearch();
    }
};