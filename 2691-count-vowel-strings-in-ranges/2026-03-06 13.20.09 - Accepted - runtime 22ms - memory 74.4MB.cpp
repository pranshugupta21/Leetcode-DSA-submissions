class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int n1=queries.size();
        string vowel="aeiou";
        vector<int>ans(n1,0);
        vector<int>vowelcount(n,0);
        for(int i=0;i<n;i++){
            string word=words[i];
            if(vowel.find(word[word.length()-1])!=string::npos&&vowel.find(word[0])!=string::npos){
                vowelcount[i]=1;
            }
        }
        vector<int>prefixsum(n+1,0);
         for(int i=0;i<n;i++){
            prefixsum[i+1]=prefixsum[i]+vowelcount[i];
         }
        for(int i=0;i<queries.size();i++){
            vector<int>query=queries[i];
            int left=query[0];
            int right=query[1];
            ans[i]=prefixsum[right+1]-prefixsum[left];
        }
return ans;
    }
};