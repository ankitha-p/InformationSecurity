#include<iostream>
using namespace std;

int main()
{
    cout<<"Substitution Cipher on ASCII\n";
    cout<<"Enter the text you want to encrypt and press ENTER\n";
    string input,output;
    getline(cin,input);
    output=input;
    for(int i=0;i<input.length();i++)      output[i]=(input[i]+64)%128;
    cout<<"After encryption the text becomes\n"<<output;

    cout<<"\nRunning Decryption\n";
    input=output;
    for(int i=0;i<output.length();i++)     input[i]=(output[i]+64)%128;
    cout<<"After decryption the text becomes\n"<<input;

    return 0;
}
