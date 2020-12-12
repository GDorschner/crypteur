#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <vector>
#include <regex>

using namespace std;

int main()
{
	int choice = { 0 }, choicecryptage = { 0 }, choicedecryptage = { 0 };
	string message;
	cout << "Hey I'm Your encoder" << endl;
	while (choice != 3) {
    cout << endl;
		cout << "1.Encrypt 2.Decrypter 3.Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Type your message:" << endl;
			cin.ignore();
			getline(cin, message);
			cout << "Encryption 1.Weak 2.Strong" << endl;
			cin >> choicecryptage;
			if (choicecryptage == 1) {
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
			else if(choicecryptage == 2){
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
		else if (choice == 2) {
			cout << "Decryptage 1.Weak 2.Strong" << endl;
			cin >> choicedecryptage;
			cout << "Message ? : " << endl;
			cin.ignore();
			getline(cin, message);
			if (choicedecryptage == 1){
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
			else if(choicedecryptage == 2){
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
		else if (choice == 3) {
			cout << "Bye" << endl;
		}
		else {
			cout << "err" << endl;
		}
	}

	return 0;
}
