#include<bits/stdc++.h>
using namespace std;

int main(){
    

    //*  Left shifting by mulitplying by (n * 2 ^ k;
    int n;  cin >> n;
    cout << "Left shifting: "<< endl;

    cout << (n << 0) << endl;       //! n * 2^k
    cout << (n << 1) << endl;
    cout << (n << 2) << endl;
    cout << (n << 3) << endl;
    cout << (n << 4) << endl;
    cout << (n << 5) << endl;
    cout << (n << 6) << endl;

    //* Right shifting by dividi by (n / 2 ^ k);
    cin >> n;
    cout << "Right shifting: "<< endl;
    cout << (n >> 0) << endl;       //! n / (2^k)
    cout << (n >> 1) << endl;
    cout << (n >> 2) << endl;
    cout << (n >> 3) << endl;
    cout << (n >> 4) << endl; 
    cout << (n >> 5) << endl; 
    cout << (n >> 6) << endl; 
    cout << (n >> 7) << endl; 
    
    return 0;
}