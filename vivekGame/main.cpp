#include <iostream>
using namespace std;

int Game(int arr[100],int n) {
    //base case
    if (n<2) {
        return 0;
    }

    //recursive case

    int sum[100];
    sum[0]=arr[0];
    for(int i=1;i<n;i++) {
        sum[i]=sum[i-1]+arr[i];
    }
int total=sum[n-1];
    for(int i=0;i<n-1;i++) {
        int left=sum[i];
        int right=total-left;
        if (left==right) {
           return 1+max(Game(arr,i+1),Game(arr+1+i,n-1-i));
        }
    }
    return 0;

}
int main() {
     int arr[100]={3,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
   cout<< Game(arr,n);
    return 0;
}