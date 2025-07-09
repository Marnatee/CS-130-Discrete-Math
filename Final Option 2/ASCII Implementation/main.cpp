
/* 
 * File:   main.cpp
 * Author: Michael Donnelly
 * CS-130
 * Professor Samuel Addington 
 * Created on July 7, 2025, 12:45 AM
 * 
 * Final Option#2 ASCII version
 * 441 lines of code
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string asciiAlphabet[34][5] = {
       //0 = A
    {
        "X  XX",
        "XXX  ",
        "     ",
        "XXX  ",
        "X  XX"
    }, //1 = B
    {
        " XXX ",
        "X   X",
        " XXX ",
        "X   X",
        " XXX "
    }, //2 = C
    {
        "X    ",
        "X X X",
        "X X X",
        "X X X",
        "    X"
    }, //3 = Ch
    {
        "XXX  ",
        "  XX ",
        "   X ",
        "   X ",
        "XXXXX"
    }, //4 = D
    {
        "XXXXX",
        "   X ",
        "XXX  ",
        " X   ",
        "X    "
    }, //5 = E
    {
        "X XXX",
        "X XX ",
        "XXXX ",
        " X X ",
        " X X "
    }, //6 = Ae
    {
        "XXXXX",
        "X   X",
        "  XXX",
        "X   X",
        "XXXXX"
    }, //7 = Eo
    {
        " XXX ",
        " X X ",
        "X   X",
        "     ",
        "XXXXX"
    }, //8 = F
    {
        "  X  ",
        "  XXX",
        "XXX  ",
        "X X  ",
        "XXXXX"
    }, //9 = G
    {
        "X XXX",
        "X   X",
        "X  X ",
        "X X  ",
        "XXX  "
    }, //10 = H
    {
        "XXXXX",
        "     ",
        " XXX ",
        "     ",
        "XXXXX"
    }, //11 = I
    {
        "  X  ",
        " XX  ",
        "  X  ",
        "  X  ",
        "  X  "
    }, //12 =J
    {
        "    X",
        "  XXX",
        "XX X ",
        "  XX ",
        "XXX  "
    }, //13 = K
    {
        "XXXXX",
        "    X",
        "    X",
        "    X",
        "XXXXX"
    }, //14 = Kh
    {
        "    X",
        "    X",
        " XXXX",
        " X  X",
        "X   X"
    }, //15 = L
    {
        "   X ",
        "   X ",
        "X  X ",
        " X X ",
        "  XX "
    }, //16 = M
    {
        "   XX",
        "  X  ",
        " X   ",
        " X   ",
        "XXXXX"
    }, //17 = N
    {
        " X X ",
        "X  X ",
        "X X X",
        "X X X",
        " X  X"
    }, //18 = Ng
    {
        "XXXXX",
        " X  X",
        " X  X",
        "X   X",
        "X   X"
    }, //19 = O
    {
        "  X  ",
        " X X ",
        " X X ",
        "X   X",
        " XXX "
    }, //20 = Oo
    {
        "XX XX",
        "X   X",
        "X   X",
        "X   X",
        "XX XX"
    }, //21 = P
    {
        " XX X",
        "X   X",
        "X   X",
        " X  X",
        "  XXX"
    }, //22 = Q
    {
        "XXXXX",
        "X   X",
        "X    ",
        "X    ",
        "XX   "
    }, //23 = R
    {
        "XXXXX",
        "   X ",
        "  X  ",
        " X   ",
        "X    "
    }, //24 = S
    {
        "X   X",
        " X  X",
        "  X X",
        "X  XX",
        " X  X"
    }, //25 = Sh
    {
        "X XXX",
        "    X",
        "   XX",
        "   X ",
        "X XX "
    }, //26 = T
    {
        "  X  ",
        "  X  ",
        "X X X",
        "X X X",
        " XXX "
    }, //27 = Th
    {
        "XXXXX",
        "X   X",
        "XXX X",
        "X   X",
        "XXXXX"
    }, //28 = U
    {
        "X  XX",
        "X X X",
        "X   X",
        "X   X",
        "XXXXX"
    }, //29 = V
    {
        "X   X",
        " X X ",
        "  X  ",
        "  X  ",
        "  X  "
    }, //30 = W
    {
        "     ",
        "XXXXX",
        "X   X",
        "X   X",
        "XXXXX"
    }, //31 = X
    {
        "  X  ",
        "  X  ",
        " X X ",
        " X X ",
        "XXXXX"
    }, //32 = Y
    {
        "XX  X",
        "X   X",
        " X X ",
        " X X ",
        "  X  "
    }, //33 = Z
    {
        "    X",
        "  XXX",
        " X  X",
        "    X",
        "XXXXX"
    }
    
};

void printAsciiFromVector(const vector<int>& translatedMsg) {
    const int glyphsPerLine = 20; //'20' will output 119 chars per row
    //(5*20 + 20-1) = (6*20-1) = 119 chars
    int total = translatedMsg.size();

    for (int i = 0; i < total; i += glyphsPerLine) {
        //This defines how many glyphs on each row.
        //min(a, b) returns the smallest of the two values).
        //glyphsPerLine = 20 and total is initially 764.
        //So you keep printing 20 until 764-1 becomes less than 20
        int blockSize = min(glyphsPerLine, total - i);

        //5 rows per ascii character and we're going to print
        //an entire row at a time until the "block" of 5 rows is
        //printed.
        for (int row = 0; row < 5; ++row) {
            //blockSize is 20 until there's less than 20 to print
            for (int j = 0; j < blockSize; ++j) {
                //If the letter is 0-33 then print the associated ASCII
                //image for that value, otherwise display a blank
                //to alert the user.
                int letterIndex = translatedMsg[i + j];
                if (letterIndex >= 0 && letterIndex < 34) {
                    cout << asciiAlphabet[letterIndex][row] << " ";
                } else {
                    cout << "     "; // placeholder for unknown
                }
            }
            cout << endl;
        }
        cout << endl; // Space between blocks
    }
}

//Assigns ints 0-33 for single letters a-z.
//Double-letters are commented in as placeholders.
int letterSingle(char ch){
    ch = tolower(ch);
    
    switch (ch){
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        //case Ch return 3
        case 'd': return 4;
        case 'e': return 5;
        //case Ae return 6
        //case Eo return 7
        case 'f': return 8;
        case 'g': return 9;
        case 'h': return 10;
        case 'i': return 11;
        case 'j': return 12;
        case 'k': return 13;
        //case Kh return 14
        case 'l': return 15;
        case 'm': return 16;
        case 'n': return 17;
        //case Ng return 18
        case 'o': return 19;
        //case Oo return 20
        case 'p': return 21;
        case 'q': return 22;
        case 'r': return 23;
        case 's': return 24;
        //case Sh return 25
        case 't': return 26;
        //case Th return 27
        case 'u': return 28;
        case 'v': return 29;
        case 'w': return 30;
        case 'x': return 31;
        case 'y': return 32;
        case 'z': return 33;
        default: return -1; //error-checking: There shouldn't be any -1's stored
    }
}

//Decodes the encoded message back to the original to prove that the original
//encoding was done properly.
string decodeTest(int decode){
    decode = (decode - 6 + 34) % 34;
    switch (decode) {
        case 0: return "a";
        case 1: return "b";
        case 2: return "c";
        case 3: return "ch";
        case 4: return "d";
        case 5: return "e";
        case 6: return "ae";
        case 7: return "eo";
        case 8: return "f";
        case 9: return "g";
        case 10: return "h";
        case 11: return "i";
        case 12: return "j";
        case 13: return "k";
        case 14: return "kh";
        case 15: return "l";
        case 16: return "m";
        case 17: return "n";
        case 18: return "ng";
        case 19: return "o";
        case 20: return "oo";
        case 21: return "p";
        case 22: return "q";
        case 23: return "r";
        case 24: return "s";
        case 25: return "sh";
        case 26: return "t";
        case 27: return "th";
        case 28: return "u";
        case 29: return "v";
        case 30: return "w";
        case 31: return "x";
        case 32: return "y";
        case 33: return "z";
        default: return "?";
    }
}


int main(int argc, char** argv) {
    string Message[9];
    Message[0] = "To: High Command";
    Message[1] = "Subject: Battle status at San Bernardino Valley";
    Message[2] = "I regret to inform you that the battle at San Bernardino Valley"
            " is not going well. The resistance forces at the San Bernardino Valley"
            " College have been using advanced tactics that our troops have not been trained to";
    Message[3] = "counteract. We are facing a major disadvantage due to a lack of"
            " understanding of discrete structures and their use in warfare.";
    Message[4] = "Without additional reinforcements, I fear that our entire battalion "
            "will be defeated. We urgently require more troops who are trained in"
            " discrete structures and are equipped to handle the advanced tactics being used";
    Message[5] = "by the resistance forces. With the right support, I am confident"
            " that we can turn the tide of this battle and emerge victorious.";
    Message[6] = "I urge High Command to take immediate action and send us the reinforcements"
            " that we desperately need. The fate of this battle and the success of our mission depend on it.";
    Message[7] = "Respectfully,";
    Message[8] = "Clone Battalion Commander.";

    //Counter variables for double-letters
    int countCH = 0, countAE = 0, countEO = 0, countKH = 0;
    int countNG = 0, countOO = 0, countSH = 0, countTH = 0;
    
    //Output original message
    for (int i = 0; i<=8; i++){
        cout << Message[i] << endl;
    }
    
    //Read through the message and encode it + store result in Vector
    vector<int> translatedMsg;
    for (int i = 0; i <= 8; ++i) {
        for (size_t j = 0; j < Message[i].length(); ++j) {
            char current = tolower(Message[i][j]);
            char next = (j+ 1 < Message[i].length()) ? tolower(Message[i][j+1]) : '\0';
            //I want to read the message 2 chars at a time (if there is space
            //in the message to do so) to account for double-letters.
            
            //ch = 3
            if (current == 'c' && next == 'h'){
                int encode = (3 + 6) % 34;
                translatedMsg.push_back(encode);
                countCH++;
                ++j;
                continue;
            }
            
            //ae = 6
            if (current == 'a' && next == 'e'){
                int encode = (6 + 6) % 34;
                translatedMsg.push_back(encode);                
                countAE++;
                ++j;
                continue;
            }       
            
            //eo = 7
            if (current == 'e' && next == 'o'){
                int encode = (7 + 6) % 34;
                translatedMsg.push_back(encode);                
                countEO++;
                ++j;
                continue;
            }
            
            //kh = 14
            if (current == 'k' && next == 'h'){
                int encode = (14 + 6) % 34;
                translatedMsg.push_back(encode);                
                countKH++;
                ++j;
                continue;
            }
            
            //ng = 18
            if (current == 'n' && next == 'g'){
                int encode = (18 + 6) % 34;
                translatedMsg.push_back(encode);               
                countNG++;
                ++j;
                continue;
            }
            
            //oo = 20
            if (current == 'o' && next == 'o'){
                int encode = (20 + 6) % 34;
                translatedMsg.push_back(encode);                
                countOO++;
                ++j;
                continue;
            }
            
            //sh = 25
            if (current == 's' && next == 'h'){
                int encode = (25 + 6) % 34;
                translatedMsg.push_back(encode);                
                countSH++;
                ++j;
                continue;
            }
            
            //th = 27
            if (current == 't' && next == 'h'){
                int encode = (27 + 6) % 34;
                translatedMsg.push_back(encode);                
                countTH++;
                ++j;
                continue;
            }
            
            //Assignment instructions say to disregard special characters
            //if (current == ':')translatedMsg.push_back(35);
            //if (current == ',')translatedMsg.push_back(36);
            //if (current == '.')translatedMsg.push_back(37);
            
            int val = letterSingle(current);
            if (val != -1) { // skip unmapped chars
                int encode = (val + 6) % 34;
                translatedMsg.push_back(encode);
            } else {
                //cout << "errorSwitch ";
            }
        }
        //Use this to preserve line breaks in the message
        //translatedMsg.push_back(38); //38 = line break
    }
    cout << endl;
    
    //counts how many chars in original message
    int charCount = 0;
    for (int i = 0; i <= 8; ++i){
        for (char ch : Message[i]){
            if (isalpha(ch)){
                ++charCount;
            }
        }
    }
    cout << "There are " << charCount << " letters in this message" << endl << endl;
    
    /* Checking to see if double-letter code is working correctly.
     * Manual check yields NG = 5, OO = 2, TH = 20
     * Output is 0 0 0 0 5 2 0 20 = 27 which matches my expectations.
     */
    int doubleCount = countAE + countCH + countEO + countKH + countNG + countOO + countSH + countTH;
    int aurebeshCount = charCount - doubleCount;
    cout << "Double letter counts:" << endl;
    cout << "Ae Ch Eo Kh Ng Oo Sh Th" << endl;
    cout << countAE << "  " << countCH << "  " << countEO << "  " << countKH << "  ";
    cout << countNG << "  " << countOO << "  " << countSH << "  " << countTH;
    cout << " = " << doubleCount << " double-letters" << endl << endl;
    
    cout << charCount << " - " << doubleCount << " = " << aurebeshCount;
    cout << " expected Aurebesh glyphs stored in the encoded vector" << endl;
    cout << "The vector has " << translatedMsg.size() << " glyphs stored" << endl;
    
    //Test case = check if expected and actual values are the same
    if (aurebeshCount == translatedMsg.size()){
        cout << "Congratulations! The expected vector size and actual vector sizes match!" << endl << endl;
    } else {
        cout << "FAILURE! The expected vector size and actual vector size don't match!" << endl << endl;
    }
    
    //Test case = output vector contents for manual verification
    cout << "Encoded message will have these " << translatedMsg.size();
    cout << " aurebesh glyphs:" << endl;
    cout << "example: '32' will call 32.png" << endl;
    for (int val : translatedMsg) {
        cout << val << " ";
    }
    cout << endl << endl;
  
    //Test case = decode message and display it to verify against original
    cout << "Decoding the encoded message to verify that the encoding was accurate:" << endl;
    for (int val : translatedMsg){
        string decode = decodeTest(val);
        cout << decode;            
    }
    cout << endl << endl;
    
    //Print the encoded message with 5x5 ASCII characters with 20 ASCII characters per line.
    //Terminal will print 119 chars per line and needs to be extended to that size.
    cout << "Encoded Aurebesh message of " << translatedMsg.size() << " total characters with 20 ASCII characters per line" << endl;
    cout << "(Please expand your terminal so it can display at least 119 characters on one line)" << endl;
    printAsciiFromVector(translatedMsg);
  
    return 0;
}