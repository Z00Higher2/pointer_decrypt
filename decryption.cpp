// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: HW E5.14
// Implement two decryption functions corresponding to the above ciphers.
// When decrypting ciphertext, ensure that the produced decrypted string is equal to the original plaintext:
// decryptCaesar(ciphertext, rshift) == plaintext
// decryptVigenere(ciphertext, keyword) == plaintext
// Write a program decryption.cpp that uses the above functions to demonstrate encryption and decryption for both ciphers.
// It should first ask the user to input plaintext, then ask for a right shift for the Caesar cipher and report the ciphertext and its subsequent decryption. 
// After that, it should do the same for the Vigenere cipher.


#include <iostream>
#include <cctype>
using namespace std;

// Function to shift a character by a specified right shift
char shiftChar(char c, int rshift) {
    if (int(c) >= 65 && int(c) <= 90) { // Uppercase letter
        c += rshift;

        if (c > 90) {
            c -= 26;
            return c;
        } else if (c < 65) {
            c += 26;
            return c;
        }

        return c;
    } else if (int(c) >= 97 && int(c) <= 122) { // Lowercase letter
        int a = int(c) + rshift;
        if (a > 122) {
            a -= 26;
            c = a;
            return c;
        } else if (a < 97) {
            a += 26;
            c = a;
            return c;
        }

        c = a;
        return c;
    }

    return c; // Non-alphabetic character
}

// Function to encrypt plaintext using Caesar cipher
string encryptCaesar(string plaintext, int rshift) {
    char c;

    for (int i = 0; i < plaintext.length(); i++) {
        c = plaintext[i];
        plaintext[i] = shiftChar(c, rshift); // call the function to shift user inputted text
    }

    return plaintext;
}

// Function to encrypt plaintext using Vigenere cipher
string encryptVigenere(string plaintext, string keyword) {
    char c, keyc;
    int n = 0; // Initialize the keyword index

    for (int i = 0; i < plaintext.length(); i++) {
        if (n > keyword.size() - 1) {
            n = 0; // Reset the keyword index if it exceeds the keyword length
        }

        c = plaintext[i];
        keyc = keyword[n];

        int kshift = (int(keyc) - 97);

        if (isalpha(c) == 0) {
            plaintext[i] = shiftChar(c, 0); // Non-alphabetic character, no shift
        } else {
            plaintext[i] = shiftChar(c, kshift); // Alphabetic character, shift based on keyword
            n++;
        }
    }

    return plaintext;
}

// Function to decrypt Caesar cipher
string decryptCaesar(string ciphertext, int rshift) {
    char c;

    for (int i = 0; i < ciphertext.length(); i++) {
        c = ciphertext[i];
        ciphertext[i] = shiftChar(c, rshift * (-1)); // Decrypt by shifting in the opposite direction
    }

    return ciphertext;
}

// Function to decrypt Vigenere cipher
string decryptVigenere(string ciphertext, string keyword) {
    char c, keyc;
    int n = 0; // Initialize the keyword index

    for (int i = 0; i < ciphertext.length(); i++) {
        if (n > keyword.size() - 1) {
            n = 0; // Reset the keyword index if it exceeds the keyword length
        }

        c = ciphertext[i];
        keyc = keyword[n];
        int kshift = (int(keyc) - 97) * (-1); // Decrypt by shifting in the opposite direction

        if (isalpha(c) == 0) {
            ciphertext[i] = shiftChar(c, 0); // Non-alphabetic character, no shift
        } else {
            ciphertext[i] = shiftChar(c, kshift); // Alphabetic character, shift based on keyword
            n++;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, keyword;
    int rshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "\n= Caesar =\n";

    cout << "Enter shift: ";
    cin >> rshift;

    cout << "Ciphertext: " << encryptCaesar(plaintext, rshift) << endl;
    cout << "Decrypted: " << decryptCaesar(encryptCaesar(plaintext, rshift), rshift) << endl;

    cout << "\n= Vigenere =\n";

    cout << "Enter keyword: ";
    cin >> keyword;

    cout << "Ciphertext: " << encryptVigenere(plaintext, keyword) << endl;
    cout << "Decrypted: " << decryptVigenere(encryptVigenere(plaintext, keyword), keyword);

    return 0;
}
