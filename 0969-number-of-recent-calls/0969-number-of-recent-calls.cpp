class RecentCounter {
public:
    deque<int> pings;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!pings.empty() && pings.front()<t-3000) pings.pop_front();
        pings.push_back(t);
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */