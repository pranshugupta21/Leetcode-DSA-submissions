class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxx=-1;
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                maxx=max(maxx,r-l-1);
            }
            l++;
            r--;
        }
        return maxx;
    }
};