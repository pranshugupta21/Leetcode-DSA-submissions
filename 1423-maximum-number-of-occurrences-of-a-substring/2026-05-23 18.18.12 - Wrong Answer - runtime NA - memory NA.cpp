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
            if(mp.size()<=maxLetters&&sz>=minSize&&sz<=maxSize){
                string sr=s.substr(l,r+1);
                mp[sr]++;
            }
            if(mp.size()>maxLetters||sz>maxSize){
                freq[s[l]]--;
                l++;
            }
            r++;
        }
        int maxnum=0;
        for(auto it:mp){
            int num=it.second;
            maxnum=max(num,maxnum);
        }
        return maxnum+1;

    }
};