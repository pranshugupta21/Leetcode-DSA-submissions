class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        unordered_map<string,char>rev;
        int j=0;
        for(int i=0;i<pattern.size();i++){
           int start=j;
            while(j<s.length()&&s[j]!=' '){
                j++;
            }
            char ch=pattern[i];
            string wd=s.substr(start,j-start);
            if(mp.count(ch)&&mp[ch]!=wd)return false; 
            if(rev.count(wd)&&rev[wd]!=ch)return false;
               mp[ch]=wd; 
               rev[wd]=ch;
            while(j<s.size()&&s[j]==' '){
                j++;
            }
        }
        if(j<s.size()) return false;
        return true;
    }
};