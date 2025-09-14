class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        auto toLower = [](const string& s) {
            string t = s;
            for (char &c : t) c = tolower(c);
            return t;
        };
        auto isVowel = [](char c) {
            c = tolower(c);
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        auto deVowel = [&](const string& s) {
            string t = s;
            for (char &c : t) if (isVowel(c)) c = '*';
            return t;
        };

        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;

        for (auto &w : wordlist) {
            string lower = toLower(w);
            string dev   = deVowel(lower);
            if (!caseMap.count(lower))  caseMap[lower]  = w;
            if (!vowelMap.count(dev))   vowelMap[dev]   = w;
        }

        vector<string> res;
        for (auto &q : queries) {
            if (exact.count(q)) { res.push_back(q); continue; }
            string lower = toLower(q);
            string dev   = deVowel(lower);
            if (caseMap.count(lower))      res.push_back(caseMap[lower]);
            else if (vowelMap.count(dev))  res.push_back(vowelMap[dev]);
            else                           res.push_back("");
        }
        return res;
    }
};
