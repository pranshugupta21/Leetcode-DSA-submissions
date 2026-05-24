class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxx=-1;
        int n=s.size();
        for(int l=0;l<n;l++){
            for(int r=l+1;r<n;r++){
            if(s[l]==s[r]){
                maxx=max(maxx,r-l-1);
            }
            }
        }
        return maxx;
    }
};