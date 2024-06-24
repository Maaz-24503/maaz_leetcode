class Solution {
public:
    string reverseWords(string s) {
        stringstream strm(s);
        string full = "";
        string temp;
        while(strm>>temp){
            full = temp+" "+full;
        }
        return full.substr(0, full.length()-1);
    }
};