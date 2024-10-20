#include<iostream>
#include<string>
using namespace std;
bool checkValidity(string s){
    int low = 0;
    int high = 0;
    for(char c:s){
        if(c=='('){
            high++;
            low++;
        }
        else if(c==')'){
            high--;
            low--;
        }
        else{
            high++;
            low--;
        }
        if(high<0){
            return false;
        }
    }
    return low==0;
}
int main(){
    string s="()";
    bool isValid = checkValidity(s);
    if(isValid){
        cout<<"string is valid";
    }
    else{
        cout<<"string is invalid";
    }
}