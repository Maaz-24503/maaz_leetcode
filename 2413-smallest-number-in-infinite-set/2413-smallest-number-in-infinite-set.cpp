class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<>> minpq;
    unordered_set<int> added;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(minpq.empty()) return this->curr++;
        else{
            int temp = minpq.top();
            minpq.pop();
            added.erase(temp);
            return temp;
        }
    }
    
    void addBack(int num) {
        if(num < curr && !added.count(num)) {
            minpq.push(num);
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */