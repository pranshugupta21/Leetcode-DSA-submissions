class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        //int n=stoi(s);
        for(int i=0;i<s.size()-1;i++){
            int x=int(s[i]);
            int y=int(s[i+1]);
            if(abs(x-y)>2) return false;
        }
        return true;;
    }
};