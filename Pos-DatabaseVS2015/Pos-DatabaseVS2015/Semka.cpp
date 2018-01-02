// Semka.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Logins.h"
#include "Database.h"
#include <fstream>
#include "Commands.h"
//ss

using namespace std;

int main()
{
	//nacitanie loginov zo suboru Logins
	Logins *log = new Logins();
	string prikaz,username,password = "";
	cout << "Log in Foltan&Sarina's database:\nUsername:\n";
	cin >> username;
	cout << "password:\n";
	cin >> password;
	while (!log->checkUserAndPass(username,password)) { //overenie hesla
		cout << "nespravne meno alebo heslo:\nZnovu zadajte: \n";
		cin >> username;
		cout << "password:\n";
		cin >> password;
	}
	cout << "Login sucesfully! \n [1]createTable [2]exit [3]AlterTable\n";
	Database *database = new Database(); //uz prihlaseny v DB
	cin >> prikaz;

	//ss
	switch (checkInput(prikaz)){
	case(EndProgram):
		return 0; // ukoncenie prirobit destruovanie objektov
		break;
	case(CreateTable):
		cout << "Zadajte nazov tabulky \n";
		cin >> prikaz;
		while (!database->createTable(prikaz)) { //vytvaranie tabulky a stlpcov
			cout << "Zadajte nazov tabulky \n";
			cin >> prikaz;
			if (prikaz == "exit") {
				break;
			}		
		}
		// mna jebneeeeeee
		break;
	case(AlterTable):
		//vytvorenie columnov
		cout << "Zadajte nazov tabulky na editovanie \n";
		cin >> prikaz;
		while (!database->findTable(prikaz))
		{
			cout << "Zadajte nazov tabulky na editovanie \n";
			cin >> prikaz;
		}
		//editovanie tabulky bude riadit trieda na editovanie kvoli
		//kritickym sekciam 
		///tu by sa mali zobrazit info o celej tabulke
		cout << database->toString(prikaz); //vypisanie tabulky


		//naplnanie riadkov podla columnov
		// nastavenie PK
		break;
	default:
		break;
	}




	
	

	cin >> prikaz;
    return 0;
}

