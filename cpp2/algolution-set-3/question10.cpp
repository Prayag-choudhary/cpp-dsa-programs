#include<iostream>
#include<vector>
using namespace std;
void findMax(vector<int> arr,int k)
{
    int proMin;
    int min=INT32_MAX;
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            int pr=1;
            if(i!=j){
                pr=arr[i]*arr[j];
            }
            if(min>pr && pr!=1){
                min=pr;
            }
        }
        k++;
        proMin=min;
    }
    cout<<proMin<<endl;
}
int main(){
    vector<int> arr={ 198 ,76 ,544 ,123 ,154 , 675};
    int k;
    cin>>k;
    findMax(arr,k);
}