class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string>st;
        int s=word.size();
        for(int i=0;i<s;i++){
            for(int j=i;j<s;j++){
                st.insert(word.substr(i,j-i+1));
            }
        }
        int c=0;
        for(auto &wd:patterns){
            if(st.find(wd)!=st.end())c++;
        }
        return c;
    }
};