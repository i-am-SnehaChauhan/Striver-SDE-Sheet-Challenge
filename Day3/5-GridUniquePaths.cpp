/*Approach 1: Recursion As problem said we can either move right or downward 
using recursion we can find all the posible combination.

Time Complexity: O(N^2)
Space Complexity: O(N^2) As we are using stack space for recursion so the 
space complexity will also be exponential.

*/


#include <bits/stdc++.h> 
int count(int i, int j, int m, int n){
	if(i==m-1 && j==n-1){
		return 1;
	}
	if(i>m-1 || j>n-1){
		return 0;
	}
	else{
		return count(i+1,j,m,n)+count(i,j+1,m,n);
	}
}
int uniquePaths(int m, int n) {
	return count(0, 0, m, n);
}

/*Approach 2: Memorisation
 In recursive solutions, there are many overlapping subproblems. In this 
 solution instead of traversing all the possible paths, whenever we get the 
 result we’ll store it in a matrix for future use.
*/

class Solution {
public:
int dp[101][101];
    int count(int i, int j, int m, int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            return dp[i][j] = count(i+1,j,m,n) + count(i,j+1,m,n);
        }
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return count(0,0,m,n);
    }
};