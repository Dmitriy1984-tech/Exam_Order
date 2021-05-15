#include "InsureOrder.h"
#include "RegularOrder.h"
#include "RushOrder.h"

#include <fstream>

#include <vector>
#include <string>

#include <iostream>
using namespace std;


int main()
{
	
	vector <Order*> order;

	int type;

	Date date;
	Time_ time;
	string id;

	string courier;
	Date deliveryDate;

	string insurenceCompany;
	int sum;

	int menu;

	int index;

	string fileName;

	int menu2 = 0;

	int menu3 = 0;

	int day=0, month=0, year=0;

	int count = 0;


	do
	{
		cout << "1 - Add order" << endl;
		cout << "2 - Delete order" << endl;
		cout << "3 - Edit order" << endl;
		cout << "4 - Print order" << endl;
		cout << "5 - Save to file" << endl;
		cout << "6 - Load from file" << endl;
		cout << "7 - Find by" << endl;
		cout << "0 - EXIT" << endl;

		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "Select order type: " << endl;
			cout << "1 - regular order" << endl;
			cout << "2 - rush order" << endl;
			cout << "3 - insured order" << endl;
			cin >> type;
			if (type == 1)
			{
				cout << "Input date: " << endl;
				cin >> date;
				cout << "Input time: " << endl;
				cin >> time;
				cout << "Input id: " << endl;
				cin >> id;

				order.push_back(new RegularOrder(date, time, id));
			}

			if (type == 2)
			{
				cout << "Input date: " << endl;
				cin >> date;
				cout << "Input time" << endl;
				cin >> time;
				cout << "Input id: " << endl;
				cin >> id;
				cout << "Input courier: " << endl;
				cin >> courier;
				cout << "Input deliveryDate: " << endl;
				cin >> deliveryDate;

				order.push_back(new RushOrder(date, time, id, courier, deliveryDate));
			}

			if (type == 3)
			{
				cout << "Input date: " << endl;
				cin >> date;
				cout << "Input time: " << endl;
				cin >> time;
				cout << "Input id: " << endl;
				cin >> id;
				cout << "Input insurence company: " << endl;
				cin >> insurenceCompany;
				try
				{
					cout << "Input new sum: " << endl;
					cin >> sum;

					if (sum < 0) cout << "Wrong summa!!!" <<
						"Entering summa greater than zero!!!" << endl
						<< endl;

					if (sum > LONG_MAX) throw "Overflow!!! Max sum is " + to_string(LONG_MAX);
					if (sum < LONG_MIN) throw "Overflow!!! Min sum is " + to_string(LONG_MIN);

					order.push_back(new InsureOrder(date, time, id, insurenceCompany, sum));

				}
				catch (const char* s)
				{
					cout << s << endl;
				}

			
			}


			break;

		case 2:
			
			/*if (index < 0 || index >= order.size())
				cout << "Out of range!!!" << endl;
			else
			{*/
			try
			{
				cout << "Input index: " << endl;
				cin >> index;
				if (index < 0 && index > order.size())
					throw "Out of range";

				auto iter = order.cbegin() + index;
				order.erase(order.cbegin() + index);
			}
			catch (char* s)
			{
				cout << s << endl;
			}
				
			/*}*/
			break;

		case 3:
			try
			{
				cout << "Input index: " << endl;
				cin >> index;
				if (index < 0 && index > order.size())
				throw "Out of range";


				if (order[index]->type() == "RegularOrder")
				{
					do
					{
						cout << "1 - change  date" << endl;
						cout << "2 - change time" << endl;
						cout << "3 - change id" << endl;
						cout << "0 - EXIT" << endl;
						cin >> menu2;

						switch (menu2)
						{
						case 1:

							cout << "Input new date: " << endl;
							cin >> date;
							order[index]->setDate(date);
							break;

						case 2:
							cout << "Input new time: " << endl;
							cin >> time;
							order[index]->setTime(time);
							break;

						case 3:
							cout << "Input new id:" << endl;
							cin >> id;
							order[index]->setId(id);
							break;
						}

					} while (menu2 != 0);
				}

				if (order[index]->type() == "RushOrder")
				{
					do
					{
						cout << "1 - change  date" << endl;
						cout << "2 - change time" << endl;
						cout << "3 - change id" << endl;
						cout << "4 - change courier" << endl;
						cout << "5 - change delivery date" << endl;
						cout << "0 - EXIT" << endl;
						cin >> menu2;

						switch (menu2)
						{
						case 1:

							cout << "Input new date: " << endl;
							cin >> date;
							((RushOrder*)order[index])->setDate(date);

							break;

						case 2:
							cout << "Input new time: " << endl;
							cin >> time;
							((RushOrder*)order[index])->setTime(time);
							break;

						case 3:
							cout << "Input new id:" << endl;
							cin.get();
							cin >> id;
							((RushOrder*)order[index])->setId(id);
							break;

						case 4:
							cout << "Input new courier: " << endl;
							cin.get();
							cin >> courier;
							((RushOrder*)order[index])->setCourier(courier);
							break;
						case 5:
							cout << "Input new delivery date: " << endl;
							cin >> deliveryDate;
							((RushOrder*)order[index])->setDeliveryDate(deliveryDate);
							break;
						}

					} while (menu2 != 0);
				}

				if (order[index]->type() == "InsureOrder")
				{
					do
					{
						cout << "1 - change  date" << endl;
						cout << "2 - change time" << endl;
						cout << "3 - change id" << endl;
						cout << "4 - change insurence company" << endl;
						cout << "5 - change sum" << endl;
						cout << "0 - EXIT" << endl;
						cin >> menu2;

						switch (menu2)
						{
						case 1:

							cout << "Input new date: " << endl;
							cin >> date;
							((InsureOrder*)order[index])->setDate(date);

							break;

						case 2:
							cout << "Input new time: " << endl;
							cin >> time;
							((InsureOrder*)order[index])->setTime(time);
							break;

						case 3:
							cout << "Input new id:" << endl;
							cin.get();
							cin >> id;
							((InsureOrder*)order[index])->setId(id);
							break;

						case 4:
							cout << "Input new insurerence company: " << endl;
							cin.get();
							cin >> insurenceCompany;
							((InsureOrder*)order[index])->setInsurenceCompany(insurenceCompany);
							break;

						case 5:

							try
							{
								cout << "Input new sum: " << endl;
								cin >> sum;

								if (sum < 0) cout << "Wrong summa!!!" <<
									"Entering summa greater than zero!!!" << endl
									<< endl;

								if (sum > LONG_MAX) throw "Overflow!!! Max sum is " + to_string(LONG_MAX);
								if (sum < LONG_MIN) throw "Overflow!!! Min sum is " + to_string(LONG_MIN);

								((InsureOrder*)order[index])->setSum(sum);
							}
							catch (char* s)
							{
								cout << s << endl;
							}

							

							break;
						}

					} while (menu2 != 0);
				}


			}
			catch (const char* s)
			{
				cout<<s<<endl;
			}
			
			/*if (index >= 0 && index < order.size())
			{*/
			
				
			//}

			//else cout << "Out of range" << endl;


			break;

		case 4:
			for (auto& x : order)	cout << x->toString();
			break;

		case 5:
		{
			cout << "Input fileName: " << endl;
			cin >> fileName;
			ofstream file(fileName + ".txt", ios::app);
			if (file)
			{
				for (int i = 0; i < order.size(); i++)
				{
					order[i]->save(file);
				}
			}
			file.close();
			break;

		}
			

		case 6:
		{
			cout << "Input fileName: " << endl;
			cin >> fileName;
			ifstream file(fileName + ".txt");
			if (file.is_open())
				while (!file.eof())
				{
					string type;
					Order* obj;
					getline(file, type);
					if (type == "RegularOrder")
					{
						obj = new RegularOrder();
						obj->load(file);
						order.push_back(obj);
					}
					else if (type == "RushOrder")
					{
						obj = new RushOrder();
						obj->load(file);
						order.push_back(obj);
					}
					else if (type == "InsureOrder")
					{
						obj = new InsureOrder();
						obj->load(file);
						order.push_back(obj);
					}

				}
			file.close();
			break;
		}
			
			

		case 7:
			do
			{
				cout << "1 - Find by date" << endl;
				cout << "2 - Find by time" << endl;
				cout << "3 - Find by id" << endl;
				cout << "4 - Find by courier" << endl;
				cout << "5 - Find by delivery date" << endl;
				cout << "6 - Find by insurence company" << endl;
				cout << "7 - Find by sum" << endl;
				cout << "0 - EXIT" << endl;

				cin >> menu2;
				switch (menu2)
				{
				case 1:
					cout << "Input date:" << endl;
					cin >> date;
					count = 0;
					for (auto& x : order)
						if (x->getDate() == date)
						{
							cout << x->toString();
							count++;
						}
					if (count == 0) cout << "No such record" << endl;
							
					break;

				case 2:
					cout << "Input time: " << endl;
					cin >> time;

					count = 0;

					for (auto& x : order)
						if (x->getTime() == time)
						{
							cout << x->toString();
							count++;
						}
					if (count == 0) cout << "No such record" << endl;
							
					break;

				case 3:
					cout << "Input id: " << endl;
					cin >> id;
					count = 0;

					for (auto& x : order)
						if (x->getId() == id)
						{
							cout << x->toString();
							count++;
						}
					if (count == 0) cout << "No such record" << endl;
					break;

				case 4:
					cin.get();
					cout << "Input courier: " << endl;
					cin >> courier;

					count == 0;
					for (int i = 0; i < order.size(); i++)

						if (((RushOrder*)order[i])->getCourier() == courier)
						{
							cout << order[i]->toString();
							count++;
						}
					if (count == 0) cout << "No such record" << endl;
					break;

				case 5:
					cout << "Input delivery date: " << endl;
					cin >> deliveryDate;

					count == 0;

					for (int i = 0; i < order.size(); i++)
						if (((RushOrder*)order[i])->getDeliveryDate() == deliveryDate)
						{
							cout << order[i]->toString();
							count++;
						}
					if (count == 0) cout << "No such record" << endl;
					break;

				case 6:
					cin.get();
					cout << "Input insurence company: " << endl;
					cin >> insurenceCompany;

					count = 0;

					for (int i = 0; i < order.size(); i++)
						if (((InsureOrder*)order[i])->getInsurenceCompany() == insurenceCompany)
						{
							cout << order[i]->toString();
							count++;
						}
					if (count == 0) cout << "No such record" << endl;
					break;

				case 7:
					cout << "Input sum: " << endl;
					cin >> sum;
					do
					{
						cout << "1 -Find more than sum " << endl;
						cout << "2 -Find less than sum " << endl;
						cout << "3 -Find sum " << endl;
						cout << "0 - EXIT" << endl;

						cin >> menu3;

						switch (menu3)
						{
						case 1 :
							count = 0;
							for (int i = 0; i < order.size(); i++)
								if (((InsureOrder*)order[i])->getSum() > sum)
								{
									cout << order[i]->toString();
									count++;
								}
							if (count == 0) cout << "No such record" << endl;
									
							break;

						case 2:
							count = 0;
							for (int i=0;i<order.size(); i++)
								if (((InsureOrder*)order[i])->getSum()<sum)
								{
									cout << order[i]->toString();
									count++;
								}
							if (count == 0) cout << "No such record" << endl;
							break;

						case 3:
							for (int i=0; i<order.size();i++)
								if (((InsureOrder*)order[i])->getSum() == sum)
								{
									cout << order[i]->toString();
									count++;
								}
							if (count == 0) cout << "No such record" << endl;
							break;

						}

					}
					while (menu3 != 0);

					break;
				}

			} while (menu3 != 0);
			break;

			}

		} 
		while (menu != 0);

	return 0;
}