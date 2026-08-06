class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
     while(! divdigit(num,t)){
        num++;
     }
      return num;
    }
    bool divdigit(int n,int t){
        int num=1;
        while(n!=0){
            num*=n%10;
            n/=10;
        }
        if(num%t==0) return true;
        return false;
    }
};