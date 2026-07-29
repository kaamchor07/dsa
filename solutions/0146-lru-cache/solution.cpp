class LRUCache {
private:
unordered_map<int,list<pair<int,int>>::iterator>m;
list<pair<int,int>>cache;
int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        cache.splice(cache.begin(),cache,m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {

        if(m.find(key)!=m.end()){
            m[key]->second=value;
            cache.splice(cache.begin(),cache,m[key]);
            return;
        }
        if(cache.size()==cap){
            int lru_key=cache.back().first;
            cache.pop_back();
            m.erase(lru_key);
        }
        cache.push_front({key,value});
        m[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
