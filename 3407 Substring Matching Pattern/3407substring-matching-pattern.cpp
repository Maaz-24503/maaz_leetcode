class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find("*");
        string pre, post;

        if(star != 0) pre = p.substr(0, star);
        else pre = "";
        
        if(star == p.size() - 1) post = "";
        else post = p.substr(star+1);

        uint l = s.find(pre);
        if(l<s.size()){
            if(post == "") return true;
            string temp = s.substr(l + pre.size());
            if(temp.find(post) < temp.size()) return true;
            return false;
        }
        return false;
    }
};