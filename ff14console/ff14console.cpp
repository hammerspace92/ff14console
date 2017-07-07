// ff14console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class Hunt {
private:
	string name;
	string loc;
	int killnum;
	double xcoord;
	double ycoord;
public:
	Hunt() {
		name = "Poring";
		loc = "CWH";
		killnum = 1;
		xcoord = 0;
		ycoord = 0;
	}
	Hunt(string n1, string l1, int k1) {
		name = n1;
		loc = l1;
		killnum = k1;
		xcoord = 0;
		ycoord = 0;
	}
	Hunt(string n1, string l1, int k1, double x1, double y1) {
		name = n1;
		loc = l1;
		killnum = k1;
		xcoord = x1;
		ycoord = y1;
	}
	string givename() {
		return name;
	}
	string giveloc() {
		return loc;
	}
	int givenum() {
		return killnum;
	}

};

class Bill {
private:
	vector<Hunt> v1;
	int level;
	int id;
public:
	Bill() {
		level = 0;
		id = -1;
	}
	Bill(Hunt h1, Hunt h2, Hunt h3, Hunt h4, Hunt h5, int lev, int newId) {
		v1.push_back(h1);
		v1.push_back(h2);
		v1.push_back(h3);
		v1.push_back(h4);
		v1.push_back(h5);
		level = lev;
		id = newId;
	}
	int givelev() {
		return level;
	}
	int giveId() {
		return id;
	}
	vector<Hunt> giveV() {
		return v1;
	}
};

//Global variables. yes i know it's bad idk wtf i'm doing right now

vector<Hunt> CWH_V;
vector<Hunt> FORE_V;
vector<Hunt> MISTS_V;
vector<Hunt> HINT_V;
vector<Hunt> SEA_V;
vector<Hunt> AZYS_V;
/*
LOCATION KEY:
CWH = Coerthas Western Highlands
FORE = The Dravanian Forelands
MISTS = The Churning Mists
HINT = The Dravanian Hinterlands
SEA = The Sea of Clouds
AZYS = Azys Lla

"The" preface included to maintain consistency with autocomplete dictionary in FFXIV.

*/

void bInsert(Bill in1) {
	bool present = false;
	vector<Hunt> tVec = in1.giveV();
	Hunt ch1;
	string loc1;
	for (int i = 0; i < tVec.size(); i++) {
		ch1 = tVec[i];
		loc1 = ch1.giveloc();
		//cout << "TVEC SIZE: " << tVec.size() << endl;
		if (loc1 == "CWH") {
			for (int j = 0; j < CWH_V.size(); j++) {
				if (CWH_V[j].givename() == ch1.givename()) {
					present = true;
				}
			}
			if (present != true) {
				CWH_V.push_back(ch1);
			}
			
		}
		else if (loc1 == "FORE") {
			for (int j = 0; j < FORE_V.size(); j++) {
				if (FORE_V[j].givename() == ch1.givename()) {
					present = true;
				}
			}
			if (present != true) {
				FORE_V.push_back(ch1);
			}
			
		}
		else if(loc1 == "MISTS") {
			for (int j = 0; j < MISTS_V.size(); j++) {
				if (MISTS_V[j].givename() == ch1.givename()) {
					present = true;
				}
			}
			if (present != true) {
				MISTS_V.push_back(ch1);
			}
			
		}
		else if (loc1 == "HINT") {
			for (int j = 0; j < HINT_V.size(); j++) {
				if (HINT_V[j].givename() == ch1.givename()) {
					present = true;
				}
			}
			if (present != true) {
				HINT_V.push_back(ch1);
			}
			
		}
		else if (loc1 == "SEA") {
			for (int j = 0; j < SEA_V.size(); j++) {
				if (SEA_V[j].givename() == ch1.givename()) {
					present = true;
				}
			}
			if (present != true) {
				SEA_V.push_back(ch1);
			}
			
		}
		else if (loc1 == "AZYS") {
			for (int j = 0; j < AZYS_V.size(); j++) {
				if (AZYS_V[j].givename() == ch1.givename()) {
					present = true;
				}
			}
			if (present != true) {
				AZYS_V.push_back(ch1);
			}
			
		}
		else {
			cout << "ERROR DETECTED IN bInsert, EXITING.\n\n\n";
			break;
		}
		present = false;
	}
	return;
}

void vEmpty(vector<Hunt>&  v1) {
	while (v1.empty() != true) {
		v1.pop_back();
	}
	return;
}

