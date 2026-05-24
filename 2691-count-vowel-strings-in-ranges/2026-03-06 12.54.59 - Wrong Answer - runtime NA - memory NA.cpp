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
            if(word[0]==word[word.length()-1]&&vowel.find(word[0])!=string::npos){
                vowelcount[i]=1;
            }
        }
        for(int i=0;i<queries.size();i++){
            vector<int>query=queries[i];
            int left=query[0];
            int right=query[1];
            int as=0;
             while(left<=right){
                if(vowelcount[left]==1){
                as++;
                }
                left++;
             }
            ans[i]=as;
        }
return ans;
    }
};