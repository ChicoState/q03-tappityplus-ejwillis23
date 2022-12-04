#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
    phrase = reference;
    uinput = "";
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
    uinput = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
    int d = 0;
    int p = phrase.size();
    int i = uinput.size();
    if (p > i)
        d = p-i;
    else
        d = i-p;

    return d;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
    int d = length_difference();
    double p = 0.0;
    if (uinput == phrase)
        p = 1.0;
    else if (d == 0) {
        for (int i=0; i<phrase.size(); i++) {
            if (phrase[i] != uinput[i])
                d++;
        }
        p = d / phrase.size();
    } else {
        if (uinput.size() == 0)
            p = 0.0;
        else if (phrase.size() > uinput.size()) {
            for (int i=0; i<uinput.size(); i++) {
                if (phrase[i] != uinput[i])
                    d++;
            }
            if (d >= phrase.size())
                p = 0.0;
            else
                p = d / phrase.size();
        } else {
            for (int i=0; i<phrase.size(); i++) {
                if (phrase[i] != uinput[i])
                    d++;
            }
            if (d >= phrase.size())
                p = 0.0;
            else
                p = d / uinput.size();
        }
    }
    p *= 100;
    
    return p;
}
