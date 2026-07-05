class MedianFinder {
    priority_queue<int,vector<int>,greater<int>>right;
    priority_queue<int,vector<int>,less<int>>left;
public:
    MedianFinder() {}
    void addNum(int num) {
        left.push(num);
        if(!right.empty() && !left.empty() && right.top()<left.top()){
            right.push(left.top());
            left.pop();
        }
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }else if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        } else {
            return (left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
