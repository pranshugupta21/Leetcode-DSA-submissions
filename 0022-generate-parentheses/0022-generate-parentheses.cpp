class Solution {
public:
    void generate(int n,int op,int cl,vector<string>&res,string curr){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(op<n){
            generate(n,op+1,cl,res,curr+'(');
        }
        if(cl<op){
           generate(n,op,cl+1,res,curr+')');
        }
        

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate(n,0,0, res,"");
        return res;
    }
};