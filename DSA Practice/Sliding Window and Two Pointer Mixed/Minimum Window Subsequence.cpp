string minWindow(string S, string T)
{
	// Write your Code here
	int n = S.size(), m = T.size(), si = 0, ti = 0, mn = n + 1, st = -1;

	while(si < n){

		if(S[si] == T[ti]) ti++;
		
		if(ti == m){
			int temp = si;
			ti--;
			while(ti >= 0){
				if(S[si] == T[ti])  ti--;
				si--;
			}
			if(temp - si < mn)   st = si + 1,  mn = temp - si;
			ti++;    si++;
		}
		si++;
	}
	return (st == -1)  ?   " "   :  S.substr(st, mn);
}