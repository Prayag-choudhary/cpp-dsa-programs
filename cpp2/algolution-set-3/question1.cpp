#include<iostream>
#include<unordered_map>
using namespace std;
int squareFree(int num){
    unordered_map<int , int> hash;
    int n=num,f=0,count=0;
    for(int i=2;i<n;i++){
        int s=i*i;
        if(s<n){
            hash[i]=s;
        }
        else{
            break;
        }
    }
    int h = hash.size();
    for(int i=n/2;i>1;i--){
        if(n%i==0){
            for(int j=2;j<h;j++){
                if(i==hash[j]){
                    f=1;
                }
                if(i%hash[j]==0){
                    f=1;
                }
            }
            if(f==0){
                count++;
            }
            else{
                f=0;
            }
        }
    }
    return count;

}
int main(){
    int num;
    cout<<"enter a number :";
    cin>>num;
    int sCount=squareFree(num);
    cout<<sCount;
}