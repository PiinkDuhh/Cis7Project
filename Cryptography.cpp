// C++ code to implement Vigenere Cipher 
#include<bits/stdc++.h> 
using namespace std; 

// This function generates the key in a cyclic manner until it's length isi'nt equal to the length of original text 
string generateKey(string str, string key) 
{ 
int x = str.size(); 

for (int i = 0; ; i++) 
{ 
if (x == i) 
i = 0; 
if (key.size() == str.size()) 
break; 
key.push_back(key[i]); 
}
cout << "extending keyword to match message...." << endl;
cout << "keyword extended is " << key << endl;
return key; 
} 

// This function returns the encrypted text generated with the help of the key 
string Encrypt(string str, string key) 
{ 
string cipher_text; 

for (int i = 0; i < str.size(); i++) 
{ 
// converting in range 0-25 
int x = (str[i] + key[i]) %26; 

// convert into alphabets(ASCII) 
x += 'A'; 

cipher_text.push_back(x); 
} 
return cipher_text; 
} 

// This function decrypts the encrypted text 
// and returns the original text 
string Decrypt(string cipher_text, string key){ 
string orig_text; 

for (int i = 0 ; i < cipher_text.size(); i++) 
{ 
// converting in range 0-25 
int x = (cipher_text[i] - key[i] + 26) %26; 

// convert into alphabets(ASCII) 
x += 'A'; 
orig_text.push_back(x); 
}

return orig_text; 
} 

// Driver program to test the above function 
int main() 
{ 

string fun = ""; 

cout << "Pleas type 'Encrypt' to encrypt, or 'Decrypt' to decrypt a message" << endl;
cin >> fun;

if (fun == "Encrypt"){
string str = "";
string keyword = "";
cout << "PLease input the message you want tot encrypt" << endl;
cin >> str;
cout << "Enter the keyword to the key to key the thing with" << endl;
cin >> keyword;
string key = generateKey(str, keyword); 
string cipher_text = Encrypt(str, key); 
cout << "Ciphertext : " << cipher_text << "\n"; 
}
else if (fun == "Decrypt"){
string cipher_text = "";
string key = "";
cout << "Enter the cipher text" << endl;
cin >> cipher_text;
cout << "Enter the keyword used to encrypt the ciphertext" << endl;
cin >> key;
string keyx = generateKey(cipher_text, key);

cout << "Original/Decrypted Text : " << Decrypt(cipher_text, keyx); 
}
}
