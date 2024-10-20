#include<iostream>
#include<vector>
using namespace std;
void findMax(vector<int> arr,int k)
{
    vector<int> result;
    int n = arr.size();
    for(int i=0;i<n-2;i++){
        int max=0;
        for(int j=i;j<k;j++){
            if(j == n-1){
                break;
            }
            if(max<arr[j]){
                max=arr[j];
            }
        }
        result.push_back(max);
        k++;

    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}
int main(){
    vector<int> arr={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k;
    cin>>k;
    findMax(arr,k);
}