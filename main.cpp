#include<bits/stdc++.h>
#include "bigint.h"

using namespace std;


int main(){
	int n;
	cin>>n;
	bigint arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	// sort all the number in desceding order 
	sort(arr,arr+n,greater<bigint>());
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	// calculate the product of all number mod 1e9+7
	bigint res=1;	
	bigint mod=1000000007;
	for(int i=0;i<n;i++){
		res=res*arr[i];
		res=res%mod;
	}
	cout<<res<<endl;

	// calculate factorial of a number (<60)
	int nm;
	cin>>nm;

	bigint fact=1;
	for(long long int i=1;i<=nm;i++){
		fact=fact*i;
	}
	cout<<fact<<endl;
	return 0;
}
