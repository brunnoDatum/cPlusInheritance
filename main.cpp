#include <iostream>
#include "Knight.h"
#include "Wizard.h"
#include "Orc.h"
#include "Undead.h"
#include <time.h>

using namespace std;

auto * knight = new Knight("", 100, 5);
auto * wizard = new Wizard("", 80, 5);

auto * orc = new Orc(100, {});
auto * undead = new Undead(70, {});

void classCreationMenu(int &firstMenuChoice);

void playerDetails(int firstMenuChoice, const string &playerName);

void enemyDetails(int &enemyRandom);

void createOrcTaunts();

void createUndeadTaunts();

void enemiesTaunts(int &enemyRandom);

void playerAttacks(int &firstMenuChoice);

void playerSpecialAttacks(int &firstMenuChoice);

void enemyAttacks(int &enemyRandom);

int main() {

    srand((unsigned) time(NULL));

    int firstMenuChoice = 0;
    bool gameOn = true;
    string playerName;

    while (gameOn) {
        classCreationMenu(firstMenuChoice);

        while (cin.fail() || (firstMenuChoice < 1 || firstMenuChoice > 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input! Try again: ";
            cin >> firstMenuChoice;
        }

        cin.ignore();

        //getline did not work outside main, could not find out why.
        cout << "What is your character name?" << endl;
        getline(cin, playerName);

        while (playerName.length() < 3) {
            cout << endl;
            cout << "You must enter at least 3 characters! Enter again: ";
            getline(cin, playerName);
        }

        bool battleReady = false;

        playerDetails(firstMenuChoice, playerName);
        cout << "Are you ready to battle? (0 = NO, 1 = YES)" << endl;
        cin >> battleReady;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You have entered wrong input! Enter again: ";
            cin >> battleReady;
        }

        int round = 0;
        int enemyRandom = (arc4random() % 2) + 1;

        if (enemyRandom == 1) createOrcTaunts();
        else createUndeadTaunts();

        enemyDetails(enemyRandom);

        while (battleReady) {

            system("read -n 1 -s -p \"Press any key to continue...\""); //MAC
            cout << endl;
            round++;

            switch(round) {
                case 1 :
                    enemiesTaunts(enemyRandom);
                    break;
                case 2  :
                    playerAttacks(firstMenuChoice);
                    break;
                case 3  :
                    enemiesTaunts(enemyRandom);
                    break;
                case 4  :
                    playerSpecialAttacks(firstMenuChoice);
                    break;
                case 5  :
                    enemyAttacks(enemyRandom);
                    break;
                case 6  :
                    enemyAttacks(enemyRandom);
                    break;
                case 7  :
                    playerSpecialAttacks(firstMenuChoice);
                    break;
                case 8  :
                    enemiesTaunts(enemyRandom);
                    break;
                case 9  :
                    playerSpecialAttacks(firstMenuChoice);
                    break;
                case 10  :
                    cout << "The enemy was slain!" << endl;
                    cout << "Congratulations!" << endl;
                    battleReady = false;
                    gameOn = false;
                    break;
                default:break;
            }

        }
    }

    cout << "Exiting Game!" << endl;
    return 0;
}

void playerDetails(int firstMenuChoice, const string &playerName) {
    cout << "Your player details:" << endl;
    cout << "Class: " << ((firstMenuChoice == 1) ? "Knight" : "Wizard") << endl;
    cout << "Name: " << playerName << endl;
    cout << "Health: " << ((firstMenuChoice == 1) ? knight->getHealth() : wizard->getHealth()) << endl;
    cout << endl;
}

void enemyDetails(int &enemyRandom) {
    cout << "The enemy details:" << endl;
    cout << "Enemy: " << ((enemyRandom == 1) ? "Orc" : "Undead") << endl;
    cout << "Health: " << ((enemyRandom == 1) ? orc->getHealth() : undead->getHealth()) << endl;
    cout << endl;
}

void classCreationMenu(int &firstMenuChoice) {
    cout << "Welcome to RPG battle!" << endl;
    cout << "What type of player do they want to play as?" << endl;
    cout << "1 -> Knight" << endl;
    cout << "2 -> Wizard" << endl;
    cout << "Enter your choice: ";
    cin >> firstMenuChoice;
}

void createOrcTaunts() {
    vector<string> orcTaunts {"You will be dead scum!", "I will cut you to pieces!", "For the Horde!"};
    orc->setTaunts(orcTaunts);
}

void createUndeadTaunts() {
    vector<string> undeadTaunts {"I will reap your flesh from the bones!", "Uurrrgh!", "Brains!"};
    undead->setTaunts(undeadTaunts);
}

void enemiesTaunts(int &enemyRandom) {
    cout << "The enemy taunts you:" << endl;
    if (enemyRandom == 1) orc->tauntPlayer();
    else undead->tauntPlayer();
}

void playerAttacks(int &firstMenuChoice) {
    cout << "The player attacks:" << endl;
    if (firstMenuChoice == 1) knight->normalAttack();
    else wizard->normalAttack();
}

void playerSpecialAttacks(int &firstMenuChoice) {
    cout << "The player performs a special attack:" << endl;
    if (firstMenuChoice == 1) knight->specialAttack();
    else wizard->specialAttack();
}

void enemyAttacks(int &enemyRandom) {
    cout << "The enemy attacks:" << endl;
    if (enemyRandom == 1) orc->normalAttack();
    else undead->normalAttack();
}