int main()
{
	cout << "Hello world!" << endl;
	string input, filename = "hunts.csv";
	string version = "hw";

	cout << "Input CSV file name (leave 1 if using default Heavensward hunts): ";
	std::cin >> input;
	if (input != "1") {
		filename = input;
		version = "sb";
	}
	ifstream file(filename);
	getline(file, input);
	int count = 0;

	//std::cout << input;

	//data to be extracted from every hunt bill
	int id, num1, num2, num3, num4, num5;
	string h1, h2, h3, h4, h5;
	string loc1, loc2, loc3, loc4, loc5;
	int level = 0;


	//vectors to hold hunt bills of each level
	vector<Bill> L1bills;
	vector<Bill> L2bills;
	vector<Bill> L3bills;
	vector<Bill> ubill; //vector to hold user chosen hunt bills

	Hunt new1, new2, new3, new4, new5;
	Bill newBill;

	//WHILE loop to population hunt bills
	while (file.good()) {
		getline(file, input, ','); // Hunt ID
		id = stoi(input);

		getline(file, input, ',');	//Hunt Mark #1
		h1 = input;
		getline(file, input, ',');	//#1 kills needed
		num1 = stoi(input);
		getline(file, input, ',');
		loc1 = input;

		getline(file, input, ',');	//Hunt Mark #2
		h2 = input;
		getline(file, input, ',');	//#2 kills needed
		num2 = stoi(input);
		getline(file, input, ',');
		loc2 = input;

		getline(file, input, ',');	//Hunt Mark #3
		h3 = input;
		getline(file, input, ',');	//#3 kills needed
		num3 = stoi(input);
		getline(file, input, ',');
		loc3 = input;

		getline(file, input, ',');	//Hunt Mark #4
		h4 = input;
		getline(file, input, ',');	//#4 kills needed
		num4 = stoi(input);
		getline(file, input, ',');
		loc4 = input;

		getline(file, input, ',');	//Hunt Mark #5
		h5 = input;
		getline(file, input, ',');	//#5 kills needed
		num5 = stoi(input);
		getline(file, input, ',');
		loc5 = input;

		getline(file, input, '\n');	//Hunt Bill Level
		level = stoi(input);

		//Creating hunts from given data
		new1 = Hunt(h1, loc1, num1);
		new2 = Hunt(h2, loc2, num2);
		new3 = Hunt(h3, loc3, num3);
		new4 = Hunt(h4, loc4, num4);
		new5 = Hunt(h5, loc5, num5);

		//cout << input;
		//cout << h1 << ", " << num1 << ", " << loc1 << " | " << h2 << ", " << num2 << ", " << loc2 << " | ";
		//cout << h3 << ", " << num3 << ", " << loc3 << " | " << h4 << ", " << num4 << ", " << loc4 << " | " << h5 << ", " << num5 << ", " << loc5 << " | " << level << endl;

		//Creating the Hunt Bill with given attributes
		newBill = Bill(new1, new2, new3, new4, new5, level, id);
		if (level == 3) {
			L3bills.push_back(newBill);
		}
		else if (level == 2) {
			L2bills.push_back(newBill);
		}
		else if (level == 1) {
			L1bills.push_back(newBill);
		}
		else {
			cout << "CRITICAL ERROR %%%%%%%%%%%%%%%%%%%%%" << endl;
			break;
		}

		count++;
	}
	//cout << input;

	file.close();
	//cout << "L1 bill size: " << L1bills.size() << ", L2 bill size: " << L2bills.size() << ", L3 bill size: " << L3bills.size() << endl;

	bool running = true, L1running = true, L2running = true, L3running = true, dRun = true;
	bool L1chosen = false, L2chosen = false, L3chosen = false;
	int billnum = 0;
	int maxSize = 0;
	//Main menu loop
	while (running) {
		cout << "%%%% FFXIV Hunt Tracker %%%%\n";
		cout << "%%%% MENU OPTIONS: \n";
		cout << "[1]: See Level 1 Hunt Bills\n";
		cout << "[2]: See Level 2 Hunt Bills\n";
		cout << "[3]: See Level 3 Hunt Bills\n";
		cout << "[4]: Display all hunts\n";
		cout << "[q/x]: Exit\n";
		cout << "IN: ";
		std::cin >> input;

		if (input == "q" || input == "x") {
			running = false;
			cout << "\n\n\nExiting.";
		}
		else if (input == "1" && L1chosen != true) {
			// Level 1 Hunt Bill Display and Input
			while(L1running) {
				cout << "$$$$ LEVEL 1 HUNT BILLS $$$$\n";
				for (int i = 0; i < L1bills.size(); i++) {
					cout << "[" << i << "]: " << L1bills[i].giveV()[0].givename() << endl;
				}
				cout << "INPUT: ";
				cin >> billnum;

				if (billnum < 0 || billnum > 8) {
					cout << "INVALID NUMBER, TRY AGAIN.\n\n";
				}
				else {
					//ubill.push_back(L1bills[billnum]);
					
					
					bInsert(L1bills[billnum]);
					L1running = false;
				}
			}
			L1running = true;
			L1chosen = true;
		}
		else if (input == "1" && L1chosen == true) {
			cout << "Level 1 Hunt Bill already chosen. Please reset from the Display.\n\n";
		}
		else if (input == "2" && L2chosen != true) {
			
			while (L2running) {
				cout << "$$$$ LEVEL 2 HUNT BILLS $$$$\n";
				for (int i = 0; i < L2bills.size(); i++) {
					cout << "[" << i << "]: " << L2bills[i].giveV()[0].givename() << ", " << L2bills[i].giveV()[1].givename() << endl;
				}
				cout << "INPUT: ";
				cin >> billnum;
				if (billnum < 0 || billnum > 8) {
					cout << "INVALID NUMBER, TRY AGAIN.\n\n";
				}
				else {
					//ubill.push_back(L2bills[billnum]);
					bInsert(L2bills[billnum]);
					L2running = false;

				}
			}
			L2running = true;
			L2chosen = true;
		}
		else if (input == "2" && L2chosen == true) {
			cout << "Level 2 Hunt Bill already chosen. Please reset from the Display.\n\n";
		}
		else if (input == "3" && L3chosen != true) {
			while (L3running) {
				cout << "$$$$ LEVEL 2 HUNT BILLS $$$$\n";
				for (int i = 0; i < L3bills.size(); i++) {
					cout << "[" << i << "]: " << L3bills[i].giveV()[0].givename() << endl;
				}
				cout << "INPUT: ";
				cin >> billnum;
				if (billnum < 0 || billnum > 16) {
					cout << "INVALID NUMBER, TRY AGAIN.\n\n";
				}
				else {
					//ubill.push_back(L3bills[billnum]);
					bInsert(L3bills[billnum]);
					cout << "INSERTING L3BILLS\n";
					cout << L3bills[billnum].giveId() << endl;
					L3running = false;

				}
			
			}
			L3running = true;
			L3chosen = true;
		}
		else if (input == "3" && L3chosen == true) {
			cout << "Level 3 Hunt Bill already chosen. Please reset from the Display.\n\n";
		}
		else if (input == "4") {
			while (dRun) {
				//cout << CWH_V.size() << " " << FORE_V.size() << " " << MISTS_V.size() << " " << HINT_V.size() << " " << SEA_V.size() << " " << AZYS_V.size() << endl;
				
				if (version == "hw") {
					cout << setw(25) << left << "Coerthas Western";
					cout << setw(25) << left << "Drav. Forelands";
					cout << setw(24) << left << "Churning Mists";
					cout << setw(24) << left << "Drav. Hinterlands";
					cout << setw(24) << left << "Sea of Clouds";
					cout << left << "Azys Lla";// << setw(24);
					cout << endl;

					
					if (maxSize < CWH_V.size()) {
						maxSize = CWH_V.size();
					}
					if (maxSize < FORE_V.size()) {
						maxSize = FORE_V.size();
					}
					if (maxSize < MISTS_V.size()) {
						maxSize = MISTS_V.size();
					}
					if (maxSize < HINT_V.size()) {
						maxSize = HINT_V.size();
					}
					if (maxSize < SEA_V.size()) {
						maxSize = SEA_V.size();
					}
					if (maxSize < AZYS_V.size()) {
						maxSize = AZYS_V.size();
					}

					for (int i = 0; i < 150; i++) {
						cout << "=";
					}
					cout << endl;

					for (int i = 0; i < maxSize; i++) {
						if (i < CWH_V.size()) {
							cout << setw(20) << CWH_V[i].givename() << "| " << setw(3) << CWH_V[i].givenum();
						}
						else {
							cout << setw(25) << "";
						}

						if (i < FORE_V.size()) {
							cout << setw(20) << FORE_V[i].givename() << "| " << setw(3) << FORE_V[i].givenum();
						}
						else {
							cout << setw(25) << "";
						}

						if (i < MISTS_V.size()) {
							cout << setw(20) << MISTS_V[i].givename() << "| " << setw(2) << MISTS_V[i].givenum();
						}
						else {
							cout << setw(24) << "";
						}

						if (i < HINT_V.size()) {
							cout << setw(20) << HINT_V[i].givename() << "| " << setw(2) << HINT_V[i].givenum();
						}
						else {
							cout << setw(24) << "";
						}

						if (i < SEA_V.size()) {
							cout << setw(20) << SEA_V[i].givename() << "| " << setw(2) << SEA_V[i].givenum();
						}
						else {
							cout << setw(24) << "";
						}

						if (i < AZYS_V.size()) {
							cout << setw(20) << AZYS_V[i].givename() << "| " << setw(2) << AZYS_V[i].givenum(); //<< setw(24);
						}
						else {
							cout << ""; //<< setw(24);
						}
						cout << endl;
					}
					
				}
				if (maxSize == 0) {
					cout << "You have not selected any hunts.";
				}
				cout << endl << endl;
				cout << "[q]: return to main menu\n";
				cout << "[r]: reset hunts\n";
				cout << "INPUT: ";

				cin >> input;
				if (input == "q" || input == "x") {
					dRun = false;
				}
				else if (input == "r") {
					L1chosen = false;
					L2chosen = false;
					L3chosen = false;
					maxSize = 0;

					vEmpty(CWH_V);
					vEmpty(FORE_V);
					vEmpty(HINT_V);
					vEmpty(MISTS_V);
					vEmpty(SEA_V);
					vEmpty(AZYS_V);
				}
				
			}
			dRun = true;
		}
		else {
			cout << "ERROR: Input not recognized\n\n";
		}


	}

	//std::cin >> input;
    return 0;
}

