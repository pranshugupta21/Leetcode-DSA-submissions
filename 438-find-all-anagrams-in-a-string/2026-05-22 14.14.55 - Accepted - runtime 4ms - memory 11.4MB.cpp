class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         int n=s.size(),m=p.size();
        if(n<m)return{};
         vector<int>v;
         vector<int>freqs(26,0);
         vector<int>freqp(26,0);
         for(char c:p){
            freqp[c-'a']++;
         }
         for(int i=0;i<s.size();i++){
            freqs[s[i]-'a']++;
            if(i>=m){
                freqs[s[i-m]-'a']--;
            }
            if(freqs==freqp){
                v.push_back(i-m+1);
            }
         }
         return v;
    }
};
