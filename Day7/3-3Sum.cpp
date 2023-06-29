/* Approach 1: Brute Force 
We take three loops and check for all the possible triplets and return the triplets whose sum is equal to 0.

Time Complexity: O(n^3)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        set<vector<int>> set;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        set.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        for(auto it: set){
            v.push_back(it);
        }
      
        return v;
    }
};

/*Approach 2: Using Two Pointer and set Technique
We sort the array and then take two pointers j and k. j points to the element next to i and k points to 
the last element. We check if the sum of the three elements is equal to 0. If yes, then we insert the
triplet in the set. If the sum is greater than 0, then we decrement k. If the sum is less than 0, then
we increment j. We repeat this process until j is less than k.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> v;
        set<vector<int>> set;
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        for(auto it: set){
            v.push_back(it);
        }
      
        return v;
    }
};
