#include <iostream>

int main()
{
    // prints the following text to the console (welcome message)
    std::cout << "The Wendigo has been unleashed into this world! Your Mission: return the beast from whence it came!" << std::endl;
    std::cout << "You need to decipher the ancient locks in order to retrieve the artefacts needed to return the beast" << std::endl;

    const int CodeA = 4;
    const int CodeB = 10;
    const int CodeC = 50;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // print CodeSum and CodeProduct to the console
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    int PlayerGuess;

    return 0;
}