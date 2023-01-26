// Space optimization using bit manipulations

// Appraoch 1
// Space complexity : O(| b - a |).
// Simply hash |b – a| positions of an array as 0 and 1.
// C++ program to mark numbers as multiple of 2 or 5
// #include <bits/stdc++.h>
// using namespace std;

// // Driver code
// int main()
// {
//     int a = 2, b = 10;
//     int size = abs(b - a) + 1;
//     int *array = new int[size];

//     // Iterate through a to b, If it is a multiple
//     // of 2 or 5 Mark index in array as 1
//     for (int i = a; i <= b; i++)
//         if (i % 2 == 0 || i % 5 == 0)
//             array[i - a] = 1;

//     cout << "MULTIPLES of 2 and 5:\n";
//     for (int i = a; i <= b; i++)
//         if (array[i - a] == 1)
//             cout << i << " ";

//     return 0;
// }

// Approach 3(Using Bit Manipulations) :

//  Here is a space optimized which uses bit manipulation technique that can be applied to problems mapping binary values in arrays.

// Size of int variable in 64 -
//     bit compiler is 4 bytes.1 byte is represented by 8 bit positions in memory.So,
// an integer in memory is represented by 32 bit positions(4 Bytes) these 32 bit positions can be used instead of just one index to hash binary values.

// We can Implement the above Approach for 32-bit integers by following these steps

//  Find the actual index in int[] that needs to be bit manipulated it will be bitwise index/ 32.
//  Find the index of bit in those 32 bits that needs to be turned on it will be bitwise index % 32.  Let’s Call it X
//  Turn on the bit by doing | (bitwise OR) with (1 << X) (here we turn on the Xth bit by bit manipulation)
//  To get the value of a bit at a bitwise index we calculate the same indices and do a bitwise & so that if Xth bit is on it will return an integer not equal to 0 which is true in C++.
// Now instead of using arithmetic operators we can use bitwise operations for efficiency

// C++ code for marking multiples
#include <bits/stdc++.h>
using namespace std;

// index >> 5 corresponds to dividing index by 32
// index & 31 corresponds to modulo operation of
// index by 32

// Function to check value of bit position whether
// it is zero or one
bool checkbit(int array[], int index)
{
    return array[index >> 5] & (1 << (index & 31));
}

// Sets value of bit for corresponding index
void setbit(int array[], int index)
{
    array[index >> 5] |= (1 << (index & 31));
}

/* Driver program to test above functions*/
int main()
{
    int a = 2, b = 10;
    int size = abs(b - a) + 1;

    // Size that will be used is actual_size/32
    // ceil is used to initialize the array with
    // positive number
    size = ceil((double)size / 32);

    // Array is dynamically initialized as
    // we are calculating size at run time
    int *array = new int[size];

    // Iterate through every index from a to b and
    // call setbit() if it is a multiple of 2 or 5
    for (int i = a; i <= b; i++)
        if (i % 2 == 0 || i % 5 == 0)
            setbit(array, i - a);

    cout << "MULTIPLES of 2 and 5:\n";
    for (int i = a; i <= b; i++)
        if (checkbit(array, i - a))
            cout << i << " ";

    return 0;
}
