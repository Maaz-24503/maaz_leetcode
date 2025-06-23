class Solution {
public:
    long long kMirror(int k, int n) {
        function<bool (long long)> isPalindrome = [&](long long x) {
            vector<int> num(101);
            int sz = -1;
            while (x) {
                sz++;
                num[sz] = x % k;
                x /= k;
            }
            for (int i = 0, j = sz; i < j; i++, j--) {
                if (num[i] != num[j]) {
                    return false;
                }
            }
            return true;
        };
        
        int curr = 1, count = 0;
        long long sum = 0LL;
        bool oddLength = true;
        
        while(count < n){
            string num = to_string(curr);
            string rev = oddLength ? num.substr(0, num.size() - 1) : num;
            reverse(rev.begin(), rev.end());
            num = num + rev;
            long long finalNum = stoll(num);
            
            if(isPalindrome(finalNum)) {
                sum += finalNum; 
                count++;
            }

            if(oddLength) {
                string temp = to_string(curr + 1);
                if(temp.length() > to_string(curr).length()) {
                    oddLength = false;
                    curr = pow(10, to_string(curr).length() - 1);
                } 
                else curr++;
            } 
            else {
                string temp = to_string(curr + 1);
                if(temp.length() > to_string(curr).length()) {
                    oddLength = true;
                    curr = pow(10, to_string(curr).length());
                } 
                else curr++;
            }
        }
        return sum;
    }
};