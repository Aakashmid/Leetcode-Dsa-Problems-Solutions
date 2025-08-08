#include<iostream>
#include<string>
using namespace std;

// return sum of binary number in string 
string addBinary(string a, string b) {
    string res="";
    int i = a.length()-1,j= b.length()-1;
    int carry =0;
    while(i >= 0 || j>=0 || carry ){
        int firstD =i>=0 ?   a[i]-'0' : 0 ;
        int secondD = j>= 0? b[j]-'0':0;
        res=to_string((firstD+secondD+carry)%2)+res;
        carry = (firstD+secondD+carry)/2;
        i--;j--;
    }
    
    return res;
}


int main(){
    string a = "11", b = "1";
    cout << addBinary(a,b) << endl;
    return 0;
}