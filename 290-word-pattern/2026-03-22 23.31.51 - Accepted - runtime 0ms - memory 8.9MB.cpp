class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        unordered_map<string,char>rev;
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss>>word){
         words.push_back(word);
        }
        if(words.size()!=pattern.size()) return false;
        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            string wd=words[i];
            if(mp.count(ch)&&mp[ch]!=wd)return false; 
            if(rev.count(wd)&&rev[wd]!=ch)return false;
               mp[ch]=wd; 
               rev[wd]=ch;
            }
            return true;
        }
};