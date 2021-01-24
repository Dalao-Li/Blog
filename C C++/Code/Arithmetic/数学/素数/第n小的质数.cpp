#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,order=0,primeNumber;
	scanf("%d",&n);
	//order的值代表第几个质数 
	for(i=2;order!=n;i++){
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0){
				break;
			}
		}
		//i是一个质数时,将i的值放入prime中，order加一 
		if(j>sqrt(i)){
		    primeNumber=i;
			order++;
		}
	}
	printf("%d\n",primeNumber);
	return 0; 
	
}
