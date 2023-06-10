/* Approach1: Brute Force*/

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {

	long long ans = 1;
	for(int i=0; i<n; i++){
		ans = (ans ^ x)%m;
	}

	return ans;
}