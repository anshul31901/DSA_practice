#include <bits/stdc++.h> 

int countDistinctArrays(vector<int> &arr)
{	
	int mod = 1e9+7;
	unordered_map<int,int>freq;
	for(int i =0;i<arr.size();i++){
		freq[arr[i]]++;
	}
	long long res = 1;
//for any element  : not take possibility =1 , take possibility = freq
// therefore total possibilities = freq+1

	for(auto it:freq){
		res = (res*(it.second+1))%mod;
	}
rea-1(1 is null set)
	return res-1;
}
