class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>>store; //key->{timestamp,value}
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end())return "";
        const auto& values=store[key];
        int high=values.size()-1;
        int low=0;
        int mid;
        string floor;
        while(high>=low){
            mid=low+(high-low)/2;
            if(values[mid].first>timestamp){
                high=mid-1;
            }else if(values[mid].first==timestamp){
                return values[mid].second;
            }else{
                low=mid+1;
                floor=values[mid].second;
            }
        }
        return floor;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
