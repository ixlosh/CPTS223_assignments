/*
ADVANTAGES/DISADVANTAGES LINKED LIST
Advantage-> Using linked list with storing commands allow infinite number of commands to be stored, if we were to use
arrays for this then we would have to allocate a fixed number of space for it before running.
Disadvantage-> Because a singly linked list can only traverse forwards, we sometimes have to go all the way back
and start from the start to go back one step -this happens when we try to remove a link in the middle of the list.
ADVANTAGES/DISADVANTAGES ARRAY
Advantage-> Because at any point accessing an element in an array is easy, they are much lighter on the workload of
computing unit.
Disadvantage-> Even though elements are easier to access, limit of such elements are defined before runtime, thus 
if too much information is loaded onto an array, overflow might happen -some data might possibly be lost-.
*/

#include "array.h"
#include "linkedList.h"

int main()
{

    srand(time(NULL));

    std::string userName, newCommandToAdd, oldCommandTodelete;
    int selection;

    LinkedList<std::string, std::string>commands;
    readAllCommands(&commands);

    Array<std::string, int> players;
    readAllPlayers(&players);

    std::cout << "================================= The Game ===================================" << std::endl;

    while (true)
    {
        std::cout << "Please select an option listed below:\n";
        std::cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n";
        std::cout << "Your selection: ";
        std::cin >> selection;

        if (std::cin.fail()) // the input is not an integer
        {
            std::cout << "Your selection is invalid. Please select again." << std::endl;
            std::cout << "=============================================================================" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else
        {
            switch (selection)
            {
                case 1: // Game Rules
                {
                    std::cout << "================================= The Game ===================================" << std::endl;
                    std::cout << "================================= Game Rule ===================================" << std::endl;
                    std::cout << "To play the game, select \"2\" where you will be prompted for your name and number of questions.\n";
                    std::cout << "Each question presents a specific Linux command where you will be able to choose from 3 different options. Each correct answer yields a point.\n";
                    std::cout << "You can also add and delete commands as needed.\n";
                    std::cout << "================================= Game Rule ===================================" << std::endl << std::endl;

                    std::cout << "================================= The Game ===================================" << std::endl;

                    break;
                }

                case 2: case 3: // 2. Play Game; 3. Load Previous Game
                {
                    std::cout << "================================= The Game ===================================" << std::endl;
                    
                    std::cout << "Please enter your username: ";
                    std::cin >> userName;

                    if (selection == 3) {

                        bool match = false;
                        int pointsAccumulated = 0;

                        for (int i = 0; i < players.accessPosition(); i++) {

                            if (userName == players.accessArrayPosition(i)->getName()) {

                                match = true;
                                pointsAccumulated = players.accessArrayPosition(i)->getPoint();

                            }

                        }

                        if (match) {

                            std::cout << "Player found." << std::endl;
                            std::cout << "Username: " << userName << std::endl;
                            std::cout << "Total Points Accumulated: " << pointsAccumulated << std::endl;

                        }
                        else std::cout << "No matching username was found. A new profile will be created after the game concludes." << std::endl;

                        std::cout << "================================= The Game ===================================" << std::endl;

                    }

                    int noGenerate = 0;

                    if (commands.getListSize() < 30) { // if size is less than deignated maximum (30), size will be the new maximum

                        while (noGenerate<5 || noGenerate>commands.getListSize()) {

                            std::cout << "Please enter game size (5-" << commands.getListSize() << " questions):" << std::endl;
                            std::cin >> noGenerate;

                            if (noGenerate<5 || noGenerate>commands.getListSize()) std::cout << "Please enter appropriate amount to generate." << std::endl;

                        }

                    }
                    else {

                        while (noGenerate < 5 || noGenerate>30) {

                            std::cout << "Please enter game size (5-30 questions):" << std::endl;
                            std::cin >> noGenerate;

                            if (noGenerate<5 || noGenerate>30) std::cout << "Please enter appropriate amount to generate." << std::endl;

                        }

                    }
                   
                    std::cout << "================================= The Game ===================================" << std::endl;

                    int numberList[30] = { 0 };

                    for (int i = 0; i < noGenerate; i++) {

                        bool isRepeated = false;

                        do { // we need a do/while loop here because generating a random number once is required to check if that number is repeated
                             // this ensures that a command is only shown once
                            numberList[i] = rand() % commands.getListSize();

                            if (i > 0) {

                                int repeat = 0;

                                for (int m = i - 1; m >= 0; m--) {

                                    if (numberList[m] == numberList[i]) repeat++;

                                }

                                if (repeat != 0) isRepeated = true;
                                else isRepeated = false;

                            }

                        } while (isRepeated);
                        
                    }

                    int points = 0;

                    for (int n = 0; n < noGenerate; n++) {

                        std::cout << "Question Number " << n + 1 << std::endl;

                        Node<std::string, std::string>* tempHead = commands.getHeadPtr();
                        for (int r = numberList[n]; r > 0; r--) tempHead = tempHead->getNextPtr();

                        std::cout << *(tempHead->getData1()) << std::endl;

                        int correctChoice = rand() % 3 + 1;
                        int falseChoiceNo[2] = { 0 };

                        do { 

                            falseChoiceNo[0] = rand() % commands.getListSize();
                            
                        } while (falseChoiceNo[0] == numberList[n]);
                        do {

                            falseChoiceNo[1] = rand() % commands.getListSize();

                        } while (falseChoiceNo[1] == numberList[n] || falseChoiceNo[1] == falseChoiceNo[0]);

                        if (correctChoice == 1) std::cout << "1. " << *(tempHead->getData2()) << std::endl;
                        else {

                            tempHead = commands.getHeadPtr();
                            for (; falseChoiceNo[0] > 0; falseChoiceNo[0]--) tempHead = tempHead->getNextPtr();
                            std::cout << "1. " << *(tempHead->getData2()) << std::endl;

                        }

                        if (correctChoice == 2) {

                            tempHead = commands.getHeadPtr();
                            for (; numberList[n] > 0; numberList[n]--) tempHead = tempHead->getNextPtr();
                            std::cout << "2. " << *(tempHead->getData2()) << std::endl;

                        }
                        else {

                            if (correctChoice == 1) {

                                tempHead = commands.getHeadPtr();
                                for (; falseChoiceNo[0] > 0; falseChoiceNo[0]--) tempHead = tempHead->getNextPtr();
                                std::cout << "2. " << *(tempHead->getData2()) << std::endl;

                            }
                            else {

                                tempHead = commands.getHeadPtr();
                                for (; falseChoiceNo[1] > 0; falseChoiceNo[1]--) tempHead = tempHead->getNextPtr();
                                std::cout << "2. " << *(tempHead->getData2()) << std::endl;

                            }

                        }

                        if (correctChoice == 3) {

                            tempHead = commands.getHeadPtr();
                            for (; numberList[n] > 0; numberList[n]--) tempHead = tempHead->getNextPtr();
                            std::cout << "3. " << *(tempHead->getData2()) << std::endl;

                        }
                        else {

                            tempHead = commands.getHeadPtr();
                            for (; falseChoiceNo[1] > 0; falseChoiceNo[1]--) tempHead = tempHead->getNextPtr();
                            std::cout << "3. " << *(tempHead->getData2()) << std::endl;

                        }
                       
                        int answer = 0;

                        std::cout << "Please enter your answer: ";

                        while (answer != 1 && answer != 2 && answer != 3) {

                            std::cin >> answer;
                            if (answer != 1 && answer != 2 && answer != 3) std::cout << "Please enter a permissible answer (an integer 1-3)." << std::endl;

                        }
                        
                        if (answer == correctChoice) {

                            std::cout << "Good job! Your answer " << answer << " is correct. You have gained 1 point." << std::endl;
                            points++;

                        }
                        else {

                            std::cout << "Sorry, that answer is incorrect. Correct answer was " << correctChoice << "." << std::endl;
                            points--;

                        }

                        std::cout << "Your point total is now -> " << points << std::endl;

                        std::cout << "================================= The Game ===================================" << std::endl;
                    }

                    std::cout << "Session completed. Going back to main menu." << std::endl;

                    bool match = false;
                    int userPosition = -1;

                    for (int h = 0; h < players.accessPosition(); h++) if (userName == players.accessArrayPosition(h)->getName()) {

                        match = true;
                        userPosition = h;

                    }

                    if (match) {

                        players.accessArrayPosition(userPosition)->addPoints(points);

                    }
                    else {

                        players.accessArrayPosition(players.accessPosition())->setName(userName);
                        players.accessArrayPosition(players.accessPosition())->setPoint(points);
                        players.upPosition();

                    }

                    std::cout << "================================= The Game ===================================" << std::endl;

                    break;
                }

                case 4: // Add Command
                {
                    std::cout << "================================= The Game ===================================" << std::endl;
                    std::cout << "To add a command to the library, please enter the command name that you would like add: ";
                    std::cin >> newCommandToAdd;

                    int repeatCheck = 0;
                    Node<std::string, std::string>* tempHead = commands.getHeadPtr();
                    while (tempHead != nullptr) {

                        if (newCommandToAdd == *(tempHead->getData1())) repeatCheck++;
                        tempHead = tempHead->getNextPtr();

                    }
                    if (repeatCheck != 0) std::cout << "Please enter a new entry. Already existing commands are not accepted. Returning to main menu." << std::endl;
                    else {

                        std::string newCommandDescription;
                        char confirmation = '$';

                        std::cout << "Please enter description for the new command: " << newCommandToAdd << std::endl;
                        std::cin >> newCommandDescription;
                        
                        std::cout << "Description for the new command is: " << newCommandDescription << std::endl;
                        std::cout << "Do you confirm this decision? (Y/N - case sensitive)" << std::endl;

                        while (confirmation != 'Y' && confirmation != 'N') {

                            std::cin >> confirmation;

                            if (confirmation == 'Y') std::cout << "Success. New command has been added. Returning back to main menu." << std::endl;
                            else if (confirmation == 'N') std::cout << "New command draft has been scraped. No new command has been added. Returning back to main menu." << std::endl;
                            else std::cout << "Please enter an acceptable input. (Make sure the letter is capital.)" << std::endl;

                        }
                        
                        if (confirmation == 'Y') {

                            Node<std::string, std::string>* newNode = new Node<std::string, std::string>(newCommandToAdd, newCommandDescription);
                            commands.insertNode(newNode);

                        }
                        
                    }

                    std::cout << "================================= The Game ===================================" << std::endl;

                    break;
                }

                case 5: // Remove Command
                {
                    std::cout << "================================= The Game ===================================" << std::endl;
                    std::cout << "Please enter the name of the command that you would like remove: ";
                    std::cin >> oldCommandTodelete;
                    
                    bool matchFound = false;
                    int position = 0;

                    Node<std::string, std::string>* tempHead = commands.getHeadPtr();
                    while (!matchFound && tempHead != nullptr) {

                        if (oldCommandTodelete == *(tempHead->getData1())) matchFound = true;
                        else {
                            tempHead = tempHead->getNextPtr();
                            position++;
                        }

                    }

                    if (matchFound) {

                        commands.deleteNode(position);
                        std::cout << "Designated entry has been deleted. Returning back to main menu." << std::endl;

                    }
                    else {

                        std::cout << "No entry matching the input was found. Returning back to main menu." << std::endl;

                    }

                    std::cout << "================================= The Game ===================================" << std::endl;

                    break;
                }
                    
                case 6: // Exit
                {

                    std::cout << "================================= The Game ===================================" << std::endl;
                    std::cout << "Exiting the program..." << std::endl;

                    writeAllCommands(commands);
                    writeAllPlayers(players);

                    return 0;
                }


            } // end of switch(selection)
        } // end of else: check (cin.fail())
        
    } // end of while(true)
} // end of int main()
