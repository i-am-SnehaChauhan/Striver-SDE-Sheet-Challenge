 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=(n*m)-1;
        while(s<=e)
        {  
            if(m==0 || n==0 ){
                return false;
            }
            int mid=s+((e-s)/2);
            int val = matrix[mid/m][mid%m];
            if(val==target)
            {
                return true;
            }
            else
            {
                if(val<target)
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
        }
        return false;
    }