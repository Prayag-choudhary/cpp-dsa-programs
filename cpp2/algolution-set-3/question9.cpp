#include<iostream>
#include<vector>
using namespace std;
void spiral(vector<vector<int>>& arr){
    int n=arr.size(),count=1,i=0,j=0;
    int num=n*n;
    int m=n;
    
    while(count<=num){
        for(j=0;j<n-1;j++){
            cout<<"->"<<arr[i][j];
            count++;
        }
        for(i=0;i<n-1;i++){
            cout<<"->"<<arr[i][j];
            count++;
        }i

        while(j>=0 ){
            if(j<0){
                break;
            }
            cout<<"->"<<arr[i][j];
            count++;
            j--;
        }
        
        i--;
        j++;
        while(j<=i ){
            if(j>i){
                break;
            }
            cout<<"->"<<arr[i][j];
            j++;
            count++;
        }
       


    }

}
int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    spiral(arr);
}