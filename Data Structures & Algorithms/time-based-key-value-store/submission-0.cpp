class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> tm;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(tm.find(key)==nullptr)return "";
        string res="";
        auto &vec=tm[key];
        int l=0,r=vec.size()-1;
        while(l<=r){
            int mid=(r+l)/2;
            if(vec[mid].first<=timestamp){res=vec[mid].second;l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
