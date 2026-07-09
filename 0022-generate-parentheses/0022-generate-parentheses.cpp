class Solution {
public:
    void generate(int n,int op,int cl,vector<string>&res,string curr){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }
        if(op<n){
            curr.push_back('(');
            generate(n,op+1,cl,res,curr);
            curr.pop_back();
        }
        if(cl<op){
             curr.push_back(')');
           generate(n,op,cl+1,res,curr);
           curr.pop_back();
        }
        

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate(n,0,0, res,"");
        return res;
    }
};