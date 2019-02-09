#include<iostream>
using namespace std;

string encrypt(string message, int shift){
    string result = message;
    int len=message.length();
    for(int i=0;i<len;i++){
        result[i]=(message[i]+shift)%128;
    }
    return result;
}

string decrypt(string cipher, int shift){
    string result = cipher;
    int len=cipher.length();
    for(int i=0;i<len;i++){
        result[i]=(127-(127-(cipher[i]-shift)))%128;
    }
    return result;
}

int main(){
    cout<<"***CAESER CIPHER***";
    int shift;
    cout<<"\nPlease enter the shift you want: ";
    cin>>shift;
    string input;
    cout<<"\nPlease enter the text to encrypt:";
    getline(cin,input);
    getline(cin, input);
    cout<<"\nEncrypting...\n";
    string cipher=encrypt(input,shift);
    cout<<"\nCipher = "<<cipher;
    cout<<"\nDecrypting...";
    string plainText=decrypt(cipher,shift);
    cout<<"Decrypted PlainText = "<<plainText<<endl;
    return 0;
}
