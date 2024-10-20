#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <unordered_map>
using namespace std;
int largestSub(vector<int> &arr,int n){
    int max=0;
    for(int i=0;i<n-1;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum = sum+arr[j];
            if(sum>max){
                max=sum;
            }
        }
    }
    return max;
}
int inversion(vector<int>arr,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j] && i<j){
                count++;
            }
        }
    }
    return count;
}
int kthLargest(vector<int>arr,int k){
    int n=arr.size();
    int max=0;
    int kLargest=INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    if(k==1){
        return max;
    }
    for(int i=0;i<k;i++){
        int maxElement = INT_MIN;
        int maxIndex = -1;
        for(int j=0;j<n;j++){
            if(arr[j]>maxElement){
                maxElement=arr[j];
                maxIndex=j;
            }
        }
        arr[maxIndex]=INT_MIN;
        if(i==k-1){
            kLargest=maxElement;
        }
    }
    return kLargest;
}
int equilibrium(vector<int> &arr){
    int n=arr.size();
    int sum=0;
    int sec_sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int f=0;
    int start=0;
    int end=n-1;
    while(start<end){
        sec_sum += arr[start];
        sum = sum-arr[end];
        if(sum==sec_sum){
            f++;
        }
        start++;
        end--;
    }
    if(f==1){
        return start+1;
    }
}
void pairTarget(vector<int> &arr,int target){
    int n=arr.size();
    int f=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum=arr[i]+arr[j];
            if(sum==target){
                f=1;
            }
        }
    }
    if(f==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int stockProfit(vector<int>&arr){
    int maxProfit=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int diff=arr[j]-arr[i];
            if(diff<0){
                diff = abs(diff);
            }
            if(diff>maxProfit && arr[j]>arr[i]){
                maxProfit=diff;
            }
        }
    }
    return maxProfit;
}
int maxSumSubArray(const std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    int max_sum = 0, window_sum = 0;
    for (int i = 0; i < k; i++){
        window_sum += arr[i];
    }
    max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = std::max(max_sum, window_sum);
    }

    return max_sum;
}

int main(){
    vector<int>arr={-2,-1,-3,4,-1,2,1,-5,4};
    int n=arr.size();
    cout<<"largest sum: ";
    int lSum=largestSub(arr,n);
    cout<<lSum<<endl;
    vector<int>arr2={7,2,6,3};
    int n1=arr2.size();
    cout<<"inversionCount:";
    int InversionCount=inversion(arr2,n1);
    cout<<InversionCount<<endl;
    vector<int>arr3={3,2,1,5,6,4};
    int k;
    cin>>k;
    int kLargest=kthLargest(arr3,k);
    cout<<"kthLargest:"<<kLargest<<endl;
    vector<int>arr4={1, 3, 5, 2, 2};
    int eqIndex=equilibrium(arr4);
    cout<<"equilibrium:"<<eqIndex<<endl;
    vector<int> arr5={1, 2, 4, 5, 7, 11};
    int target;
    cin>>target;
    pairTarget(arr5,target);
    vector<int> arr6={7,1,5,3,6,4};
    int profit=stockProfit(arr6);
    cout<<profit<<endl;
    vector<int> arr7={1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k1=4;
    int maxSum = maxSumSubArray(arr7,k1);
    cout<<"maxSum:"<<maxSum<<endl;
    
    return 0;
}