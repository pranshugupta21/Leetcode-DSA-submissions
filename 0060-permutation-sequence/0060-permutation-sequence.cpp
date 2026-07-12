class Solution {
public:
    void rec(string &ans,string &temp,vector<bool>&v,int n,int k,int &c){
        if(!ans.empty()) return;
        if(temp.size()==n){
            c++;
            if(c==k){
                ans=temp;
            }
            return;
        }
        for(int i=1;i<=n;i++){
            if(v[i-1]==false){
            temp.push_back(i+'0');// convert to string
            v[i-1]=true;
            rec(ans,temp,v,n,k,c);
            temp.pop_back();
            v[i-1]=false;
            }
        }

    }

    string getPermutation(int n, int k) {
        int c=0;
        vector<bool>v(n,false);
        string ans="";
        string temp="";
        rec(ans,temp,v,n,k,c);
        return ans;
    }
};