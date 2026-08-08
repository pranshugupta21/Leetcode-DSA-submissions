class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7;// here hour can be at most 2 digit and dist can go as 1e5 
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(dist,hour,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }
    private:
     bool check(vector<int>& dist, double hour, int speed){
        int n=dist.size();
        double time=0.0;// using time double variable bcz repeteadly subtracting double from hour can give precision error
        for(int i=0;i<n;i++){
            if(i!=n-1){ 
             time+=((dist[i]+speed-1)/speed);  // using ceil((float)dist[i]/speed)
        }                                       
        else{
           time+=(double)dist[i] / speed;
        }
        
        if(time>hour) return false;
        }
        return time<=hour;
     }
};