class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        map<pair<int,int>,int>mp;
        mp[{0,0}]=1;
        for(int i=0;i<path.size();i++){
            if(path[i]=='N'){
                y++;
            }
            else if(path[i]=='S'){
                y--;
            }
            else if(path[i]=='E'){
                x++;
            }
            else{
                x--;
            }
            if(mp.count({x,y})){
                return true;
            }
            else{
                mp[{x,y}]++;
            }
        }
        return false;
    }
};