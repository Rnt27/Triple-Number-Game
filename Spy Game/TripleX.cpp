#include <iostream>
#include <ctime>
#include <string>

bool PlayGame(int Difficulty, int maxDiff){

    int counter = maxDiff + 1 - Difficulty;

    //Start the story
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room\n";
    std::cout << "Enter the correct codes to continue...";
    
    std::cout << "\n***You see a counter that has a number at " << counter << " ...***" << std::endl << std::endl;

    //Declare integers needed
    //store player guess
    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;
    
    //store code numbers
    int CodeA = rand()%Difficulty + Difficulty;
    int CodeB = rand()%Difficulty + Difficulty;
    int CodeC = rand()%Difficulty + Difficulty;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    GuessA = 9999;
    GuessB = 9999;
    GuessC = 9999;
    std::string temp;

    std::cout << "- There are 3 numbers in the code that are less than " << Difficulty*2;
    std::cout << "\n- The numbers add to " << CodeSum;
    std::cout << "\n- The numbers multiply to give " << CodeProduct << std::endl;
    std::cout << "\nEnter the first digit: ";
    
    while(GuessA >= Difficulty*2){

        std::cin >> GuessA;
        if(GuessA >= Difficulty*2){

            std::cout << "\nNumbers must be less than " << Difficulty*2 << ". Try again\n";
            std::cin.clear();
            std::cin.ignore();

            counter--;
            std::cout << "Counter now at " << counter << " ..." << std::endl;
            if(counter == 0){

                std::cout << "\nYou've been caught!!! You must restart" << std::endl;
                std::cout << "\nPress enter to restart.";
                return false;

            }

        }
                
    }

    std::cout << "\n-->You entered: " << GuessA << std::endl;
    std::cout << "\nEnter the second digit: ";
    
    while(GuessB >= Difficulty*2){

        std::cin >> GuessB;
        
        
        if(GuessB >= Difficulty*2){

            std::cout << "\nNumbers must be less than " << Difficulty*2 << ". Try again\n";
            std::cin.clear();
            std::cin.ignore();

            counter--;
            std::cout << "Counter now at " << counter << " ..." << std::endl;
            if(counter == 0){

                std::cout << "\nYou've been caught!!! You must restart" << std::endl;
                std::cout << "\nPress enter to restart.";
                return false;

            }

        }
        
    }

    std::cout << "\n-->You entered: " << GuessB << std::endl;
    std::cout << "\nEnter the third digit: ";
    
    while(GuessC >= Difficulty*2){

        std::cin >> GuessC;
        if(GuessC >= Difficulty*2){

            std::cout << "\nNumbers must be less than " << Difficulty*2 << ". Try again\n";
            std::cin.clear();
            std::cin.ignore();

            counter--;
            std::cout << "Counter now at " << counter << " ..." << std::endl;
            if(counter == 0){

                std::cout << "\nYou've been caught!!! You must restart" << std::endl;
                std::cout << "\nPress enter to restart.";
                return false;

            }

        }
    }

    std::cout << "\n-->You entered: " << GuessC << std::endl;
    std::cout << "\nYour 3 entries are: " << GuessA << GuessB << GuessC;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\nYou win!" << std::endl;
        std::cout << "Press enter to continue" << std::endl;
        getline(std::cin, temp);
        
        return true;
    }
    else{
        std::cout << "\nYou lose! The world is Doomed!!!" << std::endl;
        std::cout << "\nPress enter to restart.";
        getline(std::cin, temp);
        
        return false;
    }

}

int main(){

    srand(time(NULL));  //create new random sequence based on time of day

    int LevelDifficulty =  1;
    int MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty){
        
        bool bLevelcomplete = PlayGame(LevelDifficulty, MaxDifficulty);

        std::cin.clear();   //Clears any errors
        std::cin.ignore();  //Discards the buffer just in case there were errors

        if(bLevelcomplete){

            //Increase the level difficulty
            LevelDifficulty++;

        }else{

            std::cout << "\nRestarting...";

            LevelDifficulty = 1;

        }
        
    }
    
    std::cout << "\n***Great work agent!!! You got all the files! Now get ouf of there!! ***" << std::endl;

    return 0;

}