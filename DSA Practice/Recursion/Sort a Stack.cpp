#include <bits/stdc++.h> 
void insertAtSort(stack<int>& s, int num){
	if(s.empty() || (!s.empty() && s.top() < num)){
		s.push(num);
		return;
	}
	int x = s.top();
	s.pop();
	insertAtSort(s, num);
	s.push(x);
}
void sortStack(stack<int> &s)
{
	// Write your code here
	if(s.empty()) return;
	int x = s.top();
	s.pop();
	sortStack(s);

	insertAtSort(s, x);
}