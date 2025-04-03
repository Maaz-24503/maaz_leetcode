class NumberContainers {
public:
    unordered_map<int, int> val;
    unordered_map<int, set<int>> occ;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(val.find(index) != val.end()){
            occ[val[index]].erase(index);
        }
        val[index] = number;
        occ[number].insert(index);
    }
    
    int find(int number) {
        if(occ.find(number) != occ.end() && !occ[number].empty()){
            return *occ[number].begin();
        }
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */