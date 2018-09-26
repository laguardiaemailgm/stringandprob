#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;

int two_DiceRolls(void);

int main()
{
    const int arrSize = 11;
    int frequency[arrSize] = {0};
    float prob[arrSize] = {0.00000};//Set both arrays to zero
    int roll_Result; // Roll Result Buffer


    srand(time(0)); //Seed Random Number


    //Dice roll tally
    for(int i = 0 ; i < 3600 ; i++)
    {
        roll_Result = two_DiceRolls();
        frequency[roll_Result-2]++;//Frequency counter
    }

    //Probability Calculation
    for(int i = 0 ; i < arrSize ; i++)
    {
        prob[i] = frequency[i]/3600.0;
    }

    //Display Results
        cout<<"\nRoll            Frequency            Probability            Probability(%)";// Header
    for(int i = 0 ; i < arrSize ; i++)
    {
        cout<<"\n"<<fixed<<setw(4)<<i+2<<"               "<<fixed<<setw(4)<<frequency[i]<<"               "
            <<fixed<<setw(4)<<prob[i]<<"               "<<fixed<<setw(4)<<prob[i]*100;
    }

}

int two_DiceRolls()
{

    return (rand()%6+1)+(rand()%6+1);
}
