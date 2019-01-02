#include<iostream>
using namespace std;

int len=0;

string encrypt(string input,string key){
    len=input.length();
    int *plain=new int[len];
    int **k= new int[len][len];
}

int main()
{
    string input,key,cipher;
    cout<<"Enter the text: ";
    cin>>input;
    cout<<"\nEnter the key: ";
    cin>>cipher;
    encrypt(input,key);
    cout<<"\nEncrypted text is: "<<decrypt(cipher,key)<<endl;


}
