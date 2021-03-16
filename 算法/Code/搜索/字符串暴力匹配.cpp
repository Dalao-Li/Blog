#include<iostream>
using namespace std;
int sum = 0;

int stringMatching(string &t,string &s) {
	int i = 0;
	int j = 0;
	while(i<t.length()&&j<s.length()) {
		if(t[i] == s[j]) {
			i++;
			j++;
		} else {
			i = i-(j-1);
			j = 0;
			sum++;
		}
	}
	if(j == s.length()) {
		return i-j;
	}
	return -1;
}

int main() {
	string s1 = "ABCDABEFABF";
	string s2 = "ABF";
	cout<<stringMatching(s1,s2)<<endl;
	cout<<"Æ¥ÅäÁË"<<sum<<"´Î"<<endl;
	return 0;
}
