class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>directions={
            {0,1},{0,-1},{1,0},{-1,0},
            {1,1},{1,-1},{-1,-1},{-1,1}};
            set<pair<int,int>>qset;
            for(auto q: queens){
                qset.insert({q[0],q[1]});
            }
            vector<vector<int>>ans;
            for(auto dir:directions){
                int da=dir[0];
                int db=dir[1];
                int r=king[0];
                int c=king[1];
                while((r>=0&&r<8)&&(c>=0&&c<8)){
                    r+=da;
                    c+=db;
                    if(qset.count({r,c})){
                     ans.push_back({r,c});
                     break;
                    }
                }
            }
            return ans;
        }
        
    
};