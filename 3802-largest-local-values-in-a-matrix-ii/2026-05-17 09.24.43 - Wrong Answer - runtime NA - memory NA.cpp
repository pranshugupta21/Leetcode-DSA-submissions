class Solution {
public:
    bool inbounds(int r,int c,int m,int n){
        return r>=0&&r<m&&c>=0&&c<n;
    }
    bool ignored(int di,int dj,int x){
        return abs(di)==x&&abs(dj)==x;
    }
    bool neigh(vector<vector<int>>& matrix,int i,int j,int x,int m,int n){
        for(int di=-x;di<=x;di++){
            for(int dj=-x;dj<=x;dj++){
                if(di==0&&dj==0) continue;
                if(ignored(di,dj,x)) continue;
                int ni=i+dj,nj=j+dj;
                if(!inbounds(ni,nj,m,n)) continue;
                if(matrix[ni][nj]>x) return true;
            }
        }
        return false;
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x=matrix[i][j];
                if(x==0) continue;
                if(!neigh(matrix,i,j,x,m,n)) c++;
            }
        }
        return c;
    }
};