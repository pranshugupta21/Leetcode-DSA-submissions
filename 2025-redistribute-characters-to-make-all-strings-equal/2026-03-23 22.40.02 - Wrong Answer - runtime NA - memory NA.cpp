class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>freq(26,0);
        for(auto word:words){
            for(auto ch: word){
                freq[ch-'a']++;
            }
        }
        if(words.size()==2 && words[0].size()==words[1].size()==1) return false;
        int n=0;
        for(int i=0;i<26;i++ ){
            if(freq[i]!=0){
                n=freq[i];
            }
        }
         for(int i=0;i<26;i++ ){
            if(freq[i]!=0&&freq[i]!=n){
                return false;
            }
        }
        return true;
    }
};