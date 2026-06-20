class Solution {
public:
    int minimumSwap(string s1, string s2) {
       int xy_mismatch=0;
       int yx_mismatch=0;
       for(int i=0;i<s1.size();i++){
        if(s1[i]=='x'&&s2[i]=='y') xy_mismatch++;
        else if(s1[i]=='y'&&s2[i]=='x') yx_mismatch++;
       }
       if((xy_mismatch+yx_mismatch)%2!=0) return -1;
       int swaps=((xy_mismatch/2)+(yx_mismatch/2));
       if(xy_mismatch % 2 !=0) swaps+=2;
       return swaps;
    }
};