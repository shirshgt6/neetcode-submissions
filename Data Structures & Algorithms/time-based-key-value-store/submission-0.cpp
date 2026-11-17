class TimeMap {
public:
    map<string,map<int,string>>mp;
    TimeMap() {
     
    }
    void set(string key, string value, int timestamp) {
      mp[key][timestamp]=value;
    }
    void cal(string key,int timestamp,string &ans){
        if(mp.find(key)==mp.end())
        return;
        auto &temp=mp[key];
            auto it=temp.upper_bound(timestamp);
            if(it!=temp.begin()){
                it--;
                ans=it->second;
            }   
    }
    string get(string key, int timestamp) {
        /*if(mp1.find(timestamp)){
            return mp[mp1[timestamp]];
        }*/
        string ans="";
      
        cal(key,timestamp,ans);
        return ans;
    }
};

