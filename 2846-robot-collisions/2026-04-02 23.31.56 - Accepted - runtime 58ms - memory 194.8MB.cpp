class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> ids(n);
        for(int i=0;i<n;i++)ids[i]=i;
        sort(ids.begin(),ids.end(),[&](int i,int j){
            return positions[i]<positions[j];
        });
        vector<int> st;
        for(int i:ids){
            if(directions[i]=='R'){
                st.push_back(i);
            }else{
                while(!st.empty()&&healths[i]>0){
                    int top=st.back();
                    if(healths[top]<healths[i]){
                        healths[i]--;
                        healths[top]=0;
                        st.pop_back();
                    }else if(healths[top]>healths[i]){
                        healths[top]--;
                        healths[i]=0;
                    }else{
                        healths[i]=0;
                        healths[top]=0;
                        st.pop_back();
                    }
                }
            }
        }
        vector<int> res;
        for(int h:healths){
            if(h>0)res.push_back(h);
        }
        return res;
    }
};