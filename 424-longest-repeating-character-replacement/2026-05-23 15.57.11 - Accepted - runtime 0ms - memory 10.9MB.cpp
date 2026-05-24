class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]={0};
        int l=0,r=0,maxfreq=0,maxlen=0;
        int n=s.size();
        while(r<n){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            if(((r-l+1)-maxfreq)>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};