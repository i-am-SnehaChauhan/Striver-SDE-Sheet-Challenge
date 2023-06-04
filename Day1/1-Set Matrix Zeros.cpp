/* Approach 1: Using two vectors Row and Col
   
*/ 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n,1);
        vector<int> col(m,1);
        // check exactlty at which pos 0 is present
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(matrix[i][j]==0){
                   row[i]=0;
                   col[j]=0;
               }
            }
        }
        // Set entire row and col zero
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(row[i]==0 || col[j]==0){
                  matrix[i][j]=0;
               }
            }
        }
    }
};
