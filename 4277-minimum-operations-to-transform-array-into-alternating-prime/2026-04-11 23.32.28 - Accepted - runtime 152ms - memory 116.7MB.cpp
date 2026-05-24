class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        if(n==2 || n==3 ) return true;
        if(n%2==0) return false;
        for(int i=3;i*i<=n;i=i+2){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int nextprime(int n){
        int x=n+1;
        while(1){
        if(isprime(x)){
            return x;
        }
           x++; 
        }   
    }
    int minOperations(vector<int>& nums) {
        int op=0;
        int n=nums.size();
      for(int i=0;i<n;i++){
          if(i==0||i%2==0){
              if(!isprime(nums[i])){
                  op+=nextprime(nums[i])-nums[i];
              }
          }
          else{
              if(isprime(nums[i])){
                  if(nums[i]==2) op+=2;
                  else{
                    op++;  
                  }
                  
              }
          }
      }
       return op; 
    }
};