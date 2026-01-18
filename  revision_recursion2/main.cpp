#include <iostream>
using namespace std;
// merge sort
void sort(int *arr,int *a,int *b,int s,int e) {
    int mid=(s+e)/2;
    int i=s,j=mid+1;
   int k=s;
    while(i<=mid && j<=e) {
        if(a[i]<b[j]) {
            a[k++]=a[i++];
        }else {
            a[k++]=b[j++];
        }
    }
    while (i<=mid) {
        a[k++]=a[i++];
    }
    while (j<=e) {
        a[k++]=b[j++];
    }
}
void mergsort(int *arr, int s,int e) {
     if (s==e)return;
    //divide
    int mid = (s+e)/2;
    int a[100];
    int b[100];
    for (int i=s; i<=mid; i++) {
        a[i]=arr[i];
    }
    for (int j=mid+1; j<=e; j++) {
        b[j]=arr[j];
    }
    //sort
    mergsort(arr,s,mid);
    mergsort(arr,mid+1,e);
    //merge
    sort(arr,a,b,s,e);
}
void toh(int n,char s,char h,char d) {
    if (n==0)return;


    toh(n-1,s,d,h);
    cout<<"take disk "<<n<<" from " <<s<<" to "<<d<<endl;
    toh(n-1,h,s,d);
}
void subsequence(char* str,char* op,int i,int j) {
    if (str[i]=='\0') {
        op[j]='\0';
        cout<<op<<" ";
        return;
    }
    subsequence(str,op,i+1,j);
    op[j]=str[i];
    subsequence(str,op,i+1,j+1);

}
void permutation(char* str,int i) {
    if (str[i]=='\0') {
        cout<<str<<endl;
    }
    for (int j=i;str[j]!='\0';j++) {
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }
}
bool mat_in_raze(char maze[][5],int sol[][100],int n,int m,int i,int j) {
    //base case
    if (i==n-1 and j==m-1) {
        sol[i][j]=1;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    //recusive case
    sol[i][j]=1;
    if (j+1<n && maze[i][j+1]!='X') {
        bool rightse=mat_in_raze(maze,sol,n,m,i,j+1);
        if (rightse) {
            return true;
        }
    }
    if (i+1<n && maze[i+1][j]!='X') {
        bool leftse=mat_in_raze(maze,sol,n,m,i+1,j);
        if (leftse) {
            return true;
        }
        sol[i][j]=0;
        return false;
    }
}
bool queen_ki_chaal(int board[][100],int i,int j,int n) {
    for (int k=0;k<n;k++) {
        if (board[k][j]==1) {
            return false;;
        }
    }
    int oi =i;
    int oj =j;
    while ( i>=0 && j>=0) {
        if (board[i][j]==1) {
            return false;;
        }
    }
    i=oi;
    j=oj;
    while ( i>=0 && j<n) {
        if (board[i][j]==1) {
            return false;;

        }
    }
    return true;
}
bool nqueen(int board[][100],int row,int n) {
    //base case
if (row==n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<board[i][j]<<" ";
        }
    }
    cout<<endl;

    return true;
}
    //recursive
    for (int col=0;col<n;col++) {
        if (queen_ki_chaal( board,row,col,n)) {
            board[row][col]=1;
            bool baki_queen=nqueen(board,row+1,n);
            if (baki_queen) {
                return true;
            }
        }
        //backtracking
        board[row][col]=0;

    }
    return false;
}

int main() {

    int board[100][100]={0};
    nqueen(board,0,4);

}