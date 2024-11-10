#include<iostream>
#include<climits>
using namespace std;

/*
create a function to reverse an integer  which return 0 if the integer is out of range 
*/
int reverse(int x) {
    int ans = 0;
    while(x != 0) {
        int d = x % 10;
        if(ans > INT_MAX/10 || ans < INT_MIN/10) {
            return 0;
        }
        ans = ans * 10 + d;
        x = x / 10;
    }                                   
    return ans;
} 

int main() {
    int num;
    char choice;

    do {
        cout << "Enter an integer to reverse: ";
        cin >> num;

        int reversed = reverse(num);
        
        if (reversed == 0 && num != 0) {
            cout << "The reversed integer overflows." << endl;
        } else {
            cout << "Reversed integer: " << reversed << endl;
        }

        cout << "Do you want to reverse another integer? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the integer reversal program!" << endl;

    return 0;
}