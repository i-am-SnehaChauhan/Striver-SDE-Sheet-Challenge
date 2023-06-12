/* Approach 1: Brute Force
 Take a variable count Start traversing the array as we get arr[i]> arr[j]*2 
 where i<j then increment the count.
 At the end return count which is number of reverse pairs.

 Time Complexity : O(N^2)
 Space Complexity: O(1)
*/

#include <bits/stdc++.h> 
int reversePairs(vector<int> &nums, int n){
	 int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]>2*nums[j]){
                    count++;
                }
            }
        }
        return count;	
}

/*Approach 2: Modified Merge-Sort*/

#include <bits/stdc++.h> 

int binarySearch(vector<int>& sortedArr, int num) {

	int start = 0, end = sortedArr.size() - 1;
	
	while(start <= end) {

		int mid = (start + end)/2;

		if(sortedArr[mid] > num) {

			if(mid == 0) return sortedArr.size();

			else if(sortedArr[mid - 1] <= num) return sortedArr.size() - mid;

			else end = mid - 1;
		}

		else start = mid + 1;
	}

	return 0;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	int ans = 0;
	vector<int> sortedArr;
	sortedArr.push_back(arr[0]);

	for(int i = 1; i < arr.size(); i++) {

		ans+= binarySearch(sortedArr, 2*arr[i]);
		
		auto it = upper_bound(sortedArr.begin(), sortedArr.end(), arr[i]);
		sortedArr.insert(it, arr[i]);
	}

	return ans;
}