#include <iostream>
#include <random>
// Password length
#define LENGTH 16

// Customer`s password
char* password = new char[LENGTH];
// Random symbols
char* all_symbols = new char[4];
// CapsOFF letter
char small_letter = '\0';
// CapsON letter
char big_letter = '\0';
// Number
char number = '\0';
// Symbols like ' + - )( ! @
char symbol = '\0';

// Initialize
void init(){
    all_symbols[0] = small_letter;
    all_symbols[1] = big_letter;
    all_symbols[2] = number;
    all_symbols[3] = symbol;
}

// Generate random symbols
void generate(){
	all_symbols[0] = rand()%('z'-'a') + 'a';
    all_symbols[1] = rand()%('Z'-'A') + 'A';
    all_symbols[2] = rand()%('9' - '0') + '0';
	all_symbols[3] = rand()%('/' - ' ') + ' ';
}

// Input random symbols from array(all_symbols) to password
void input(){
    init();
    for (size_t i = 0; i < LENGTH; i++)
    {
        generate();
        int random_index = rand()% 4;
        password[i] = all_symbols[random_index];
    }
}

// Print password
void print(){
    for (size_t i = 0; i < LENGTH; i++)
    {
        std::cout << password[i];
    }
    std::cout << '\n';
}

int main(){
    srand(time(NULL));

    input();
    print();

    delete[] password;
    delete[] all_symbols;

	return 0;
}
