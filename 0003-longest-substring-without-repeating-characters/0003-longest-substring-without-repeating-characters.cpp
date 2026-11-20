class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_char_idx[256]={-1};
        fill(last_char_idx, last_char_idx + 256, -1);
        int c=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            if(last_char_idx[s[r]]>=l){
                l=last_char_idx[s[r]]+1;
            }
                last_char_idx[s[r]]=r;
             c=max(c,r-l+1);
        }
        return c;
    }
};