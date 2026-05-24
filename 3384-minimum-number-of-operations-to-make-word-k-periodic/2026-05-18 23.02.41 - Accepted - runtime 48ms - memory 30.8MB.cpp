class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mp;
        int n=word.size();
        int i=0;
        while(i<n){
            mp[word.substr(i,k)]++;
            i+=k;
        }
        int mx=-1;
        string wd;
        for(auto it:mp){
         if(it.second>mx){
            mx=max(mx,it.second);
            wd=it.first;
         }
        }
        i=0;
        int c=0;
        while(i<n){
            if(word.substr(i,k)!=wd)c++;
            i+=k;
        }
        return c;
    }
};