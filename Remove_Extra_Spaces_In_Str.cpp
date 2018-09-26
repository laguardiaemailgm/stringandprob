#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
void eraseExtraSpaces(string&); //Pass by reference

int main()
{
    string letter_Upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string letter_Lower = "abcdefghijklmnopqrstuvwxyz";
    string strInput,
           strBuffer;//String that will be used to edit and count spaces inside the strInput

    int letterFrequency[26] = {0};//Letter Frequency Counter
                            //A/a =[0]<--Stored in Index; B/b =[1]<--Stored in Index; and ....

    cout<<"'$' to terminate\n";
    cout<<"Input string: ";
    getline(cin,strInput, '$'); //Get Input from user
    eraseExtraSpaces(strInput);
    strBuffer = strInput; //Copy string to the buffer

    //count letter frequency
    for(int i = 0; i < letter_Lower.length(); i++)
    {
        char replace_withSpace = ' ';
        for(int j = 0 ; j < strBuffer.length(); j++)
        {
            if((letter_Lower[i] == strBuffer[j]) ||  (letter_Upper[i] == strBuffer[j]) )
            {
                letterFrequency[i]++;
                strBuffer[j] = replace_withSpace;
            }
        }
    }
    //Display Results
    cout<<"The String: \""<<strInput<<"\" "<<" uses the letters";
    for(int i = 0; i < letter_Lower.length(); i++)
    {
        cout<<"\n"<<letter_Lower[i]<<": "<<letterFrequency[i]<<" times";
    }
}

void eraseExtraSpaces(string& strInput)
{
    string str2 = "";//Buffer to hold the modified String
    bool appendToString = 1;// 1 = write; 0 = do not write
    for(int i = 0 ; i < strInput.length() ; i++)
    {

        if((strInput[i] != ' ') && (appendToString == 1))
        {
            str2 += strInput[i];
            if(strInput[i+1] == ' ')
            {
                str2 += strInput[i+1];
                appendToString = 0; // set to false

                while(strInput[i+1] == ' ')
                {
                    i++;
                    appendToString = 1;
                }
            }
        }
    }
    strInput=str2;//replace original String with the new String
}
