/*Approach 1: Sorting
  We can simply sort the array and run a for loop to find the 
  longest consecutive sequence.

  Time Complexity: O(N*logn(N))
    Space Complexity: O(1)

    Where N is the length of array.

*/

#include <algorithm>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
}

/*Approach 2: Using Hash Table
 We can improve our time complexity of searching the next consecutive 
 element in the array by using a Hash Table which can check the presence 
 of an element in O(1). 
   
   Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the length of the given array.
*/