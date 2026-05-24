class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>maxfreq(26,0);
        for(auto str:words2){
            vector<int>freq(26,0);
            for(auto ch: str){
                freq[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                maxfreq[i]=max(maxfreq[i],freq[i]);
            }
        }
        for(auto strings:words1){
            vector<int>freq(26,0);
            for(auto c:strings){
                freq[c-'a']++;
            }
            bool f=true;
            for(int i=0;i<26;i++){
                if(freq[i]<maxfreq[i]){
                   f=false;
                   break;
                }
            }
                if(f){
                    ans.push_back(strings);
                }
            }
       return ans;
    }
};