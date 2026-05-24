class Solution {
public:
    bool buddyStrings(string s, string goal) {
       int n=s.size();
       int m=goal.size();
       if(n!=m) return false;
       if(s==goal){
         vector<int>freq(26,0);
         for(char ch: s){
            freq[ch-'a']++;
         }
         for(int i=0;i<26;i++){
            if(freq[i])>1 return true;
         }
     return false;
       }
        int i=0,j=n-1;
        while(i<j&&s[i]==goal[i]){
            i++;
        }
        while(j>=0&&s[j]==goal[j]){
            j--;
        }
        if(i<j){
        swap(s[i],s[j]);}
        return s==goal;
    }
};