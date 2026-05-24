class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto it:knowledge){
            string key=it[0];
            string val=it[1];
            mp[key]=val;
        }
        string ans="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                int st=i;
                int l=0;
                while(s[i]!=')'){
                    i++;
                    l++;
                }
                if(s[i]==')'){
                    string temp="";
                     temp+=s.substr(st+1,l-1);
                    if(mp.find(temp)!=mp.end())
                    {
                    ans+=mp[s.substr(st+1,l-1)];
                    }
                   else{
                    ans+="?";
                   }
                }
            }
                if(s[i]!='('&&s[i]!=')'){
                    ans+=s[i];
                }
                i++;
            }
            return ans;
        }
    
};