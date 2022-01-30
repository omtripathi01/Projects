// Constraints: We can only generate ascii art for letters and numbers not for special symbols 
// How it works: So i just divided the charaters in six layers and implemented each layer separetely
// to exit the window just use: Ctrl+C

#include <bits/stdc++.h>
#include<conio.h>

using namespace std;

void ascii_art()
{
    string str;
    cout<<"Enter text: "; getline(cin,str);
    //loop will print first layer
    for (int i=0; i < str.size(); i++)
    {
        if (str[i] == 'A' || str[i]== 'a')
            cout<<"  ___   ";
        if (str[i] == 'B' || str[i] == 'b')
            cout<<" _____  ";
        if (str[i] == 'C' || str[i] == 'c')
            cout<<" _____  ";
        if (str[i] == 'D' || str[i] == 'd')
            cout<<" _____  ";
        if (str[i] == 'E' || str[i] == 'e')
            cout<<" _____  ";
        if (str[i] == 'F' || str[i] == 'f')
            cout<<" _____  ";
        if (str[i] == 'G' || str[i] == 'g')
            cout<<" _____  ";
        if (str[i] == 'H' || str[i] == 'h')
            cout<<" _   _  ";
        if (str[i] == 'I' || str[i] == 'i')
            cout<<" _____  ";
        if (str[i] == 'J' || str[i] == 'j')
            cout<<"   ___  ";
        if (str[i] == 'K' || str[i] == 'k')
            cout<<" _   __ ";
        if (str[i] == 'L' || str[i] == 'l')
            cout<<" _      ";
        if (str[i] == 'M' || str[i] == 'm')
            cout<<" __  __  ";
        if (str[i] == 'N' || str[i] == 'n')
            cout<<" _   _  ";
        if (str[i] == 'O' || str[i] == 'o')
            cout<<" _____  ";
        if (str[i] == 'P' || str[i] == 'p')
            cout<<" _____  ";
        if (str[i] == 'Q' || str[i] == 'q')
            cout<<" _____  ";
        if (str[i] == 'R' || str[i] == 'r')
            cout<<" _____  ";
        if (str[i] == 'S' || str[i] == 's')
            cout<<" _____  ";
        if (str[i] == 'T' || str[i] == 't')
            cout<<" _____  ";
        if (str[i] == 'U' || str[i] == 'u')
            cout<<" _   _  ";
        if (str[i] == 'V' || str[i] == 'v')
            cout<<" _   _  ";
        if (str[i] == 'W' || str[i] == 'w')
            cout<<" _    _  ";
        if (str[i] == 'X' || str[i] == 'x')
            cout<<"__   __ ";
        if (str[i] == 'Y' || str[i] == 'y')
            cout<<"__   __ ";
        if (str[i] == 'Z' || str[i]== 'z')
            cout<<" ______ ";
        if (str[i] == ' ')
            cout<<"  ";
        if (str[i] == '`')
            cout<<" _  ";
        if (str[i] == '~')
            cout<<"      ";
        if (str[i] == '1')
            cout<<" __   ";
        if (str[i]== '2')
            cout<<" _____  ";
        if (str[i]== '3')
            cout<<" _____  ";
        if (str[i] == '4')
            cout<<"   ___  ";
        if (str[i] == '5')
            cout<<" _____  ";
        if (str[i] == '6')
            cout<<"  ____  ";
        if (str[i] == '7')
            cout<<" ______ ";
        if(str[i] == '.')
            cout<<"    ";
        if (str[i] == '8')
            cout<<" _____  ";
        if (str[i] == '9')
            cout<<" _____  ";
        if (str[i] == '0')
            cout<<" _____  ";
    }
    cout<<endl;
    //loop will print second layer
    for (int i=0; i < str.size(); i++)
    {
        if (str[i] == 'A' || str[i]== 'a')
            cout<<" / _ \\  ";
        if (str[i] == 'B' || str[i] == 'b')
            cout<<"| ___ \\ ";
        if (str[i] == 'C' || str[i] == 'c')
            cout<<"/  __ \\ ";
        if (str[i] == 'D' || str[i] == 'd')
            cout<<"|  _  \\ ";
        if (str[i] == 'E' || str[i] == 'e')
            cout<<"|  ___| ";
        if (str[i] == 'F' || str[i] == 'f')
            cout<<"|  ___| ";
        if (str[i] == 'G' || str[i] == 'g')
            cout<<"|  __ \\ ";
        if (str[i] == 'H' || str[i] == 'h')
            cout<<"| | | | ";
        if (str[i] == 'I' || str[i] == 'i')
            cout<<"|_   _| ";
        if (str[i] == 'J' || str[i] == 'j')
            cout<<"  |_  | ";
        if (str[i] == 'K' || str[i] == 'k')
            cout<<"| | / / ";
        if (str[i] == 'L' || str[i] == 'l')
            cout<<"| |     ";
        if (str[i] == 'M' || str[i] == 'm')
            cout<<"|  \\/  | ";
        if (str[i] == 'N' || str[i] == 'n')
            cout<<"| \\ | | ";
        if (str[i] == 'O' || str[i] == 'o')
            cout<<"|  _  | ";
        if (str[i] == 'P' || str[i] == 'p')
            cout<<"| ___ \\ ";
        if (str[i] == 'Q' || str[i] == 'q')
            cout<<"|  _  | ";
        if (str[i] == 'R' || str[i] == 'r')
            cout<<"| ___ \\ ";
        if (str[i] == 'S' || str[i] == 's')
            cout<<"/  ___| ";
        if (str[i] == 'T' || str[i] == 't')
            cout<<"|_   _| ";
        if (str[i] == 'U' || str[i] == 'u')
            cout<<"| | | | ";
        if (str[i] == 'V' || str[i] == 'v')
            cout<<"| | | | ";
        if (str[i] == 'W' || str[i] == 'w')
            cout<<"| |  | | ";
        if (str[i] == 'X' || str[i] == 'x')
            cout<<"\\ \\ / / ";
        if (str[i] == 'Y' || str[i] == 'y')
            cout<<"\\ \\ / / ";
        if (str[i] == 'Z' || str[i]== 'z')
            cout<<"|___  / ";
        if (str[i] == ' ')
            cout<<"  ";
        if (str[i] == '`')
            cout<<"( ) ";
        if (str[i] == '~')
            cout<<"      ";
        if (str[i] == '1')
            cout<<"/  |  ";
        if (str[i]== '2')
            cout<<"/ __  \\ ";
        if (str[i]== '3')
            cout<<"|____ | ";
        if (str[i] == '4')
            cout<<"  /   | ";
        if (str[i] == '5')
            cout<<"|  ___| ";
        if (str[i] == '6')
            cout<<" / ___| ";
        if (str[i] == '7')
            cout<<"|___  / ";
        if(str[i] == '.')
            cout<<"    ";
        if (str[i] == '8')
            cout<<"|  _  | ";
        if (str[i] == '9')
            cout<<"|  _  | ";
        if (str[i] == '0')
            cout<<"|  _  | ";
    }
    cout<<endl;
    //loop will print third layer
    for (int i=0; i < str.size(); i++)
    {
        if (str[i] == 'A' || str[i]== 'a')
            cout<<"/ /_\\ \\ ";
        if (str[i] == 'B' || str[i] == 'b')
            cout<<"| |_/ / ";
        if (str[i] == 'C' || str[i] == 'c')
            cout<<"| /  \\/ ";
        if (str[i] == 'D' || str[i] == 'd')
            cout<<"| | | | ";
        if (str[i] == 'E' || str[i] == 'e')
            cout<<"| |__   ";
        if (str[i] == 'F' || str[i] == 'f')
            cout<<"| |_    ";
        if (str[i] == 'G' || str[i] == 'g')
            cout<<"| |  \\/ ";
        if (str[i] == 'H' || str[i] == 'h')
            cout<<"| |_| | ";
        if (str[i] == 'I' || str[i] == 'i')
            cout<<"  | |   ";
        if (str[i] == 'J' || str[i] == 'j')
            cout<<"    | | ";
        if (str[i] == 'K' || str[i] == 'k')
            cout<<"| |/ /  ";
        if (str[i] == 'L' || str[i] == 'l')
            cout<<"| |     ";
        if (str[i] == 'M' || str[i] == 'm')
            cout<<"| .  . | ";
        if (str[i] == 'N' || str[i] == 'n')
            cout<<"|  \\| | ";
        if (str[i] == 'O' || str[i] == 'o')
            cout<<"| | | | ";
        if (str[i] == 'P' || str[i] == 'p')
            cout<<"| |_/ / ";
        if (str[i] == 'Q' || str[i] == 'q')
            cout<<"| | | | ";
        if (str[i] == 'R' || str[i] == 'r')
            cout<<"| |_/ / ";
        if (str[i] == 'S' || str[i] == 's')
            cout<<"\\ `--.  ";
        if (str[i] == 'T' || str[i] == 't')
            cout<<"  | |   ";
        if (str[i] == 'U' || str[i] == 'u')
            cout<<"| | | | ";
        if (str[i] == 'V' || str[i] == 'v')
            cout<<"| | | | ";
        if (str[i] == 'W' || str[i] == 'w')
            cout<<"| |  | | ";
        if (str[i] == 'X' || str[i] == 'x')
            cout<<" \\ V /  ";
        if (str[i] == 'Y' || str[i] == 'y')
            cout<<" \\ V /  ";
        if (str[i] == 'Z' || str[i]== 'z')
            cout<<"   / /  ";
        if (str[i] == ' ')
            cout<<"  ";
        if (str[i] == '`')
            cout<<" \\| ";
        if (str[i] == '~')
            cout<<" /\\/| ";
        if (str[i] == '1')
            cout<<"`| |  ";
        if (str[i]== '2')
            cout<<"`' / /' ";
        if (str[i]== '3')
            cout<<"    / / ";
        if (str[i] == '4')
            cout<<" / /| | ";
        if (str[i] == '5')
            cout<<"|___ \\  ";
        if (str[i] == '6')
            cout<<"/ /___  ";
        if (str[i] == '7')
            cout<<"   / /  ";
        if(str[i] == '.')
            cout<<"    ";
        if (str[i] == '8')
            cout<<" \\ V /  ";
        if (str[i] == '9')
            cout<<"| |_| | ";
        if (str[i] == '0')
            cout<<"| |/' | ";
    }
    cout<<endl;
    //loop will print fourth layer
    for (int i=0; i < str.size(); i++)
    {
        if (str[i] == 'A' || str[i]== 'a')
            cout<<"|  _  | ";
        if (str[i] == 'B' || str[i] == 'b')
            cout<<"| ___ \\ ";
        if (str[i] == 'C' || str[i] == 'c')
            cout<<"| |     ";
        if (str[i] == 'D' || str[i] == 'd')
            cout<<"| | | | ";
        if (str[i] == 'E' || str[i] == 'e')
            cout<<"|  __|  ";
        if (str[i] == 'F' || str[i] == 'f')
            cout<<"|  _|   ";
        if (str[i] == 'G' || str[i] == 'g')
            cout<<"| | __  ";
        if (str[i] == 'H' || str[i] == 'h')
            cout<<"|  _  | ";
        if (str[i] == 'I' || str[i] == 'i')
            cout<<"  | |   ";
        if (str[i] == 'J' || str[i] == 'j')
            cout<<"    | | ";
        if (str[i] == 'K' || str[i] == 'k')
            cout<<"|    \\  ";
        if (str[i] == 'L' || str[i] == 'l')
            cout<<"| |     ";
        if (str[i] == 'M' || str[i] == 'm')
            cout<<"| |\\/| | ";
        if (str[i] == 'N' || str[i] == 'n')
            cout<<"| . ` | ";
        if (str[i] == 'O' || str[i] == 'o')
            cout<<"| | | | ";
        if (str[i] == 'P' || str[i] == 'p')
            cout<<"|  __/  ";
        if (str[i] == 'Q' || str[i] == 'q')
            cout<<"| | | | ";
        if (str[i] == 'R' || str[i] == 'r')
            cout<<"|    /  ";
        if (str[i] == 'S' || str[i] == 's')
            cout<<" `--. \\ ";
        if (str[i] == 'T' || str[i] == 't')
            cout<<"  | |   ";
        if (str[i] == 'U' || str[i] == 'u')
            cout<<"| | | | ";
        if (str[i] == 'V' || str[i] == 'v')
            cout<<"| | | | ";
        if (str[i] == 'W' || str[i] == 'w')
            cout<<"| |/\\| | ";
        if (str[i] == 'X' || str[i] == 'x')
            cout<<" / ^ \\  ";
        if (str[i] == 'Y' || str[i] == 'y')
            cout<<"  \\ /   ";
        if (str[i] == 'Z' || str[i]== 'z')
            cout<<"  / /   ";
        if (str[i] == ' ')
            cout<<"  ";
        if (str[i] == '`')
            cout<<"    ";
        if (str[i] == '~')
            cout<<"|/\\/  ";
        if (str[i] == '1')
            cout<<" | |  ";
        if (str[i]== '2')
            cout<<"  / /   ";
        if (str[i]== '3')
            cout<<"    \\ \\ ";
        if (str[i] == '4')
            cout<<"/ /_| | ";
        if (str[i] == '5')
            cout<<"    \\ \\ ";
        if (str[i] == '6')
            cout<<"| ___ \\ ";
        if (str[i] == '7')
            cout<<"  / /   ";
        if(str[i] == '.')
            cout<<"    ";
        if (str[i] == '8')
            cout<<" / _ \\  ";
        if (str[i] == '9')
            cout<<"\\____ | ";
        if (str[i] == '0')
            cout<<"|  /| | ";
    }
    cout<<endl;
    //loop will print fifth layer
    for (int i=0; i < str.size(); i++)
    {
        if (str[i] == 'A' || str[i]== 'a')
            cout<<"| | | | ";
        if (str[i] == 'B' || str[i] == 'b')
            cout<<"| |_/ / ";
        if (str[i] == 'C' || str[i] == 'c')
            cout<<"| \\__/\\ ";
        if (str[i] == 'D' || str[i] == 'd')
            cout<<"| |/ /  ";
        if (str[i] == 'E' || str[i] == 'e')
            cout<<"| |___  ";
        if (str[i] == 'F' || str[i] == 'f')
            cout<<"| |     ";
        if (str[i] == 'G' || str[i] == 'g')
            cout<<"| |_\\ \\ ";
        if (str[i] == 'H' || str[i] == 'h')
            cout<<"| | | | ";
        if (str[i] == 'I' || str[i] == 'i')
            cout<<" _| |_  ";
        if (str[i] == 'J' || str[i] == 'j')
            cout<<"/\\__/ / ";
        if (str[i] == 'K' || str[i] == 'k')
            cout<<"| |\\  \\ ";
        if (str[i] == 'L' || str[i] == 'l')
            cout<<"| |____ ";
        if (str[i] == 'M' || str[i] == 'm')
            cout<<"| |  | | ";
        if (str[i] == 'N' || str[i] == 'n')
            cout<<"| |\\  | ";
        if (str[i] == 'O' || str[i] == 'o')
            cout<<"\\ \\_/ / ";
        if (str[i] == 'P' || str[i] == 'p')
            cout<<"| |     ";
        if (str[i] == 'Q' || str[i] == 'q')
            cout<<"\\ \\/' / ";
        if (str[i] == 'R' || str[i] == 'r')
            cout<<"| |\\ \\  ";
        if (str[i] == 'S' || str[i] == 's')
            cout<<"/\\__/ / ";
        if (str[i] == 'T' || str[i] == 't')
            cout<<"  | |   ";
        if (str[i] == 'U' || str[i] == 'u')
            cout<<"| |_| | ";
        if (str[i] == 'V' || str[i] == 'v')
            cout<<"\\ \\_/ / ";
        if (str[i] == 'W' || str[i] == 'w')
            cout<<"\\  /\\  / ";
        if (str[i] == 'X' || str[i] == 'x')
            cout<<"/ / \\ \\ ";
        if (str[i] == 'Y' || str[i] == 'y')
            cout<<"  | |   ";
        if (str[i] == 'Z' || str[i]== 'z')
            cout<<"./ /___ ";
        if (str[i] == ' ')
            cout<<"  ";
        if (str[i] == '`')
            cout<<"    ";
        if (str[i] == '~')
            cout<<"      ";
        if (str[i] == '1')
            cout<<"_| |_ ";
        if (str[i]== '2')
            cout<<"./ /___ ";
        if (str[i]== '3')
            cout<<".___/ / ";
        if (str[i] == '4')
            cout<<"\\___  | ";
        if (str[i] == '5')
            cout<<"/\\__/ / ";
        if (str[i] == '6')
            cout<<"| \\_/ | ";
        if (str[i] == '7')
            cout<<"./ /    ";
        if(str[i] == '.')
            cout<<" _  ";
        if (str[i] == '8')
            cout<<"| |_| | ";
        if (str[i] == '9')
            cout<<".___/ / ";
        if (str[i] == '0')
            cout<<"\\ |_/ / ";
    }
    cout<<endl;
    // loop for 6th layer
    for (int i=0; i < str.size(); i++)
    {
        if (str[i] == 'A' || str[i]== 'a')
            cout<<"\\_| |_/ ";
        if (str[i] == 'B' || str[i] == 'b')
            cout<<"\\____/  ";
        if (str[i] == 'C' || str[i] == 'c')
            cout<<" \\____/ ";
        if (str[i] == 'D' || str[i] == 'd')
            cout<<"|___/   ";
        if (str[i] == 'E' || str[i] == 'e')
            cout<<"\\____/  ";
        if (str[i] == 'F' || str[i] == 'f')
            cout<<"\\_|     ";
        if (str[i] == 'G' || str[i] == 'g')
            cout<<" \\____/ ";
        if (str[i] == 'H' || str[i] == 'h')
            cout<<"\\_| |_/ ";
        if (str[i] == 'I' || str[i] == 'i')
            cout<<" \\___/  ";
        if (str[i] == 'J' || str[i] == 'j')
            cout<<"\\____/  ";
        if (str[i] == 'K' || str[i] == 'k')
            cout<<"\\_| \\_/ ";
        if (str[i] == 'L' || str[i] == 'l')
            cout<<"\\_____/ ";
        if (str[i] == 'M' || str[i] == 'm')
            cout<<"\\_|  |_/ ";
        if (str[i] == 'N' || str[i] == 'n')
            cout<<"\\_| \\_/ ";
        if (str[i] == 'O' || str[i] == 'o')
            cout<<" \\___/  ";
        if (str[i] == 'P' || str[i] == 'p')
            cout<<"\\_|     ";
        if (str[i] == 'Q' || str[i] == 'q')
            cout<<" \\_/\\_\\ ";
        if (str[i] == 'R' || str[i] == 'r')
            cout<<"\\_| \\_| ";
        if (str[i] == 'S' || str[i] == 's')
            cout<<"\\____/  ";
        if (str[i] == 'T' || str[i] == 't')
            cout<<"  \\_/   ";
        if (str[i] == 'U' || str[i] == 'u')
            cout<<" \\___/  ";
        if (str[i] == 'V' || str[i] == 'v')
            cout<<" \\___/  ";
        if (str[i] == 'W' || str[i] == 'w')
            cout<<" \\/  \\/  ";
        if (str[i] == 'X' || str[i] == 'x')
            cout<<"\\/   \\/ ";
        if (str[i] == 'Y'  || str[i] == 'y')
            cout<<"  \\_/   ";
        if (str[i] == 'Z' || str[i]== 'z')
            cout<<"\\_____/ ";
        if (str[i] == ' ')
            cout<<"  ";
        if (str[i] == '`')
            cout<<"    ";
        if (str[i] == '~')
            cout<<"      ";
        if (str[i] == '1')
            cout<<"\\___/ ";
        if (str[i]== '2')
            cout<<"\\_____/ ";
        if (str[i]== '3')
            cout<<"\\____/  ";
        if (str[i] == '4')
            cout<<"    |_/ ";
        if (str[i] == '5')
            cout<<"\\____/  ";
        if (str[i] == '6')
            cout<<"\\_____/ ";
        if (str[i] == '7')
            cout<<"\\_/     ";
        if(str[i] == '.')
            cout<<"(_) ";
        if (str[i] == '8')
            cout<<"\\_____/ ";
        if (str[i] == '9')
            cout<<"\\____/  ";
        if (str[i] == '0')
            cout<<" \\___/  ";
    }
    cout<<endl;
}

int main()
{
    while(1)
    {
        ascii_art();
        _getch();
        cout<<endl;
    }
    return 0;
}
