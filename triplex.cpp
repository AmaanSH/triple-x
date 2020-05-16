#include <iostream>

int main()
{
    // prints the following text to the console (welcome message)
    std::cout << "The Wendigo has been unleashed into this world! Your Mission: return the beast from whence it came!\n";
    std::cout << "You need to decipher the ancient locks in order to retrieve the artefacts needed to return the beast\n\n";

    const int CodeA = 2;
    const int CodeB = 3;
    const int CodeC = 4;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // print CodeSum and CodeProduct to the console
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: ";

    // Store player guess
    int GuessA, GuessB, GuessC;    
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou Win!";
    }
    else
    {
        std::cout << "\nYou Lose!";
    }

    return 0;
}