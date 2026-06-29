class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int c=0;
        for(auto &wd:patterns){
            if(word.find(wd)!=string::npos)c++;
        }
        return c;
    }
};