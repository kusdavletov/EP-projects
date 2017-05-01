#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int bet, cash, profit = 0;
    do
    {
        cout << "Initial game money: ";
        cin >> cash;
        if (cash <= 0)
            cout << "Invalid game money. Game money should be more than 0." << endl;
    } while (cash <= 0);
    cout << "\n\n>>>>> Game Start!" << endl;
    do
    {
        do
        {
            cout << "How much you want to bet? (holding sum $" << cash << ") : ";
            cin >> bet;
            if (bet == 0)
                cout << "The money player bet should be more than 0" << endl;
            else if (bet < 0)
                cout << "The money player bet should be a positive number" << endl;
            else if (bet > cash)
                cout << "The money player bet should be less than or equal to player cash($" << cash << ")" << endl;
        } while (bet > cash || bet <= 0);
        int c1, c2, c3, c4, c5, c6, sum_player = 0, sum_dealer = 0;
        srand(time(NULL));
        c1 = rand() % 13 + 1;
        c2 = rand() % 13 + 1;
        c3 = rand() % 13 + 1;
        c4 = rand() % 13 + 1;
        c5 = rand() % 13 + 1;
        c6 = rand() % 13 + 1;
        cout << "Player's card deck: ";
        if (c1 == 1)
        {
            cout << "A, ";
            sum_player += 11;
        }
        else if (c1 == 11)
        {
            cout << "J, ";
            sum_player += 10;
        }
        else if (c1 == 12)
        {
            cout << "Q, ";
            sum_player += 10;
        }
        else if (c1 == 13)
        {
            cout << "K, ";
            sum_player += 10;
        }
        else
        {
            cout << c1 << ", ";
            sum_player += c1;
        }
        if (c2 == 1)
        {
            cout << "A";
            if (c1 != 1)
                sum_player += 11;
            else
                sum_player += 1;
        }
        else if (c2 == 11)
        {
            cout << "J";
            sum_player += 10;
        }
        else if (c2 == 12)
        {
            cout << "Q";
            sum_player += 10;
        }
        else if (c2 == 13)
        {
            cout << "K";
            sum_player += 10;
        }
        else
        {
            cout << c2;
            sum_player += c2;
        }
        cout << " (sum " << sum_player << ")" << endl;
        cout << "Dealer's card deck: ";
        if (c3 == 1)
        {
            cout << "A, ";
            sum_dealer += 11;
        }
        else if (c3 == 11)
        {
            cout << "J, ";
            sum_dealer += 10;
        }
        else if (c3 == 12)
        {
            cout << "Q, ";
            sum_dealer += 10;
        }
        else if (c3 == 13)
        {
            cout << "K, ";
            sum_dealer += 10;
        }
        else
        {
            cout << c3 << ", ";
            sum_dealer += c3;
        }
        if (c3 == 1 && c4 == 1)
            sum_dealer += 1;
        else if (c3 != 1 && c4 == 1)
            sum_dealer += 11;
        else if (c4 == 11 || c4 == 12 || c4 == 13)
            sum_dealer += 10;
        else
            sum_dealer += c4;
        cout << "?" << endl;
        if (sum_player == 21)
        {
            if (sum_player > sum_dealer)
            {
                cout << ">>>>>>>> BLACK JACK <<<<<<<<" << endl;
                cout << "Player win!" << endl;
                profit = 1.5 * bet;
                cash += profit;
                cout << "Player got $" << profit << " (holding sum $" << cash << ")" << endl;
            }
            else
            {
                cout << "BLACKJACK for both the player and the dealer!(Draw)" << endl;
                cout << "Pushing the game..." << endl;
                break;
            }
        }
        else
        {
            string choice;
            do
            {
                cout << "Player's choice (1. Hit 2. Stand) : ";
                cin >> choice;
            } while (choice != "1" && choice != "2");
            if (choice == "1")
            {
                cout << "Player`s card deck: ";
                if (c1 == 1)
                    cout << "A, ";
                else if (c1 == 11)
                    cout << "J, ";
                else if (c1 == 12)
                    cout << "Q, ";
                else if (c1 == 13)
                    cout << "K, ";
                else
                    cout << c1 << ", ";
                if (c2 == 1)
                    cout << "A, ";
                else if (c2 == 11)
                    cout << "J, ";
                else if (c2 == 12)
                    cout << "Q, ";
                else if (c2 == 13)
                    cout << "K, ";
                else
                    cout << c2 << ", ";
                if (c5 == 1)
                {
                    cout << "A";
                    if(c1 + c2 <= 10)
                        sum_player += 11;
                    else
                        sum_player += 1;
                }
                else if (c5 == 11)
                {
                    cout << "J";
                    sum_player += 10;
                }
                else if (c5 == 12)
                {
                    cout << "Q";
                    sum_player += 10;
                }
                else if (c5 == 13)
                {
                    cout << "K";
                    sum_player += 10;
                }
                else
                {
                    cout << c5;
                    sum_player += c5;
                }
                if ((c1 == 1 || c2 == 1 || c5 == 1) && sum_player > 21)
                    sum_player -= 10;
                cout << " (sum " << sum_player << ")" << endl;
                cout << "Dealer`s card deck: ";
                if (c3 == 1)
                    cout << "A";
                else if (c3 == 11)
                    cout << "J";
                else if (c3 == 12)
                    cout << "Q";
                else if (c3 == 13)
                    cout << "K";
                else
                    cout << c3;
                cout << ", ?" << endl;
            }
            cout << ">>> Comparing scores.." << endl;
            cout << "Dealer`s card deck : ";
            if (c3 == 1)
                cout << "A";
            else if (c3 == 11)
                cout << "J";
            else if (c3 == 12)
                cout << "Q";
            else if (c3 == 13)
                cout << "K";
            else
                cout << c3;
            if (c4 == 1)
                cout << ", A";
            else if (c4 == 11)
                cout << ", J";
            else if (c4 == 12)
                cout << ", Q";
            else if (c4 == 13)
                cout << ", K";
            else
                cout << ", " << c4;
            if (sum_dealer < 17 && sum_player < 21)
            {
                if(c6 == 1)
                {
                    cout << ", A";
                    if(c3 + c4 <= 10)
                        sum_dealer += 11;
                    else
                        sum_dealer += 1;
                }
                else if(c6 == 11)
                {
                    cout << ", J";
                    sum_dealer += 10;
                }
                else if(c6 == 12)
                {
                    cout << ", Q";
                    sum_dealer += 10;
                }
                else if(c6 == 13)
                {
                    cout << ", K";
                    sum_dealer += 10;
                }
                else
                {
                    cout << ", " << c5;
                    sum_dealer += c5;
                }
            }
            if ((c3 == 1 || c4 == 1 || c5 == 1) && sum_dealer > 21)
                sum_dealer -= 10;
            cout << " (sum " << sum_dealer << ")" << endl;
            if ((sum_player > sum_dealer && sum_player <= 21) || (sum_dealer > 21 && sum_player <= 21))
            {
                cout << "Player win!" << endl;
                profit = 1.5 * bet;
                cash += profit;
                cout << "Player got $" << profit << " (holding sum $" << cash << ")" << endl;
            }
            else if ((sum_dealer > sum_player && sum_dealer <= 21) || (sum_player > 21 && sum_dealer <= 21))
            {
                cout << "Player lose." << endl;
                profit = -bet;
                cash += profit;
                cout << "Player lost $" << bet << " (holding sum $" << cash << ")" << endl;
            }
            /*else if (sum_dealer > 21 && sum_player > 21)
            {
                cout << "Both the player and the dealer have sum more than 21!(Draw)" << endl;
                cout << "Pushing the game..." << endl;
                break;
            }*/
            else
            {
                cout << "Both the player and the dealer have equal sum!(Draw)" << endl;
                cout << "Pushing the game..." << endl;
            }
        }
        if (cash > 0)
        {
            string answer;
            do
            {
                cout << "\ncontinue game? (y/n) : ";
                cin >> answer;
            } while (answer != "n" && answer != "y" && answer != "Y" && answer != "N");
            string line;
            line.assign(40, '-');
            cout << line << endl;
            if (answer == "n" || answer == "N")
            {
                cout << "\n\n>>>>>>>>>> Game Over!\n";
                return 0;
            }
        }
    } while (cash > 0);
    cout << "\nPlayer lost all of the money\n\n\n>>>>>>>>>> Game Over!\n";
    return 0;
}
