class RandomizedSet {
public:
    unordered_map<int, int> dict;
    vector<int> lst;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(dict.find(val) != dict.end()) return false;
        lst.push_back(val);
        dict[val] = lst.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(dict.find(val) == dict.end()) return false;
        lst[dict[val]] = lst[lst.size() - 1];
        dict[lst[dict[val]]] = dict[val];
        lst.pop_back();
        dict.erase(val);
        // for(int i = 0; i<lst.size(); i++) cout<<lst[i]<<" ";
        // cout<<endl;
        return true;
    }
    
    int getRandom() {
        return lst[rand()%lst.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */