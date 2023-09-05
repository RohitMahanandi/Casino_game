#include <bits/stdc++.h>
using namespace std;


void printcard(int value) 
{
    cout << "--------------"<< endl;
    cout << "|            |"<< endl;
    cout << "|            |"<< endl;
    cout << "|     "<<value<<"      |"<< endl;
    cout << "|            |"<< endl;
    cout << "|            |"<< endl;
    cout << "--------------"<< endl;

    
}


int exiting() {
    string opinion;
    cout << "Do you still want to play the game?(Yes/No): ";
    cin >> opinion;
    transform(opinion.begin(),opinion.end(),opinion.begin(),::toupper);

    if (opinion == "NO") return -1;
    else if (opinion == "YES") return 1;
    else {
        cout << "Invalid Answer, Please Try again" << endl;
        return exiting();}


}

int main() {
    cout << "--------------------------------------------"<< endl;
    cout << "|Welcome to the Casino Number Guessing Game|"<< endl;
    cout << "--------------------------------------------"<< endl;
    int money = 10000;
    srand(time(NULL));
    
    cout << "Initializing 10000 currency"<< endl;
    cout << "welcome to the table"<< endl;
    cout<< "--------------------------------------------"<< endl;
    cout <<"Rule is the person who will get the number close to 9 will win"<< endl;
    float win_ratio = 2;
    while(1) {


        if (money>15000) win_ratio = 1.5;
        else if (money>20000) win_ratio = 1.3;
        cout << "Your Money: "<< money << endl;
        cout << "Win Ratio: "<< win_ratio << endl;

        int bet = 0;
        while(1) {
        cout << "Your bet: ";
        cin >> bet;
        if (bet <= money) break;
        cout <<"Invalid bet, Please try again" << endl;
        
        }

        money -= bet;
        int number_of_cards;
        cout<< "How many cards are you willing to take: ";
        cin>> number_of_cards;
        vector<int> user_cards;
        vector<int> computer_cards;
        int i1,i2;
        
        for (int i = 0;i< number_of_cards;i++) {
            i1 = rand()%10;
            i2 = rand()%10;
            user_cards.push_back(i1);
            computer_cards.push_back(i2);
    
        }
        int computer;
        int mine;
        computer = *max_element(computer_cards.begin(), computer_cards.end());
        mine = *max_element(user_cards.begin(),user_cards.end());

        cout << "showing only the cards that are more close to 9" << endl;
        cout << "\033[4mYour Card"<< endl;
        cout << "\033[0m";
        printcard(mine);
        cout << "\033[4mComputer Card" << endl;
        cout << "\033[0m";
        printcard(computer);

        if(computer == mine) {
            cout << "Its Tie"<< endl;
            money += bet;
        }


        else {
            cout<< "----------------------"<< endl;
            if (9-computer>9-mine) {
                cout << "\033[1m";
                cout <<"\033[34mYou win the game" << endl;
                cout << "\033[0m";
                
                money += bet*win_ratio;
            }
            else {
                cout << "\033[1m";
                cout << "\033[31mYou lose the game" << endl;
                cout << "\033[0m";
                money -= bet;
            
            }
            cout<< "----------------------"<< endl;
            cout << "Computer Number: "<< computer << endl;
            cout << "Your Number: " << mine << endl;
            cout << "Remaining money: "<< money << endl;}


        if (money<0) {
            cout << "\033[41m";
            cout << "You have less money than minimum"<< endl;
            cout << "\033[0m";
            break;
        }
        int answer = exiting();
        if (answer == -1) break;

    }
    if (money<0) {
        cout << "\033[41m";
        cout << "You lost " << money<< "\033[0m" << endl;
        
    }
    else {
    cout << "Congratulations!, You won " << money << endl;
    }
    
}