#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i=m-1, j=n-1, k=n+m-1;
	while(j>=0){
		if(arr1[i]>arr2[j]){
			swap(arr1[k],arr1[i]);
			k--;
			i--;
		}else{
			swap(arr1[k],arr2[j]);
			k--;
            j--;
		}
	}
	
	return arr1;
}