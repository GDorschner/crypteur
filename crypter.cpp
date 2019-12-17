#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>


int main()
{
	int choix = { 0 }, choixcryptage = { 0 }, choixdecryptage = { 0 };
	string message;
	cout << "boujour voisi un encodeur" << endl;
	while (choix != 3) {
		cout << "1. crypter 2. decrypter 3. exit" << endl;
		cin >> choix;
		//--------------------------Crypter--------------------------------
		if (choix == 1) {
			cout << "taper votre message:" << endl;
			cin.ignore();
			getline(cin, message);
			cout << "cryptage 1. faible 2.fort" << endl;
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
				cout << "la key vaut: " << key << endl;
			}
			else if(choixcryptage == 2){
				//--------------------------choixcryptage fort--------------------------------
				cout << "en developement" << endl;
			}
		}

		//--------------------------Decrypter--------------------------------
		else if (choix == 2) {
			cout << "decryptage 1. faible 2.fort" << endl;
			cin >> choixdecryptage;
			int key;
			cout << "quelle est votre key: " << endl;
			cin >> key;
			cout << "quelle est votre message" << endl;
			cin.ignore();
			getline(cin, message);
			if (choixdecryptage == 1){
				//--------------------------choixdecryptage faible--------------------------------
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
			}
		}
		//--------------------------Leave--------------------------------
		else if (choix == 3) {
			cout << "aurevoir" << endl;
		}
		else {
			cout << "erreur" << endl;
		}
	}

	system("pause");
	return 0;
}