class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l=0,r=0;
        int n=s.size();
        if(n<minSize) return 0;
        unordered_map<string,int>mp;
        unordered_map<char,int>freq;
        while(r<n){
            freq[s[r]]++;
            int sz=r-l+1;
            if(sz==minSize){
                if(freq.size()<=maxLetters){
                string sr=s.substr(l,sz);
                mp[sr]++;
                }
            freq[s[l]]--;  //shrink from left
            if(freq[s[l]]==0){
                freq.erase(s[l]);
            }
            l++;
        }
        r++;
        }
        int maxnum=0;
        for(auto it:mp){
            int num=it.second;
            maxnum=max(num,maxnum);
        }
        return maxnum;

    }
};