class Solution {
    int value(char c){
        if(c>='a'&&c<='z')return 1;
        else if(c>='A'&&c<='Z')return 2;
        else if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9') return 3;
        else if(c=='!'||c=='@'||c=='#'||c=='$') return 5;
        return 0;
    }
public:
    int passwordStrength(string password) {
        unordered_set<char>st;
        for(char ch:password){
            st.insert(ch);
        }
        int tv=0;
    for (auto it = st.begin(); it != st.end(); ++it) {
        char ch=*it;
        tv+=value(ch);
    }
        return tv;
    }
};