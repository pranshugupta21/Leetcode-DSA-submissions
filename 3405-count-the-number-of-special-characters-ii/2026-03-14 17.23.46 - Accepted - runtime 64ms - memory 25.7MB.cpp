class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> a(150,-1);
        vector<int> b(150,-1);
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
        if(a[s[i]]==-1){
           a[s[i]]=i;
        }   
            }
            else{
                b[s[i]]=i;
            }
        }
        for(int j='a'; j<='z'; j++){
            if(b[j]==-1 || a[j-32]==-1) continue;

            if(b[j] < a[j-32]) 
                count++;
        }
        return count;
    }
};