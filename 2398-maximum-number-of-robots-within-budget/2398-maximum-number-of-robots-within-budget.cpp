class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long n=chargeTimes.size();
         multiset<int>st;
         int j=0,ans=0;
         long long cost=0;
         for(int i=0;i<n;i++){
           cost+=runningCosts[i];
           st.insert(chargeTimes[i]);
           while(!st.empty()&&(i-j+1)*cost*1LL+1LL*(*rbegin(st))>budget){ // shring window and remove number
            cost-=runningCosts[j];
            st.erase(st.find(chargeTimes[j]));
            j++;
           }
           ans=max(ans,i-j+1);
            }
        return ans;
         }
};