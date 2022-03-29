#include <iostream>
#include <string>

using namespace std;

int main() {
    //declare all variables
    string letters, message, key , lettersen , lettersdec;
    //all alpha letters
    letters = "abcdefghijklmnopqrstuvwxyz";
    //let user choose he want encryption or decryption
    int opperation;
    cout<<"please enter 1 for encryption and 2 for decryption: ";
    cin>>opperation;
    //get the key from the user
    cout<<"please enter the key: ";
    cin>>key;
    //take the message from the user
    cout<<"please enter you message: ";
    //I use getline not cin to take all the message
    getline(cin>>ws , message);
    //convert all message letters to small letters
    for (int j = 0; j < message.length() ; j++) {
        message[j]= tolower(message[j]);
    }
    //convert all key letters to small letters
    for (int j = 0; j < key.length() ; j++) {
        key[j]= tolower(key[j]);
    }
    //encryption
    if (opperation==1){
        //put the letters of the key at the beginning of the letters encryption 
        lettersen=key;
        //for loop on the all letters
        for (int i = 0; i < 27; i++) {

            char x ;
            x = letters[i];
            //check the if the letters in the letters encryption or not
            if (lettersen.find(x)!=string::npos){
                continue;

            } else{
                //if the letter doesn't exist in the letters encryption , put it in the letters encryption
                lettersen+=x;
            }


        }
        //encrypt the message by for loop on all the message
        for (int k = 0; k < message.length(); k++)
        {
            char y ;
            y = message[k];
            //we don't encrypt spaces then we check if the char of the message is space or not 
            if (y==' ')
                continue;
            else
            {
                //nested loop by another for loop on the letters and encrypt letters
                for (int m = 0; m < letters.length(); m++)
                {
                    if (y==letters[m])
                    {
                        message[k] = lettersen[m];
                    }
                    else
                        continue;

                }

            }

        }

        cout << message<<endl;
    }
    //decryption
    else if (opperation==2){
        //put the letters of the key at the beginning of the letters decryption
        lettersdec = key;
        //for loop on the all letters
        for (int i = 0; i < 27; i++) {

            char x ;
            x = letters[i];
            //check the if the letters in the letters decryption or not
            if (lettersdec.find(x)!=string::npos){
                continue;

            } else{
                //if the letter doesn't exist in the letters decryption , put it in the letters decryption
                lettersdec+=x;
            }
        }
        //decrypt the message by for loop on all the message
        for (int i = 0; i < message.length(); i++) {
            char y;
            y = message[i];
            //we don't decrypt spaces then we check if the char of the message is space or not
            if (y == ' ') {
                continue;

            }else
            {
                //nested loop by another for loop on the letters and decrypt letters
                for (int k = 0; k < letters.length(); k++)
                {
                    if (y==lettersdec[k])
                    {
                        message[i] = letters[k];
                    }

                }

            }


        }cout << message;

    }else{
        //if user don't choose 1 or 2 (encryption or decryption), let he choose a valid operation
        cout<<"please enter valid opperation!" << endl;
        main();
    }

}