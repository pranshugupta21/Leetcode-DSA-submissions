class Solution {
public:
    int calscore(vector<vector<int>>& students,vector<vector<int>>& mentors,int sindex,int mindex){
        int score=0;
         for(int i=0;i<students[sindex].size();i++){
            if(students[sindex][i]==mentors[mindex][i]) score++;
         }
         return score;
    }
    void solve(vector<vector<int>>& students, vector<vector<int>>& mentors,vector<bool>&visitedmentors,int index,int score,int  &total_score){
        int n=students.size();
        if(index>=n){
            total_score=max(total_score,score);
            return;
        }
        for(int i=0;i<n;i++){
            if(visitedmentors[i]==false){
                visitedmentors[i]=true;
             int curr_score=calscore(students,mentors,index,i);
             solve(students,mentors,visitedmentors,index+1,score+curr_score,total_score);
             visitedmentors[i]=false;
            }
        }

    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int index=0;
        int score=0;
        int total_score=0;
        int n=students.size();
        vector<bool>visitedmentors(n,false);
        solve(students,mentors,visitedmentors,index,score,total_score);
        return total_score;
    }
    
};