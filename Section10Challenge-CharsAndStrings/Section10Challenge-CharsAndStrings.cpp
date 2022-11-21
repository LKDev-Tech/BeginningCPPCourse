// Section 10 Challenge - Substitution Cipher
/* A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string secret;
    //string encSecret;
    string alphabet { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$^&*()' " };
    string key      { "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr!#*8& 16$309)7@2^'45(" };
    //string lettersToReplace {};

    cout << "Please enter your secret phrase: ";
    getline(cin, secret);
    //lettersToReplace = secret;
    //unordered_set<char> log;
    //lettersToReplace.erase(remove_if(lettersToReplace.begin(), lettersToReplace.end(), [&](char const c) { return !(log.insert(c).second); }), lettersToReplace.end());
    cout << "Encrypting Message... " << endl;

    //for (char letter: lettersToReplace)
    //    replace(secret.begin(), secret.end(), letter, key.at(alphabet.find(letter)));
    for (size_t i{ 0 }; i < secret.length(); i++)
        secret.at(i) = key.at(alphabet.find(secret.at(i)));
    cout << "Encrypted Message: " << secret << endl;

    cout << "Decrypting Message..." << endl;
    for (size_t i{ 0 }; i < secret.length(); i++)
        secret.at(i) = alphabet.at(key.find(secret.at(i)));
    cout << "Decrypted Message: " << secret << endl;
}