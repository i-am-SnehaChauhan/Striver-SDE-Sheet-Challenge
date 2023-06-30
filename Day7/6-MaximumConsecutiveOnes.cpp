/*Approach 1: BruteForce : Find all the subarrays and count the number of 1s in each subarray. 
Return the maximum count.

Time Complexity: O(N^2)
Space Complexity: O(1)*/


#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == 1) {
                count++;
            }
            else {
                break;
            }
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}   