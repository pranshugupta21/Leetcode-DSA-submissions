class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>v;
        unordered_map<int,int>mp;
        vector<int>res;
        int i=0;
        for (auto& interval : intervals) {
             int s = interval[0];
             int e = interval[1];
              mp[s]=i;
               v.push_back(s);
              i++;
        }
        sort(v.begin(),v.end());
            for (auto& interval : intervals) {
             int s = interval[0];
             int e = interval[1];
            auto it=lower_bound(v.begin(),v.end(),e);
            if(it!=v.end()){
                int idx=(it-v.begin());
                res.push_back(mp[v[idx]]);
            }
            else res.push_back(-1);
        }
        return res;
    }
};