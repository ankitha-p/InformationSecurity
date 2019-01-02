#include<iostream>
using namespace std;

int len=0;

int* multiply(int *plain,int **k)
{
    int *result=new int[len];
    for(int i=0;i<len;i++) result[i]=0;

    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            result[i]+=k[i][j]*plain[j];

    return result;
}

int** make2DMatrix(string key){
    int** k = new int*[len];
    for(int i=0; i<len; ++i)    k[i] = new int[len];
    int p=0;
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
                k[i][j]=(key[p++]-'A')%26;
    return k;
}

int* make1DMatrix(string input){
    int *plain=new int[len];
    for(int i=0;i<len;i++){ plain[i]=(input[i]-'A')%26;}
    return plain;
}

string performHill(string input,string key){
    len=input.length();

    int *plain=make1DMatrix(input);
    int** k = make2DMatrix(key);

    int *result= multiply(plain,k);

    string cipher=input;
    for(int i=0;i<len;i++){
        result[i]=result[i]%26;
        cipher[i]=result[i]+65;
    }
    return cipher;
}

int main()
{
    string input,key,cipher;
    cout<<"Enter the text: ";
    cin>>input;
    cout<<"\nEnter the key: ";
    cin>>key;
    cout<<"\nEncrypted text is: "<<performHill(input,key)<<endl;
    return 0;
}
