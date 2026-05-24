class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
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
            if(x==0&&y==0){
                return true;
            }
        }
        return false;
    }
};