class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n =score.size();
        vector<string>result(n);
        priority_queue<pair<int,int>>p;
        for(int i = 0 ;i<score.size();i++){
            p.push({score[i],i});
        }
        int rank =1 ;
        while(!p.empty()){
            int idx = p.top().second;
            p.pop();
            if(rank==1){
                result[idx]="Gold Medal";
            }
            else if(rank==2){
                result[idx]="Silver Medal";
            }
            else if (rank==3){
                result[idx]="Bronze Medal";
            }
            else{
                result[idx]=to_string(rank);
            }
            rank++ ;

        }
        return result ;
        
    }
};