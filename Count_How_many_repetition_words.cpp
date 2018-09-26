#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
using namespace std;

int removeWord(string& strInput, string wordToBeRemoved);//Remove the word Word
void strToLowerCase(string& strInput); //All Characters To Lower Case
string uniqueWordFinder(string& strInput);
void eraseExtraSpaces(string& strInput);
void eraseNewLines(string& strInput);

int main()
{
    string uniqueWordBuffer = ""; //Temp Storage for UniqueWord
    int numberOfWords = 0; //Number of Words Counter
    string strInput = "";

    cout<<"'$' to terminate\n";
    cout<<"Input string: ";
    getline(cin,strInput, '$');

    eraseExtraSpaces(strInput);
    eraseNewLines(strInput); // Remove \n
    strInput += " ";//Insert Extra So that the uniqueWordFinder can locate it

    strToLowerCase(strInput);//Set Input to lower case
    uniqueWordBuffer = uniqueWordFinder(strInput);
    while(uniqueWordBuffer != "$")//uniqueWordBuffer != "$"
    {

        eraseExtraSpaces(strInput);
        eraseExtraSpaces(uniqueWordBuffer);
        numberOfWords = removeWord(strInput,uniqueWordBuffer);//Removes iteration of the uniqueWord
        cout<<"\nThe word: "<<"'"<<uniqueWordBuffer << "' is repeated "<<numberOfWords << " in your input string";
        uniqueWordBuffer = "";//Reset Buffer
        uniqueWordBuffer = uniqueWordFinder(strInput);//Find uniqueWord
    }
    return 0;

}

int removeWord(string& strInput, string wordRemove)
{
    int numberOfWords = 0;
    int rightIndexPos = 0;
    int leftIndexPos = 0;

    strInput += " ";//Add Extra Space so that it would count the last word
    while(rightIndexPos != std::string::npos)
    {
        rightIndexPos = strInput.find(wordRemove);//Look the First Word
        leftIndexPos = wordRemove.length();
        if((rightIndexPos != std::string::npos) && (leftIndexPos >= 0) )//If Word Is Found
        {
            strInput.erase(rightIndexPos,leftIndexPos);
            numberOfWords++;
            eraseExtraSpaces(strInput);//Remove Extra Spaces
        }
        else
            break;//The word doesn't exist inside the string
    }
    return numberOfWords;

}

string uniqueWordFinder(string& strInput)
{
    string uniqueWord = "";
    eraseExtraSpaces(strInput); //Remove Extra Spaces

    int rightIndexPos = strInput.find(' ');//Find the First Word
    if(rightIndexPos != std::string::npos)//if String is not found
        uniqueWord = strInput.substr(0,rightIndexPos);//Copy First Word To Temp

    if(strInput == "")//If String Empty Insert Terminating Character
        uniqueWord = "$";//Terminating Character

    eraseExtraSpaces(uniqueWord);//Remove Extra Spaces

    return uniqueWord;//Append terminating character
}

void strToLowerCase(string& strInput) //All Characters To Lower Case
{
    for(int i = 0; i < strInput.length(); i++)
    {
        strInput.at(i) = tolower(strInput.at(i));
    }
}
void eraseNewLines(string& strInput)
{
    for(int i =0 ; i < strInput.length(); i++)
    {
        if(strInput.at(i) == '\n')
        {
            strInput[i] = ' ';
        }
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

