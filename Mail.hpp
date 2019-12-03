// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef MAIL_H
#define MAIL_H

#include <iostream>
#include "Address.hpp"
#include <iomanip>
#include <string>
using namespace::std;
using std::string;

class Mail
{
	
	friend istream& operator>>(istream& in, Mail& c);
	friend ostream &operator<<(ostream &, const Mail &);
private:
    // Address from sender
    // Address from receiver
    // Type of Mail: Express, Business or etc..
    // Int: date sent/ date received
    // Int: estimate time to send the mail
    // Mailing Status: Sent/ In-process
	string track; 
	string street;
	string city;
	string state;
	int zip;
   

public:
	Mail() { track = ""; street = ""; city = ""; state = ""; zip = 0; }
	Mail(string t, string s, string c, string st, int z) { track = t; street = s; city = c; state = st; zip = z; };
	//Setters
	
	void setStreet(string s) { street = s; }
	void setCity(string c) { city = c; }
	void setState(string s) { state = s; }
	void setZip(int z) { zip = z; }
	void setTracking(string t) { track = t; }
    // Getters
	string getStreet() const { return street; }
	string getCity() const { return city; }
	string getState() const { return state; }
	int getZip() const { return zip; }
	string getTrack() const { return track; }

   
    
    //Comparing priority
    bool operator<(const Mail &);
    bool operator>( const Mail &);
	void display(Mail& a);
	

};
 ostream& operator<<(ostream& out ,const Mail& m) 
{
	 out << right << setw(14) << "Street: " << m.street << "," << m.city << " " << m.state << " " << m.zip << "Track: " << m.track << endl;
	 return out;
}
 istream& operator >>(istream& in, Mail& c)
 {
	 in >> c.street;
	 in >> c.city;
	 in >> c.state;
	 in >> c.zip;
	 in >> c.track;
	 return in;
 }
 void Mail::display(Mail& a)
 {
	 cout << a;
 }
 bool Mail ::operator<(const Mail& a)
 {
	 bool stt = false;
	 if (city < a.city)
	 {
		 stt = true;
	 }
	 return stt;

 }
 bool Mail::operator>(const Mail& a)
 {
	 bool stt = false;
	 if (city > a.city)
	 {
		 stt = true;
	 }
	 return stt;

 }


#endif
