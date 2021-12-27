#include <iostream>
#include <fstream>
#include <random>

// Length of array
unsigned int LENGTH = 0;
// Amount of password
unsigned int PASSWORD_AMOUNT = 0;

// Password amount & length
void length(){
    // Input password amount
    std::cout << "Password amount: ";
    std::cin >> PASSWORD_AMOUNT;
	// Input length
	std::cout << "Length of password: ";
	std::cin >> LENGTH;
	// If length is wrong 
	while (LENGTH <= 0)
	{
		std::cout << "\nPlease enter again";
		std::cin >> LENGTH;
		std::cout << '\n'; 
	}
}

// Customer`s password
char* password = new char[LENGTH];

// Input random symbols from array(all_symbols) to password
char* generate(){
    for (size_t i = 0; i < LENGTH; i++)
    {
        // int random_index = rand()% 4;
        password[i] = rand()%('z'-' ') + ' ';
    }
    return password;
}

// Print password
void print(){
    for (size_t i = 0; i < LENGTH; i++)
    {
        std::cout << password[i];
    }
    std::cout << '\n';
}

// Generate & print password 
// Write to file
void amount_password(){
    length();
    // Create or open file to write
    std::ofstream f("YourPasswords.txt");
        for (size_t i = 0; i < PASSWORD_AMOUNT; i++)
        {
            f << '\n' << generate();
            print();
        }
    // Close
    f.flush();
    f.close();
}

int main(){
    srand(time(0));

    amount_password();

    delete[] password;

	return 0;
}