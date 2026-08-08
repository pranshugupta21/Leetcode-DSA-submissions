class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low=0,high=removable.size();
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(issubseq(s,p,removable,mid)){
              ans=mid;
              low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
     bool issubseq(string &s,string &p,vector<int>&removable,int k){
        vector<bool>removed(s.size(),false);
        for(int i=0;i<k;i++){                     // subsequence check
            removed[removable[i]]=true;
        }
        int i=0,j=0;
        while(i<s.size() && j<p.size()){
            if(!removed[i] && s[i]==p[j]){
                j++;
            }
            i++;
        }
        return j==p.size();          // whole string p is consumed so p is a subsequence of s
     }
};