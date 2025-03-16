class Solution {
private:
    vector<int> ranks; 
    int cars, n;

    bool isValid(long long x){
        long long done = 0;
        for(int i = 0; i<n; i++){
            long long curr = x / ranks[i];
            curr = sqrt(curr);
            done += curr;
        }
        return done >= cars;
    }

    long long binarySearch(){
        long long l = 0, r = (cars + 0LL)*(cars + 0LL)*(static_cast<long long>(*min_element(ranks.begin(), ranks.end())));
        long long ans = r;
        while(l<r){
            long long mid = (l + r) / 2;
            if(isValid(mid)){
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return isValid(l) ? l : ans;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        this->ranks = ranks;
        this->cars = cars;
        n = ranks.size();
        return binarySearch();
    }
};