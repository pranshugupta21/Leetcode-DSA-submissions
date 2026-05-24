class Solution {
public:
 bool isanagram(string &w0,string &w1){
            vector<int>freq(26,0);
            if(w0.size()!=w1.size()) return false;
            for(int j=0;j<w1.size();j++){
                freq[w1[j]-'a']++;
                freq[w0[j]-'a']--;
            }
            bool found=true;
            for(int k=0;k<26;k++){
                if(freq[k]!=0){
                    found=false;
                    break;
                }
            }
            return found;
 }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            string w0=words[i-1];
            string w1=words[i];
           if(isanagram(w0,w1))continue;
           else{
             ans.push_back(w1);
           }
    }
    return ans;
    }
};