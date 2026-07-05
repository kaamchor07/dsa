class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>>pq;
    int maxsize;
public:
    KthLargest(int k, vector<int>& nums) {
        maxsize=k;
        for(int num : nums){
            pq.push(num);
            if(pq.size()>maxsize){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>maxsize){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
