// Dz  OOP 11.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include <iostream>
using namespace std;    
class Base {
public:
	static int people_on_base;
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
};

class Vechicle
{
protected:
	double petrol_amount;	
	double tank_volume;	

public:	
	Vechicle() = default;	
	Vechicle(double petrol_amount, double tank_volume) 
	{
		this->petrol_amount = petrol_amount;	
		this->tank_volume = tank_volume;
	}
	double getTankVolume() 
	{
		return tank_volume;
	}
	double getPetrolAmount() 
	{
		return petrol_amount;	
	}
	virtual void arrive() 
	{
		cout << "The car is located at the base\n";
	}
	virtual bool leave()	
	{
		return true;
	}
};	

class Bus: public Vechicle	
{
private:
	int people;
	int max_people;	

public:
	Bus(int people, int max_people, double petrol, double max_petrol):Vechicle(petrol, max_petrol)
	{
		this->people = people;	
		this->max_people = max_people;	
	}
	int getPeopleCount() 
	{
		return people;	
	}
	int getMaxPeople() 
	{
		return max_people;	
	}
	void arrive()	
	{
		cout << "Number of people: " << people << endl;		
		Base::people_on_base += people;
	}
	bool leave() 
	{
		if (getTankVolume() > getPetrolAmount()) 
		{
			return false;	
		}	
		if (people != 0 && Base::people_on_base > max_people)	
		{	
			Base::people_on_base -= people;
			Base::vehicles_on_base--;
		}
		else {
			return false;	
		}
	}
};

class Truck : public Vechicle 
{
private:
	double load;
	double max_load;
public:
	Truck(double load, double max_load, double petrol, double max_petrol) : Vechicle(petrol, max_petrol)	
	{
		this->load = load;
		this->max_load = max_load;
	}
	double getCurrentLoad() 
	{
		return load;
	}
	double getMaxLoad() 
	{
		return max_load;	
	}
	void arrive() 
	{
		cout << "Number of tons of cargo on the bus " << load << endl;
		if (load != 0.0)	
		{
			Base::goods_on_base += load;		
		}
	}	
	bool leave() 
	{
		if (getTankVolume() > getPetrolAmount()) 
		{
			return false;
		}
		else {
			Base::goods_on_base -= load;
			petrol_amount = tank_volume;	
			Base::vehicles_on_base--;	
				
			return true; 
		}
	}	
};


int main()
{
	Bus obj1(12, 34, 12.0, 78.1);
	Truck  obj2(7.8, 15, 30.0, 60.7);	

	obj1.arrive();	
	obj2.arrive();

	bool rez1 = obj1.leave();	
	bool rez2 = obj2.leave();

	cout << "people_on_base: " << Base::people_on_base << endl;	
	cout << "vehicles_on_base: " << Base::vehicles_on_base << endl;
	cout << "petrol_on_base: " << Base::petrol_on_base << endl;
	cout << "goods_on_base: " << Base::petrol_on_base << endl;

	if (rez1 == true) {
		cout << "The truck left\n";
	}
	else {
		cout << "The truck didn't leave\n";
	}

	if (rez2 == true) {
		cout << "The bus left\n";
	}
	else {
		cout << "The bus didn't leave\n";	
	}
}
	
int Base::people_on_base = 3;
int Base::vehicles_on_base = 8;
double Base::petrol_on_base = 5.0;
double Base::goods_on_base = 7.3;

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
