class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> a(26,-1);
        vector<int> b(26,-1);
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
        if(a[s[i]-'A']==-1){
           a[s[i]-'A']=i;
        }   
            }
            else{
                b[s[i]-'a']=i;
            }
        }
        for(int j=0; j<26; j++){
            if(b[j]==-1 || a[j]==-1) continue;

            if(b[j] < a[j]) 
                count++;
        }
        return count;
    }
};