// ## A Game of 21
// ### For this assignment, you will write a program that lets the user play against the computer in a variation of the popular blackjack card game. In this variation of the game, two six-sided dice are used instead of cards. The dice are rolled, and the player tries to beat the computer’s hidden total without going over 21.
// Here are some suggestions for the game’s design:
// ```
// • Each round of the game is performed as an iteration of a loop that repeats as long
// as the player agrees to roll the dice, and the player’s total does not exceed 21.
// • At the beginning of each round, the program will ask the users whether they want
// to roll the dice to accumulate points.
// • During each round, the program simulates the rolling of two six-sided dice. It rolls
// the dice first for the computer, and then it asks the user if he or she wants to roll.
// • The loop keeps a running total of both the computer and the user’s points.
// • The computer’s total should remain hidden until the loop has finished.
// • After the loop has finished, the computer’s total is revealed, and the player with the
// most points without going over 21 wins.
// ```
// ---
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

class Dice
{
    int sides;

public:
    Dice(int s = 0)
    {
        sides = s;
        if (sides < 2)
        {
            sides = 6;
        }
        srand(time(0));
    }

    int roll()
    {
        return (rand() % sides) + 1;
    }
    int getSides()
    {
        return sides;
    }

    void setSides(int s)
    {
        sides = s;
        if (sides < 2)
        {
            sides = 6;
        }
    }
};
class GameOf21
{
    Dice d1, d2;
    int userTotal, computerTotal;

public:
    GameOf21()
    {
        userTotal = 0;
        computerTotal = 0;
    }

    void play()
    {
        char choice;
        do
        {
            cout << "Roll the dice? (y/n): ";
            cin >> choice;
            if (choice == 'y')
            {
                userTotal += d1.roll() + d2.roll();
                cout << "Your total: " << userTotal << endl;
            }
        } while (choice == 'y' && userTotal <= 21);

        // Computer's turn
        while (computerTotal < 17)
        {
            computerTotal += d1.roll() + d2.roll();
        }

        // Determine the winner
        cout << "Your total: " << userTotal << endl;
        cout << "Computer's total: " << computerTotal << endl;
        if (userTotal > 21)
        {
            cout << "You bust! Computer wins." << endl;
        }
        else if (computerTotal > 21 || userTotal > computerTotal)
        {
            cout << "You win!" << endl;
        }
        else
        {
            cout << "Computer wins." << endl;
        }
    }
};

int main()
{
    GameOf21 game;
    game.play();
    return 0;
}
