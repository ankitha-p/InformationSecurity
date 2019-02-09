#include<iostream>
using namespace std;

void rsa(string message, int e, int n, int d){
    string result=message;
    int len=message.length();
    int *arr=new int[len];
    for(int i=0;i<len;i++)  arr[i]=(int)message[i];

    cout<<"Encrypting...\nCipher = ";

    int *output=new int[len];
    for(int i=0;i<len;i++){
        output[i]=arr[i];
        for(int j=1;j<e;j++){
            output[i]=((output[i]%n)*(arr[i]%n))%n;
        }
        cout<<output[i];
    }
    cout<<"\nDecrypting...\n";
    for(int i=0;i<len;i++){
        arr[i]=output[i];
        for(int j=1;j<d;j++){
            arr[i]=((output[i]%n)*(arr[i]%n))%n;
        }
        result[i]=(char)arr[i];
    }
    cout<<"Decrypted plainText = "<<result;
}

int gcd(int num1, int num2){
    if(num2==0) return num1;
    else return gcd(num2, num1%num2);
}

int main()
{
    int p,q;
    cout<<"Enter two large prime numbers: ";
    cin>>p>>q;
    int n= p*q;

    int phi = (p-1)*(q-1);
    int e;
    for(int itr=2;itr<phi;itr++){
        if(gcd(itr,phi)==1) {e=itr;break;}
    }

    int  d=1;

	while(1)
	{
		if((d*e) % phi==1)	 break;
		else d++;
	}

    cout<<"Public key(e,n): "<< e<<","<<n<<endl;
    cout<<"Private key(d,n): "<<d<<", "<<n<<endl;
    string input;
    getline(cin,input);
    cout<<"Enter the message you want to encrypt:";
    getline(cin, input);
    rsa(input,e,n,d);
    return 0;
}
