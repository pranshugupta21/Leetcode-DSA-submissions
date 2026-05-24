class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int l=0,r=0,vc=0,maxvc=0;
        while(l<=s.size()-k){
            vc=0;
            for(int i=l;i<l+k;i++){
                char ch=s[i];
                if(st.count(ch)){
                    vc++;
                }
                r++;
            }
            maxvc=max(vc,maxvc);
            l++;
        }
        return maxvc;
    }
};