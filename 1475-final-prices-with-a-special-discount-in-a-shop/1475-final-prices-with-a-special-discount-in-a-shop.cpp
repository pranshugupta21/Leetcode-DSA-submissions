class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int id=-1;
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    id=j;
                    break;
                } 
            }
            int val=(id==-1)? prices[i]:prices[i]-prices[id];
            ans.push_back(val);
        }
        return ans;
    }
};