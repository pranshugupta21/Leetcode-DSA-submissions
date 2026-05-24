class Solution {
public:
    int firstMatchingIndex(string s) {
        int j=s.size()-1;
        int i=0;
        int idx=-1;
        while(i<=j){
            if(s[i]==s[j]){
                idx=i;
                break;
            }
            i++;
            j--;
        }
        return idx;
        
    }
};