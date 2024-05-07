#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a,int b)
{
	if(a==0)
	return b;
	return gcd(b%a,a);
}

int main()
{
	int p,q,n,z,d =0,e,i;
	
	cout<<"Enter the value of p....= ";
	cin>>p;
	cout<<"Enter the value of q....= ";
	cin>>q;
	
	n = p * q;
	z = (p - 1) * (q - 1);
	
	for (e = 2; e < z; e++)
	{
		if (gcd(e,z) == 1)
		{
			break;
		}
	}
	
	for (i = 0; i <=9; i++)
	{
		int x =1 + (i * z);
		if (x % e == 0)
		{
			d = x / e;
			break;
		}
	}
	
	cout<<"PUBLIC KEY (e,n) :(" << e <<", "<< n << ")" <<endl;
	cout<<"PRIVATE KEY (d,z) :(" << d <<", "<< z << ")" <<endl;
	
	int msg;
	cout<<"Enter MESSAGE to be ENCRYPTED: ";
	cin>>msg;
	
	int encrypted = fmod(pow(msg,e),n);
	cout<<"ENCRYPTED MSG : "<<encrypted<<endl;
	
	int decrypted = fmod(pow(encrypted,d),n);
	cout<<"DECRYPTED MSG : "<<decrypted<<endl;
	
	return 0;
	
}
