class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans=queens;
        int rCenter=king[0];
        int cCenter=king[1];
        sort(ans.begin(),ans.end(),[&](vector<int>&a,vector<int>&b){
            int da=abs(a[0]-rCenter)+abs(a[1]-cCenter);
            int db=abs(b[0]-rCenter)+abs(b[1]-cCenter);
            return da<db;
        });
    
    vector<vector<int>>ans1;
    bool r=true;
    bool c=true;
    bool ud=true;
    bool ld=true;
    for(auto v:ans){
        if(v[0]==rCenter&&r==true){
            r=false;
            ans1.push_back({v[0],v[1]});
        }
        if(v[1]==cCenter&&c==true){ 
            c=false;
            ans1.push_back({v[0],v[1]});}

        if(v[0]==v[1]&&ud==true&&rCenter<v[0]){
            ud=false;
            ans1.push_back({v[0],v[1]});
        }
        if(v[0]==v[1]&&ld==true&&cCenter>v[0]){
            ld=false;
            ans1.push_back({v[0],v[1]});
        }
    }
    return ans1;
    }
};