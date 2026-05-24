bool isletter(char ch){
            return ch>='a'&& ch<='z';
        }
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(auto str : chunks){
            s+=str;
        }
        
        int n=s.size();
        vector<bool>valid(n,false);
       for(int i=0;i<n;i++){
        if(isletter(s[i])){
            valid[i]=true;
        }
            else if(s[i]=='-'){
                if((i>0&&i<n-1)&&(s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')){
                  valid[i]=true;  
                }
            }
        }
        
         unordered_map<string,int>mp;
         int i=0,j=0;
         while(i<n){
            if(valid[i]){
                j=i;
            while(j<n&&valid[j]) j++;
            mp[s.substr(i,j-i)]++;
            i=j;
            }
            else{
                i++;
            }
         }
        int sz=queries.size();
        vector<int>ans(sz);
        for(int i=0;i<sz;i++){
            auto it=mp.find(queries[i]);
        if(it!=mp.end()){
            ans[i]=it->second;
        }
        }
         return ans;
    }
};