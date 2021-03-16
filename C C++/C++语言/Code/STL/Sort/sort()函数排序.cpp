#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int i;
	int a[10] = { 2, 4, 1, 23, 2, 76, 0, 43, 24, 65 };

	/*	for (i = 0; i < 10; i++) {
			cout << a[i] << " ";  //2 4 1 23 5 76 0 43 24 65
		}
		cout << endl;
		//ÉýÐòsort( begin, end, less<data-type>() );
		sort( a, a + 10, less<int>() );
		for (i = 0; i < 10; i++) {
			cout << a[i] << " ";  //0 1 2 4 5 23 24 43 65 76
		}
		cout << endl;

		//½µÐòsort( begin, end, greater<data-type>() );
		sort( a, a + 10, greater<int>() );
		for (i = 0; i < 10; i++) {
			cout << a[i] << " ";  //76 65 43 24 23 5 4 2 1 0
		}
		cout << endl;*/
	sort(a,a+10);
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";  
	}
	return 0;
}
