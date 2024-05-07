#include <iostream>
#include <string>
#include <vector>

// Function to encrypt a message using the Transposition technique
std::string encrypt(const std::string& message, int key) 
{
    std::string encryptedText = "";
    int col = message.length() / key;
    int row = key;
    if (message.length() % key != 0) 
	{
        col++;
    }
    char rail[row][col];

    for (int i = 0; i < row; i++) 
	{
        for (int k = 0; k < col; k++) 
		{ 
            int index = i * col + k;
            if (index < message.length()) 
			{
                rail[i][k] = message[index];
            } else 
			{
                rail[i][k] = '*'; // Use '*' to fill the empty spaces
            }
        }
    }

    for (int i = 0; i < col; i++) 
	{
        for (int k = 0; k < row; k++)
		{
            encryptedText += rail[k][i];
        }
    }

    return encryptedText;
}

// Function to decrypt a message using the Transposition technique
std::string decrypt(const std::string& encryptedText, int key) 
{
    std::string decryptedText = "";
    int col = encryptedText.length() / key;
    int row = key;
    char rail[row][col];

    for (int i = 0; i < col; i++) 
	{
        for (int k = 0; k < row; k++) 
		{
            int index = i * row + k;
            rail[k][i] = encryptedText[index];
        }
    }

    for (int i = 0; i < row; i++) 
	{
        for (int k = 0; k < col; k++) 
		{
            decryptedText += rail[i][k];
        }
    }

    return decryptedText;
}

int main() 
{
    std::string message;
    int key;
 
    // Take input from the user
    std::cout << "Enter the message to be encrypted: ";
    std::getline(std::cin, message);
    std::cout << "Enter the key: ";
    std::cin >> key;

    // Encrypt the message
    std::string encryptedText = encrypt(message, key);
    std::cout << "Encrypted message is: " << encryptedText << std::endl;

    // Decrypt the message
    std::string decryptedText = decrypt(encryptedText, key);
    std::cout << "Decrypted message is: " << decryptedText << std::endl;

    return 0;
}

