#include <iostream>
using namespace std;

const int LUCKY_NUMS =10;

/*// Function for calling Linear Search
int ticketSearch(const int [], int, int);*/

// Function for calling Binary Search
int binarySearch (const int array[], int size, int value);

int main ()
{
    char again;
    int winningNum;
    int playerNum;
    int ticket;
    const int LUCKY_NUMS = 10;

    // Array of winning numbers
    int lottoTix[LUCKY_NUMS] = {13579, 26791, 26792, 33445, 55555,
                                62483, 77777, 79422, 85647, 93121};

    // Decide if they want to continue playing

    for (int week = 0; week < 10; week++)
    {
        // Winning lotto ticket for each week
        ticket = lottoTix[week];

        cout << "Please enter your 5-digit ticket number for week " << (week + 1) << ": " << endl;
        // Player's ticket number
        cin >> playerNum;

/*        // Calls linear search
        winningNum = ticketSearch(lottoTix, LUCKY_NUMS, playerNum);*/

        // Calls Binary Search
        winningNum = binarySearch (lottoTix, LUCKY_NUMS, playerNum);

        // Error message if player's number is not the winning ticket
        if ((winningNum == -1) || playerNum != ticket)
        {
            cout << "Sorry, you did not win the megamonies lottery. ";
            cout << "Thanks for playing! ";
            cout << "Play again? (Y/N)";
            cin >> again;
        }

            //Player wins the lottery
        else if (playerNum == ticket)
        {

            cout << "You have just won lots of monies!!! ";
            cout << "CONGRATULATIONS!!!";
            cout << "Play again? (Y/N)";
            cin >> again;
        }

        if ((again != 'Y') && (again != 'y'))
        {
            cout << "Press [Enter] to exit...\n\n";                 // exit message
            cin.ignore(1000,'\n');                                  // remove any chars from input buffer
            cin.get();                                              // wait for user to press enter
            exit(0);                                                // exits program
        }
    }
    return 0;
}

/*
//linear search
int ticketSearch(const int ticketList[], int numTickets, int winningNum)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while ((index < numTickets) && !found)
    {
        if (ticketList[index] == winningNum)
        {
            found = true;
            position = index;
        }
        index ++;
    }
    return position;
}*/

int binarySearch (const int ticketList[], int numTickets, int winningNum)
{
    int first = 0;                                      // First Array Element
    int last = numTickets - 1;                          // Last Array Element
    int middle;                                         // Midpoint of the search
    int position = -1;                                  // Position of the search value
    bool found = false;                                 // True or False flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (ticketList[middle] == winningNum)
        {
            found = true;
            position = middle;
        }
        else if (ticketList[middle] > winningNum)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}