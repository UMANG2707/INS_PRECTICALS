#include<iostream>
using namespace std;

string encrypt(string x,int n)
{
    string cipher="";

    for(int i=0;i<x.length();i++)
    {
        if(isupper(x[i]))
            cipher += (x[i] + n - 65)%26 + 65;
        else if(islower(x[i]))
            cipher += (x[i] + n - 97)%26 + 97;
        else
            cipher += x[i];
    }
    return cipher;
}

void decrypt(string x)
{
    string text;
    for(int n=0;n<26;n++)
    {
        text = "";
        for(int i=0;i<x.length();i++)
        {
            if(isupper(x[i]))
            {
                if((x[i] - n - 65)<0)
                    text += 91 + (x[i] - n - 65);
                else
                    text += (x[i] - n - 65)%26 + 65;
            }
            else if(islower(x[i]))
            {
                if((x[i] - n - 97) < 0)
                    text += 123 + (x[i] - n - 97);
                else
                    text += (x[i] - n - 97)%26 + 97;
            }
            else
                text += x[i];
        }
        cout << "plain text for key " << n << " :- " << text << endl;
    }
}

int main()
{
    int key;
    string text;
    cout << "enter text:- ";
    getline(cin,text);
    cout << "enter key:- ";
    cin >> key;

    string cipher = encrypt(text,key);
    cout << "cipher text :- " << cipher << endl << endl;

    decrypt(cipher);
}
