// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: HW E7.1
// Write a function
// void sort2(double* p, double* q)
// that receives two pointers and sorts the values to which they point. If you call
// sort2(&x, &y)
// then x <= y after the call

#include <iostream>
using namespace std;

// Function to sort two double values in ascending order
void sort2(double* p, double* q){
    // Create references to the values pointed to by p and q
    double &x = *p;
    double &y = *q;

    // Sorting logic
    if (x > y) {
        // Swap the values if they are not in ascending order
        double temp = x;
        x = y;
        y = temp;
    }
}

int main(){
    // Declare variables to store user input
    double x, y;

    // Get user input for the first value
    cout << "Enter the value: ";
    cin >> x;

    // Get user input for the second value
    cout << "Enter the value: ";
    cin >> y;

    // Call the sort2 function with the addresses of x and y
    sort2(&x, &y);

    // Return 0 to indicate successful execution
    cout << x << ", " << y << endl;
    return 0;
}
