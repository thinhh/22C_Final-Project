// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef ADDRESS_H
#define ADDRESS_H
#include <iomanip>
#include <iostream>
#include <string>
using namespace::std;
using std::string;


class Address
{
	friend ostream& operator <<(ostream& out, const Address& c);
	friend istream& operator >>(istream& in, Address& c);

private:
    
	int ID;
	string street;
    string city;
    string state;
    int zip;
	
public:
	Address() { ID = -1; street = ""; city = ""; state = ""; zip = 0; }
	Address(int i, string s, string c, string st, int z) { ID = i; street = s; city = c; state = st; zip = z; }
	//Setters
	void setID(int i) { ID = i; }
	void setStreet(string s) { street = s; }
	void setCity(string c) { city = c; }
	void setState(string s) { state = s; }
	void setZip(int z) { zip = z; }
    // Getters
    string getStreet() const { return street; }
    string getCity() const { return city; }
	string getState() const { return state; }
    int getZip() const { return zip; }

    // Other functions
	void display(Address& a);
	bool operator<(const Address &);
	bool operator>(const Address&);
	
};
 ostream& operator <<(ostream& out, const Address& c)
{
	 out << right << setw(14) << "Street: " << c.street << endl
		 << right << setw(14) << "City: " << c.city << endl
		 << right << setw(14) << "State: " << c.state << endl
		 << right << setw(14) << "Zip: " << c.zip << endl;
	 return out;
}
 istream& operator >>(istream& in, Address& c)
 {
	 in >> c.street;
	 in >> c.city;
	 in >> c.state;
	 in >> c.zip;
	 return in;
 }

 void Address::display( Address& a)
 {
	 cout << a; 
 }
 bool Address ::operator<(const Address& a)
 {
	 bool stt = false;
	 if (city < a.city) 
	 {
		 stt = true;
	 }
	 return stt;
	 
 }
 bool Address ::operator>(const Address& a)
 {
	 bool stt = false;
	 if (city > a.city)
	 {
		 stt = true;
	 }
	 return stt;

 }
 
#endif
