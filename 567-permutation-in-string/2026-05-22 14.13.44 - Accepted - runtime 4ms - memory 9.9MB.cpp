class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>freqs1(26,0);
        vector<int>freqs2(26,0);
        for(char c: s1){
            freqs1[c-'a']++;
        }
        for(int i=0;i<m;i++){
           freqs2[s2[i]-'a']++;
           if(i>=n){
             freqs2[s2[i-n]-'a']--;
           }
           if(freqs1==freqs2){
            return true;
           }
        }
        return false;
    }
};