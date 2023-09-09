#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << #y"=" << y << '\n';

int main(){	

	string s; int k;
	cin>>s>>k;
	
	string aux = "";
	vector<int> v(26, 0);
	
	for(char c : s){
		v[c-'a']++;
	}
	
	for(int i = 0; i < 26; i++){
		while(v[i] > 0 && k > 0){
			v[i]--; k--;
		}
	}
	
	for(int i = s.size()-1; i >=0; i-- ){
		if(v[s[i]-'a'] > 0){
			aux += s[i];
			v[s[i]-'a']--;
		}
	}
	
	reverse(aux.begin(), aux.end());
	
	cout<<aux<<'\n';

}
