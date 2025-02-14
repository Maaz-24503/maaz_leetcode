class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(minHeap.size() == 0){
            if(maxHeap.size()>1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else{
            if(maxHeap.top() > minHeap.top()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            if(maxHeap.size() < minHeap.size() - 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else if(minHeap.size() < maxHeap.size() - 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) return ((minHeap.top()+maxHeap.top())*1.0)/2.0;
        if(minHeap.size() < maxHeap.size()) return maxHeap.top()*1.0;
        return minHeap.top()*1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */