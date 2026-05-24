class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
      vector<int>minfreq(26,INT_MAX);
      for(auto word: words){
        vector<int>freq(26,0);
        for(auto c: word){
         freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            minfreq[i]=min(minfreq[i],freq[i]);
        }
      }
      vector<string>ans;
      for(int i=0;i<26;i++){
        for(int count=0;count<minfreq[i];count++){
            ans.push_back(string(1,i+'a'));
        }
      }
        return ans;
    }
};