#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <vector>
#include <regex>

int main()
{
	int choix = { 0 }, choixcryptage = { 0 }, choixdecryptage = { 0 };
	string message;
	cout << "Hey I'm Your encoder" << endl;
	while (choix != 3) {
    cout << endl;
		cout << "1. crypter 2. decrypter 3. exit" << endl;
		cin >> choix;
		//--------------------------Crypter--------------------------------
		if (choix == 1) {
			cout << "type your message:" << endl;
			cin.ignore();
			getline(cin, message);
			cout << "cryptage 1.Weak 2.Strong" << endl;
			cin >> choixcryptage;
			if (choixcryptage == 1) {
				//--------------------------choix de cryptage faible--------------------------------
				int key = rand() % 93;
				for (int i = 0; i < message.size(); i++)
				{
					if (int(message[i]) + int(key)  > 126) {
						message[i] = int(message[i]) - int(94) + int(key);
					}
					else {
						message[i] = int(message[i]) + int(key);
					}
					cout << char(message[i]);
				}
				cout << endl;
				cout << "key: " << key << endl;
			}
			else if(choixcryptage == 2){
				//--------------------------choixcryptage fort--------------------------------
        vector<string> keyTab;
				for (int i = 0; i < message.size(); i++)
				{
          if(i != 0){
            keyTab.push_back(".");
          }
          int key = rand() % 93;
          keyTab.push_back(to_string(key));
					if (int(message[i]) + int(key)  > 126) {
						message[i] = int(message[i]) - int(94) + int(key);
					}
					else {
						message[i] = int(message[i]) + int(key);
					}
					cout << char(message[i]);
				}
				cout << endl;
				cout << "key: ";
        for(int i = 0; i < keyTab.size(); i++){
          cout << keyTab[i];
        }
			}
		}

		//--------------------------Decrypter--------------------------------
		else if (choix == 2) {
			cout << "decryptage 1.Weak 2.Strong" << endl;
			cin >> choixdecryptage;
			cout << "Message ? : " << endl;
			cin.ignore();
			getline(cin, message);
			if (choixdecryptage == 1){
				//--------------------------choixdecryptage faible--------------------------------
        int key;
        cout << "key ? : " << endl;
        cin >> key;
				for (int i = 0; i < message.length(); i++)
				{
					if (int(message[i]) - int(key) < 32) {
						message[i] = int(message[i]) + int(94) - int(key);
					}
					else {
					message[i] = int(message[i]) - int(key);
					}
					cout << char(message[i]);
				}
				cout << endl;
			}
			else if(choixdecryptage == 2){
				//--------------------------choixdecryptage fort--------------------------------
				cout << "en developement" << endl;
        string key;
        cout << "key ? : " << endl;
        cin >> key;
        vector<int> keyTab;

        regex words_regex("[^.]+");
        auto words_begin = 
            sregex_iterator(key.begin(), key.end(), words_regex);
        auto words_end = sregex_iterator();
    
        for (sregex_iterator i = words_begin; i != words_end; ++i) {
            smatch match = *i;                                                 
            string match_str = match.str(); 
            keyTab.push_back(stoi(match_str));
        }

        for (int i = 0; i < message.length(); i++)
				{

					if (int(message[i]) - int(keyTab[i]) < 32) {
						message[i] = int(message[i]) + int(94) - int(keyTab[i]);
					}
					else {
					message[i] = int(message[i]) - int(keyTab[i]);
					}
					cout << char(message[i]);
				}
				cout << endl;
			}
		}
		//--------------------------Leave--------------------------------
		else if (choix == 3) {
			cout << "Bye" << endl;
		}
		else {
			cout << "err" << endl;
		}
	}

	return 0;
}
