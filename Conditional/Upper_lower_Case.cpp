#include<iostream>
using namespace std;

int main(){
    char ch;
    cin>>ch;

    if(ch >= 65 && ch<=90){
        cout<<"Upper case";
    }else if(ch >= 97 && ch<=122){
        cout<<"lower case";
    }else if(ch >=48 && ch <= 57){
        cout<<"Number"<<endl;
    }else{
        cout<<"Symbol";
    }

}