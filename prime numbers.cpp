#include <iostream>
using namespace std;
int main()
{
	cout<<"List of prime numbers from 0 to 100"<<endl;
	int x,y;
	for(int x= 0; x<=100; x++)
	{
		for(y=2;y<x;y++)
		{
			if(x%y==0)
			break;

		}
		if(x==y)
		cout<<("%d",x)<<endl;
	}

	return 0;
}
