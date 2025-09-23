class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0, start2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        while(start1 < n1 || start2 < n2){
            int curr1 = 0, curr2 = 0;
            if(start1 < n1){
                int len = 0;
                while(start1 + len < n1 && version1[start1 + len] != '.') len++;
                curr1 = stoi(version1.substr(start1, len));
                start1 += len + 1; 
            }
            if(start2 < n2){
                int len = 0;
                while(start2 + len < n2 && version2[start2 + len] != '.') len++;
                curr2 = stoi(version2.substr(start2, len));
                start2 += len + 1; 
            }
            if(curr1 != curr2) return curr1 < curr2 ? -1 : 1;
        }
        return 0;
    }
};