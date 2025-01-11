#include<bits/stdc++.h>>

int getSingleElement(vector<int> &arr){
	// Write your code here.	
	for(int i = 0; i < arr.size()-1; i++){
		if(arr[i] != arr[i+1]) return arr[i];
		i++;
	}return arr.back();
}