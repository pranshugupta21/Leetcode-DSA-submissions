class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        int c=0;
        if(n==1){
            if(s1[0]=='0'&& s2[0]=='1') return 1;
            else if(s1[0]=='1'&& s2[0]=='0') return -1;      // if the string contain only one character
            else return 0;
        }
        int ans=0;
        // now moving forward we will process the string 
        for(int i=0;i<n;i++){
            if(s1[i]=='0' && s2[i]=='1'){ //we change s1 to 1 
                ans++;
            }
            else if(s1[i]=='1' && s2[i]=='0'){
                if(i!=n-1 && s1[i+1] =='1'){
                    ans++;              // we change it to 0 and 0 applying 2nd condition
                  s1[i+1]='0';
                   s1[i]='0';
                }
                else if(i!=n-1 && s1[i+1]=='0')s1[i]='0', ans+=2; // we change s2 to 1 then apply 2nd condition so 2 opration needed and s2 will be 0 so no need to change 
                if(i==n-1){ // only in the last case when s1 is 1 we need 2 opeartion
                    if(s1[i-1]=='0'||s1[i-1]=='1') ans+=2;
                }
            }
        }
        return ans;
    }
};