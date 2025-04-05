class Solution {
private:
    string str1, str2;
    int n1, n2;

    bool isValid(int m){
        if(m > n1) return false;
        if(n1 % m != 0 || n2 % m != 0) return false;
        for(int i = 0; i<n1; i += m){
            for(int j = 0; j<m; j++) if(str1[j] != str1[i+j]) return false;
        }
        for(int i = 0; i<n2; i += m){
            for(int j = 0; j<m; j++) if(str1[j] != str2[i+j]) return false;
        }
        return true;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size()) swap(str1, str2);
        this->str1 = str1;
        this->str2 = str2;
        n1 = str1.size();
        n2 = str2.size();
        int maxi = 0;
        for(int k = 1; k<=n1+1; k++) if(isValid(k)) maxi = k;
        return str1.substr(0, maxi);
    }
};