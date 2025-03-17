class Solution {
private:
    int bs(vector<int>& citations){
        int l = 0, r = citations.size()-1, ans = citations.size()-1;
        while(l<=r){
            if(l == r){
                if(citations[l] >= citations.size() - l) return citations.size() - l;
                break;
            }
            int mid = (l + r) / 2;
            if(citations[mid] >= citations.size() - mid){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return citations[ans] >= citations.size() - ans ? citations.size() - ans : 0;
    }
public:
    int hIndex(vector<int>& citations) {
        return bs(citations);
    }
};