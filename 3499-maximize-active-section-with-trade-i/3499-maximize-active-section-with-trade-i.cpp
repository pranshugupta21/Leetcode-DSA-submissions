class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int onesc=0;
        int zeroslen=0;
        int prevzerolen=0;
        int i=0;
            while(i<n){
            if(s[i]=='1'){
             onesc++;
             i++;
            }
            else{
               int currzerolen=0;
               while(s[i]=='0'){
                currzerolen++;
                i++;
               }
               if(prevzerolen>0){
                zeroslen=max(zeroslen,prevzerolen+currzerolen);
               }
               prevzerolen=currzerolen;
            }
           }
           return onesc+zeroslen;
            }
};