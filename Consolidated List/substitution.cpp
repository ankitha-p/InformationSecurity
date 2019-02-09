#include<iostream>
using namespace std;

string encrypt(string message){
    string result=message;
    int len=message.length();
    for(int i=0;i<len;i++) result[i]=(message[i]+64)%128;
    return result;
}

string decrypt(string cipher){
    string result=cipher;
    int len=cipher.length();
    for(int i=0;i<len;i++) result[i]=(cipher[i]+64)%128;
    return result;
}

int main()
{
    cout<<"***SUBSTITUTION CIPHER***\n";
    string input;
    cout<<"Please enter the text to encrypt: ";
    getline(cin,input);
    cout<<"\nEncrypting...\n";
    string cipher = encrypt(input);
    cout<<"Cipher = "<<cipher<<endl;
    cout<<"Decrypting...\n";
    string plainText= decrypt(cipher);
    cout<<"Decrypted PlainText = "<<plainText<<endl;
    return 0;
}
