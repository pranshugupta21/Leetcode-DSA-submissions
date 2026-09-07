class Solution {
public:
    string smallestNumber(string pattern) {
        string curr="";
        vector<bool>visited(10,false);
        backtrack(pattern,curr,visited);
        return curr;
    }
    private:
     bool backtrack(const string & pattern ,string &curr, vector<bool>&visited ){
          if(curr.size()==pattern.size()+1){
            return true;
          }
          for(int i=1;i<=9;i++){
                if(visited[i]) continue;
                if(!curr.empty()){
                    char prevdigit=curr.back();
                    char rel=pattern[curr.size()-1];
                    if(rel=='I'&& i+'0'<=prevdigit) continue;
                    if(rel=='D'&& i+'0'>=prevdigit) continue;
                }
                visited[i]=true;
                curr.push_back(i+'0');
                if(backtrack(pattern,curr,visited)){
                    return true;
                }
                curr.pop_back();
                visited[i]=false;
          }
          return false;
       }
};