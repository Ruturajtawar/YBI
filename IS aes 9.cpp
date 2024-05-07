#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//AES S-BOX
const unsigned char s_box[256]=
{
	
	
};

//RCON values to key schedule
const unsigned char rcon[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x1B, 0x36};

//Number of words in keys
const int key_words = 4;

//number of round AES-128
const int num_rounds = 10;

//KEY Expansion function
void keyExpansion(const vector<unsigned char>& key, vector<unsigned char>& roundKeys)

{
	roundKeys=key;
	
	for(int i = key_words; i < (key_words * (num_rounds + 1));++i)
	
	{
		unsigned char temp[4];
		for (int j = 0; j < 4; ++j)
		{
			temp[j] = roundKeys[(i - 1) * 4 +j];
		}
		
		if (i % key_words == 0) 
		{
            // Rotate word
            unsigned char temp_byte = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = temp_byte;
            
             // Substitute word using S-box
            for (int j = 0; j < 4; ++j) 
			{
                temp[j] = s_box[temp[j]];
            }
            
             // XOR with Rcon
            temp[0] ^= rcon[i / key_words - 1];      
        }
		
		 // XOR with the previous word
        for (int j = 0; j < 4; ++j)
        {
            roundKeys.push_back(roundKeys[(i - key_words) * 4 + j] ^ temp[j]);
        }		
	}	
}


int main()
{
	// Input matrix
	int rows, columns;
    rows=4;
	cout << "No. of rows: " <<rows<< endl;
	columns=4;
	cout << "No. of columns: " <<columns<<endl;
	
	char plain[rows][columns];
	cout << "Enter plain text:" << endl;
	
	for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < columns; j++) 
		{
            cin >> plain[i][j];
        }
    }
	
	for (int j = 0; j < columns; j++) 
	{
		cout << "[";
        for (int i = 0; i < rows; i++) 
		{
            cout << (plain[i][j]) << " ";
        }
        cout << "]";
        cout << endl;
    }
    
    
    
	 // Convert into ASCII
	cout << "Ascii=" << endl;
	for (int j = 0; j < columns; j++) 
	{
		cout << "[";
        for (int i = 0; i < rows; i++) 
		{
            cout << int(plain[i][j]) << " ";
        }
        cout << "]";
        cout << endl;
    }
	
	
	
	// Convert into hexadecimal
	cout << "Hexadecimal=" << endl;
	for (int j = 0; j < columns; j++) 
	{
		cout << "[";
        for (int i = 0; i < rows; i++) 
		{
            cout << hex << int(plain[i][j]) << " ";
        }
        cout << "]";
        cout << endl;
    }
	
	
	
	// Example key (128 bits)
	vector<unsigned char> key;
	for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
        	key.push_back(static_cast<unsigned char>(plain[i][j]));
		}
    }
	
	
	// Vector to store round keys
    vector<unsigned char> roundKeys;
	
	
	 // Generate round keys
    keyExpansion(key, roundKeys);
	
	
	// Display the round keys
	 for (int i = 0; i < num_rounds + 1; ++i)
	{
        cout << "Round Key " << i << ": ";
        for (int j = 0; j < 16; ++j) 
		{
            cout << hex << setw(2) << setfill('0') << (int)roundKeys[i * 16 + j] << " ";
        }
        cout << endl;
    }	
	return 0;
}
