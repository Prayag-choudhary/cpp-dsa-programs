#include<iostream>
#include<string>


using namespace std;
int isPalindrome(string s){
    int start=0,end=s.size()-1,count=0,f=0,c=0;
    string copy_s=s;
    while(true){
        if(f==1){
            f=0;
        }
        int st=start,e=end;
        while(st<=e){
            if(s[st]!=s[e]){
                f=1;
                break;
            }
            st++;
            e--;
        }
        if(f==0){
            break;
        }
        if(count==end){
            break;
        }
        char temp;
        s[start]=s[end];
        for(int j=start+1;j<end;j++){
            temp=s[j];
            s[j]=s[j+1];
            if(j+1 == end){
                s[end]=temp;
            }
        }
        
        count++;
    }
    if(f==1){
        return -1;
    }
    return count;

}
int main(){
    string s="abc";
    int step=isPalindrome(s);
    cout<<step;
}
