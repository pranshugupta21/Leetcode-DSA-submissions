class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int>res;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'){
                vector<int>left=diffWaysToCompute(exp.substr(0,i));
                vector<int>right=diffWaysToCompute(exp.substr(i+1));
                for(auto a:left){
                    for(auto b:right){
                         if(exp[i]=='+') res.push_back(a+b);
                         else if(exp[i]=='-') res.push_back(a-b);
                         else res.push_back(a*b);
                    }
                }
            }

        }
        if(res.empty()) res.push_back(stoi(exp));
        return res;
    }
};