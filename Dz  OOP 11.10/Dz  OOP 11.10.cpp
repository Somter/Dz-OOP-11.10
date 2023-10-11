// Dz  OOP 11.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		
	}	
};

int main()
{
  
}
	
int Base::people_on_base = 1;
int Base::vehicles_on_base = 0;
double Base::petrol_on_base = 0.0;
double Base::goods_on_base = 7.3;	


//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Base {
//public:
//    static int people_on_base;
//    static int vehicles_on_base;
//    static double petrol_on_base;
//    static double goods_on_base;
//};
//
//class Vehicle {
//    double petrol_amount;
//    double tank_volume;
//public:
//    Vehicle(double petrol_amount, double tank_volume) : petrol_amount(petrol_amount), tank_volume(tank_volume) {}
//    double getTankVolume() {
//        return tank_volume;
//    }
//    double getPetrolAmount() {
//        return petrol_amount;
//    }
//    virtual void arrive() {
//        cout << "Vehicle arrived at the base." << endl;
//    }
//    virtual bool leave() {
//        return true;
//    }
//};
//
//class Bus : public Vehicle {
//    int people;
//    int max_people;
//public:
//    Bus(int people, int max_people, double petrol, double max_petrol) : Vehicle(petrol, max_petrol), people(people), max_people(max_people) {}
//    int getPeopleCount() {
//        return people;
//    }
//    int getMaxPeople() {
//        return max_people;
//    }
//    void arrive() {
//        cout << "Bus arrived at the base with " << people << " passengers." << endl;
//        Base::people_on_base += people;
//        Vehicle::arrive();
//    }
//    bool leave() {
//        if (Base::people_on_base > 0) {
//            if (Base::people_on_base > max_people) {
//                people = max_people;
//                Base::people_on_base -= max_people;
//            }
//            else {
//                people = (max_people - Base::people_on_base);
//            }
//
//            Vehicle::leave();
//        }
//
//        return false;
//    }
//};
//
//class Truck : public Vehicle {
//    double load;
//    double max_load;
//public:
//    Truck(double load, double max_load, double petrol, double max_petrol) : Vehicle(petrol, max_petrol), load(load), max_load(max_load) {}
//    double getCurrentLoad() {
//        return load;
//    }
//    double getMaxLoad() {
//        return max_load;
//    }
//    void arrive() {
//        cout << "Truck arrived at the base with a load of " << load << " tons." << endl;
//        Base::goods_on_base += load;
//        Vehicle::arrive();
//    }
//    bool leave() {
//        if (Base::goods_on_base > 0) {
//            if (Base::goods_on_base > max_load) {
//                load = max_load;
//                Base::goods_on_base -= max_load;
//            }
//            else {
//                load = (max_load - Base::goods_on_base);
//            }
//
//            Vehicle::leave();
//        }
//
//        return false;
//    }
//};
//
//int Base::people_on_base = 10;
//int Base::vehicles_on_base = 0;
//double Base::petrol_on_base = 25000.0;
//double Base::goods_on_base = 1500.0;
//
//int main() {
//    Bus bus(20, 50, 20.0, 100.0);
//    Truck truck(10, 30.0, 30.0, 150.0);
//
//    bus.arrive();
//    truck.arrive();
//
//    if (bus.leave()) {
//        cout << "Bus successfully left the base." << endl;
//    }
//    else {
//        cout << "Bus couldn't leave the base." << endl;
//    }
//
//    if (truck.leave()) {
//        cout << "Truck successfully left the base." << endl;
//    }
//    else {
//        cout << "Truck couldn't leave the base." << endl;
//    }
//
//    return 0;
////}
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Base {
//public:
//    static int people_on_base;
//    static int vehicles_on_base;
//    static double petrol_on_base;
//    static double goods_on_base;
//};
//
//int Base::people_on_base = 0;
//int Base::vehicles_on_base = 0;
//double Base::petrol_on_base = 100.0;  // Íà÷àëüíîå êîëè÷åñòâî áåíçèíà (ïðîèçâîëüíîå çíà÷åíèå)
//double Base::goods_on_base = 50.0;    // Íà÷àëüíîå êîëè÷åñòâî ãðóçà (ïðîèçâîëüíîå çíà÷åíèå)
//
//class Vehicle {
//protected:
//    double petrol_amount;
//    double tank_volume;
//
//public:
//    Vehicle(double petrol_amount, double tank_volume) : petrol_amount(petrol_amount), tank_volume(tank_volume) {}
//
//    double getTankVolume() {
//        return tank_volume;
//    }
//
//    double getPetrolAmount() {
//        return petrol_amount;
//    }
//
//    virtual void arrive() {
//        cout << "Vehicle arrived at the base." << endl;
//    }
//
//    virtual bool leave() {
//        return true;
//    }
//};
//
//class Bus : public Vehicle {
//private:
//    int people;
//    int max_people;
//
//public:
//    Bus(int people, int max_people, double petrol, double max_petrol)
//        : Vehicle(petrol, max_petrol), people(people), max_people(max_people) {}
//
//    int getPeopleCount() {
//        return people;
//    }
//
//    int getMaxPeople() {
//        return max_people;
//    }
//
//    void arrive() {
//        cout << "Bus arrived at the base with " << people << " passengers." << endl;
//        Base::people_on_base += people;
//        Vehicle::arrive();
//    }
//
//    bool leave() {
//        if (Base::people_on_base >= people && petrol_amount >= tank_volume) {
//            cout << "Bus left the base with " << people << " passengers." << endl;
//            Base::people_on_base -= people;
//            petrol_amount = 0.0;
//            return true;
//        }
//        return false;
//    }
//};
//
//class Truck : public Vehicle {
//private:
//    double load;
//    double max_load;
//
//public:
//    Truck(double load, double max_load, double petrol, double max_petrol)
//        : Vehicle(petrol, max_petrol), load(load), max_load(max_load) {}
//
//    double getCurrentLoad() {
//        return load;
//    }
//
//    double getMaxLoad() {
//        return max_load;
//    }
//
//    void arrive() {
//        cout << "Truck arrived at the base with a load of " << load << " tons." << endl;
//        Base::goods_on_base += load;
//        Vehicle::arrive();
//    }
//
//    bool leave() {
//        if (Base::goods_on_base >= load && petrol_amount >= tank_volume) {
//            cout << "Truck left the base with a load of " << load << " tons." << endl;
//            Base::goods_on_base -= load;
//            petrol_amount = 0.0;  // Refuel the tank
//            return true;
//        }
//        return false;
//    }
//};
//
//int main() {
//    Bus bus(20, 50, 70.0, 100.0);
//    Truck truck(10.0, 30.0, 100.0, 150.0);
//
//    bus.arrive();
//    truck.arrive();
//
//    if (bus.leave()) {
//        cout << "Bus successfully left the base." << endl;
//    }
//    else {
//        cout << "Bus couldn't leave the base." << endl;
//    }
//
//    if (truck.leave()) {
//        cout << "Truck successfully left the base." << endl;
//    }
//    else {
//        cout << "Truck couldn't leave the base." << endl;
//    }
//
//    cout << endl;
//    cout << "Base::people_on_base " << Base::people_on_base << endl;
//    cout << "Base::vehicles_on_base " << Base::vehicles_on_base << endl;
//    cout << "Base::petrol_on_base " << Base::petrol_on_base << endl;
//    cout << "Base::goods_on_base " << Base::goods_on_base << endl;
//
//    return 0;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
