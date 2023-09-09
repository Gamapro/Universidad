#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;
	
	vector<int> v(n,0);
	
	int zero = 0, remain = 0;
	for(int i = 0; i < n; i++){
		cin>>v[i];
		if(v[i] == 0) zero++;
	}
	
	for(int i = n-1; i >=0 && zero > remain; i--){
		if(v[i] == 0){
			remain++;
		}else{
			int idx = i + zero - remain;
			if(idx < n){
				v[idx] = v[i];
			}
			v[i] = 0;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout<<v[i]<<' ';
	}
	
	return 0;
	
}