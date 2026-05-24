class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int c=0;
        int y=1;
        for(int i=0;;i++){
            int num=1;
            for(int x=1;x<=k;x++){
                num*=i;
                if(num>r)return c;
            }
            if(num>=l) c++;
        }
        return c;
    }
};