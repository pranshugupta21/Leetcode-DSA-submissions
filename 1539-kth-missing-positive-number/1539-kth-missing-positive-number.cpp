class Solution {
public:
       int findKthPositive(vector<int>& A, int k) {
        for(auto n:A){
          if(n<=k)k++;
          else break;
        }
        return k;
    }
};                                                                                