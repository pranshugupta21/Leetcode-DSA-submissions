class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices);
        stack<int>st;
        int n=prices.size();
        for(int i=n-1;i>=0;i--){         
            while(!st.empty() && prices[st.top()]>prices[i]){  // maintain monotonic increasing
            st.pop();           
            }
            if(!st.empty()){
                ans[i]=ans[i]-prices[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};