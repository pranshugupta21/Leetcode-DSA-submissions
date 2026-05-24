class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>lastidx(256,-1);
        int l=0,r=0,maxlen=0;
        for(r=0;r<s.size();r++){
            char c=s[r];
            if(lastidx[c]>=l){
                l=lastidx[c]+1;
            }
            lastidx[c]=r;
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};