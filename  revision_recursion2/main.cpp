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

//hanoi
void toh(int n,char s,char h,char d) {
    if (n==0)return;


    toh(n-1,s,d,h);
    cout<<"take disk "<<n<<" from " <<s<<" to "<<d<<endl;
    toh(n-1,h,s,d);
}

//subsequence
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

//permutation
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

//mat_in_raze
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

//queenPlacing
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

//sudokogame
bool isSafe(int arr[][9],int i,int j,int n ,int number) {
    for (int k=0;k<n;k++) {
        if (arr[k][j]==number || arr[i][k]==number) {
            return false;;
        }
    }
     n=sqrt(n);
    int si=(i/n)*n;
    int sj=(j/n)*n;
    for (int i=si;i<si+n;i++) {
        for (int j=sj;j<sj+n;j++) {
            if (arr[i][j]==number) {
                return false;;
            }
        }
    }
    return true;
}
bool sudoko(int arr[][9],int i,int j ,int n) {
    // base case
    if (i==n) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
if (j==n) {
    return sudoko(arr,i+1,0,n);
}
   if (arr[i][j]!=0) {
       return sudoko(arr,i,j+1,n);
   }
    //recursive
    for (int number=1;number<=9;number++) {
        if (isSafe(arr,i,j,n,number)) {
            arr[i][j]=number;
            bool kyabaaki=sudoko(arr,i,j+1,n);

            if (kyabaaki) {
                return true;
            }
            arr[i][j]=0;
        }

    }
    return false;

}
int main() {
int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudoko(mat,0,0,9);
    int board[100][100]={0};
    nqueen(board,0,4);

}