class TimeMap {
public:
 unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int,string>temp={timestamp,value};
        mp[key].push_back(temp);
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        auto &temp=mp[key];
       // sort(temp.begin(),temp.end());
        int n=temp.size();
        int l=0,h=n-1;
        string ans="";
        while(l<=h){
            int m=l+(h-l)/2;
            if(temp[m].first<=timestamp){
                ans=temp[m].second;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */