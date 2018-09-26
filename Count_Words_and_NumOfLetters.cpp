#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

void eraseExtraSpaces(string&); //Pass by reference
void num_characterInWords(string,int[]);// Counts how many x letters are there inside a word

int main()
{
    string strInput,
           strBuffer;//String that will be edit to count the letters inside
    int frequency[12] = {0};//Keeps track on how character are there inside a word;
                            //It's capable of track words that have a length of 1-10
                            //The last Index => frequency[11] keeps track of words that has more than 10 character.
    cout<<"Enter String: ";
    getline(cin,strInput);
    eraseExtraSpaces(strInput);
    num_characterInWords(strInput,frequency);

    for(int i = 0 ; i < 12 ; i++)
    {
        cout<<"\nWords containing "<<fixed<<setw(4)<<i+1<<" letters: "<<"          "<<fixed<<setw(4)<<frequency[i];
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
void num_characterInWords(string strInput, int frequency[])
{
    int charIndex;
    strInput = strInput+" ";//Extra Space for the last '$' character
    for(int i = 0 ; i < strInput.length(); i++)
    {
        charIndex = strInput.find(' ');
        strInput[charIndex] = '$';//Insert '$' character at index
    }

    for(int i = 0 ; i < strInput.length() ; i++)
    {
        charIndex = strInput.find('$');

        switch(charIndex)// Test if the word's length is 1 - 10  letters
        {
            case 0: break;
            case 1: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}//charIndex+1: Delete from index 0 to '$' including the '$' character
            case 2: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 3: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 4: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 5: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 6: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 7: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 8: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 9: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            case 10: {
                frequency[charIndex-1]++; strInput.erase(0,charIndex+1);break;}
            default:
                {
                    frequency[11]++;//If word has more than ten letters
                    strInput.erase(0,charIndex+1);
                    break;
                }
        }
    }
}
