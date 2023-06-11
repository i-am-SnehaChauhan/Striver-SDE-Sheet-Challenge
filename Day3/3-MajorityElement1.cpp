/* Brute Force
    Time Complexity: O(N ^ 2)
    Space Complexity: O(1)

    Where 'N' is the size of array/list.
*/

int findMajorityElement(int arr[], int n) {
	// Iterating each element in the array/list and check if it is a majority element.
	for(int i = 0; i < n ; i++) {	
		// Variable to store the frequency of the current element at index 'i'.
		int maxCount = 0;

		// Iterating the array/list to count the frequency of the current element at index 'i'.
		for(int j = 0; j < n; j++) {
			// Increment the count of variable if an occurrence of the current element is observed.
			if(arr[j] == arr[i]) {
				maxCount++;
			}	
		}

		// If count of any element exceeds 'n' / 2, then it is the majority element.
		if(maxCount > n/2) {
			return arr[i];
		}
	}
	// If no majority element found, return -1.
	return -1;
}

/* Uisng Hashmap
 Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the size of array/list.
*/
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) {
		mp[arr[i]]++;	
    }
	
	for(auto i: mp){
		if(i.second>n/2){
			return i.first;
		}
	}
	return -1;
}

/*Moore Voting Algorithm
  Time Complexity: O(N)
  Space Complexity: O(1)

    Where 'N' is the size of array/list.
*/

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int majorityElement = -1;
	int count=0;
	for(int i = 0; i < n; i++){
		if(count==0){
			majorityElement = arr[i];
			count=1;
			continue;
		}
		
		if(majorityElement==arr[i]){
			count++;
		}else{
			count--;
		}
	}
	count=0;
	for(int i = 0; i < n; i++){
        if (arr[i] == majorityElement) {
            count++;
        }
    }
    if(count> n/2){
		return majorityElement;
	}
	
	return -1;
}