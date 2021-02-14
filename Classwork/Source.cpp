#include <iostream>
#include <windows.h>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <algorithm> 
#include <functional>

using namespace std;

class Passport {
public:
	string Name;
	string NumPassport;
	Passport(){}
	void AddPassport()
	{
		cout << "Enter your Name-> ";
		cin >> this->Name;
		cout << "Enter your series and number-> ";
		cin >> this->NumPassport;
		cout << endl;
	}
	void ShowPassport() {
		cout << "Name: " << this->Name << endl;
		cout << "Number Pasport: " << this->NumPassport << endl;
		cout << endl;
	}
};

class ForeignPassport : public Passport
{
	class Visa {
	public:
		int numberVisa;
		string country;
		string expiration_date;
		Visa(int numberVisa, string country, string expiration_date)
		{
			this->numberVisa = numberVisa;
			this->country = country;
			this->expiration_date = expiration_date;
		}
		void ShowVisa() {
			cout << "Number visa: " << numberVisa << endl;
			cout << "Country: " << country << endl;
			cout << "Expiration_date: " << expiration_date << endl;
		}

	};
public:
	//Visa visa; // із за цього не створювався конструктор (((
	vector<Visa> vVisa;
	ForeignPassport() : Passport() {} //унаслідувальний конструктор по замовчуванню

	void AddVisa() {
		int numberVisa;
		string country;
		string expiration_date;
		cout << "Enter number by visa: ";
		cin >> numberVisa;
		cout << "Enter  country by visa: ";
		cin >> country;
		cout << "Enter  expiration date by visa: ";
		cin >> expiration_date;
		vVisa.push_back(Visa(numberVisa, country, expiration_date));
	}
	void ShowVisaInfo() {
		ShowPassport();
		for (int i = 0; i < vVisa.size(); i++)
		{
			vVisa[i].ShowVisa();
		}
		cout << endl;
	}
	void DeleteVisa() {
		int number_Visa_delete;
		cout << "1.Enter number visa delete: ";
		cin >> number_Visa_delete;
		for (int i = 0; i < vVisa.size(); i++)
		{
			if (number_Visa_delete == vVisa[i].numberVisa)
			{
				auto it = vVisa.begin();
				advance(it, number_Visa_delete - 1);
				vVisa.erase(it);
			}
		}
	}
};

	int main() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		ForeignPassport foreignPassport;
		//Passport* passport;
		//passport = nullptr;
		int action = 1;
		while (action)
		{
			cout << "1.Add passport" << endl;
			cout << "2.Show passport" << endl;
			cout << "3.Add visa" << endl;
			cout << "4.Show all visat" << endl;
			cout << "5.Delete visa" << endl;
			cout << "6.Delete visa" << endl;
			cout << "0.Exit" << endl;
			cout << endl;

			cout << "Enter menu item: ";
			cout << endl;
			cin >> action;
			switch (action)
			{
			case 1: {
				foreignPassport.AddPassport();
				break;
			}
			case 2: {
				foreignPassport.ShowPassport();
				break;
			}
			case 3: {
				foreignPassport.AddVisa();
				break;
			}
			case 4: {
				foreignPassport.ShowVisaInfo();
				break;
			}
			case 5: {
				foreignPassport.DeleteVisa();
				break;
			}
			case 0: {
				break;
			}
			default:
				break;
			}
		}
		return 0;
	}
