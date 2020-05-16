#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction()
{
    // prints the following text to the console (welcome message)
    std::cout << R"(     ___,---.__          /'|`\          __,---,___
    ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
  ,'        |           ~'\     /`~           |        `.
 /      ___//              `. ,'          ,  , \___      \
|    ,-'   `-.__   _         |        ,    __,-'   `-.    |
|   /          /\_  `   .    |    ,      _/\          \   |
\  |           \ \`-.___ \   |   / ___,-'/ /           |  /
 \  \           | `._   `\\  |  //'   _,' |           /  /
  `-.\         /'  _ `---'' , . ``---' _  `\         /,-'
     ``       /     \    ,='/ \`=.    /     \       ''
             |__   /|\_,--.,-.--,--._/|\   __|
             /  `./  \\`\ |  |  | /,//' \,'  \
            /   /     ||--+--|--+-/-|     \   \
           |   |     /'\_\_\ | /_/_/`\     |   |
            \   \__, \_     `~'     _/ .__/   /
             `-._,-'   `-._______,-'   `-._,-'
   )" << '\n';

    std::cout << "\n\nThe Wendigo has been unleashed into this world! Your Mission: return the beast from whence it came!\n";
    std::cout << "You need to decipher the ancient locks in order to retrieve the artefacts needed to return the beast.\n";
}

void PrintLevelFlavourText(int Difficulty, string CurrentArtifact, string CurrentLocation)
{
    std::cout << "\nYou need to retrieve the " << CurrentArtifact << " from " << CurrentLocation << ". Current Level: " << Difficulty << "\n\n";
}

bool PlayGame(int Difficulty, string CurrentArtifact, string CurrentLocation)
{
    if (Difficulty == 1)
    {
        PrintIntroduction();
        PrintLevelFlavourText(Difficulty, CurrentArtifact, CurrentLocation);
    }
    else
    {
        PrintLevelFlavourText(Difficulty, CurrentArtifact, CurrentLocation);
    }

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // print CodeSum and CodeProduct to the console
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;    
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Nice going! That is the " << CurrentArtifact << " safely recovered! Let's get the next one ***";
        return true;
    }
    else
    {
        std::cout << "\n*** The ancient lock whirls in confusion, it seems you entered the code. Try Again! ***\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));

    string const ARTIFACTNAMES[]
    {
        "Enigmatic Book",
        "Thunder Crown",
        "Truth Canopic Chest",
        "Life Cloak",
        "Azure Statue",
        "Statue of Doom",
        "Urn of Darkness",
        "Stone of Chaos",
        "Gem of Passion",
        "Fleece of Benediction"
    };

    string const PLACENAMES[]
    {
        "Bearcliff",
        "Pinefort",
        "Crystalmount",
        "Madgrove",
        "Farwell",
        "Rosefort",
        "Stillchill",
        "Goldcall",
        "Sandborn",
        "Frosthaven"
    };
    
    int Difficulty = 1;
    int MaxDifficulty = 10;

    while (Difficulty <= MaxDifficulty)
    {
        string CurrentArtifact = ARTIFACTNAMES[Difficulty - 1];
        string CurrentLocation = PLACENAMES[Difficulty - 1];

        bool bLevelComplete = PlayGame(Difficulty, CurrentArtifact, CurrentLocation);

        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            ++Difficulty;
        }
    }

    std::cout << "\nYou have returned The Wendigo!\n\n";
    return 0;
}