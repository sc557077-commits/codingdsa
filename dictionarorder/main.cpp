#include <iostream>
#include<vector>
#include<string>
using namespace std;

void permutation(char *str,int i,vector<string>&output) {
    //base case
if (str[i] == '\0' ) {
     string input(str);
    string temp=str;
    if (temp<"cab") {
        output.push_back(temp);
    }

    return;
}
    //rcursive
    for (int j=i;str[j]!='\0';j++) {
        swap(str[i],str[j]);
        permutation(str,i+1,output);
        swap(str[i],str[j]);
    }

}
int main() {
     char str[]="cab";
    //getline(cin,str);
    sort(str,str+strlen(str));
     vector<string>output;
      permutation(str,0,output );
    sort(output.begin(),output.end());
   for (int i=0;i<output.size();i++) {
       cout<<output[i]<<endl;
   }


}
