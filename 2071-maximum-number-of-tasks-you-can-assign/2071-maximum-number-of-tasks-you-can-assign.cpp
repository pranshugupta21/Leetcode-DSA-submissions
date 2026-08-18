class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();
        int low=0,high=min(n,m);
        int assigned=0;
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(tasks,workers,pills,strength,mid)){
                assigned=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return assigned;
    }
    private: 
        bool check(vector<int>&tasks,vector<int>&workers,int pills,int strength,int mid){
            multiset<int>workers_assign(workers.end()-mid,workers.end());// put the strongest mid workers to set
          for(int i=mid-1;i>=0;i--){
            auto str_worker=--workers_assign.end();
           if(*str_worker<tasks[i]){
               if(pills<=0) return false;   // not enough pills to complete tasks
               auto next_worker=workers_assign.lower_bound(tasks[i]-strength);  // minimum strength to complete the tasks
               if(next_worker==workers_assign.end()){
                return false;               // cannot get the tasks done by using pills also
               }
               pills--;
               workers_assign.erase(next_worker);
           } 
           else{
            workers_assign.erase(str_worker);
            }
           } 
           return true;
          }
};