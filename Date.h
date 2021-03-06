 #ifndef __DATE_H_INCLUDED__
#define __DATE_H_INCLUDED__
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iostream>
//#include <sstream>
class Date {
	private:
		struct std::tm * primitiveTM;
		//struct primitiveTM;
        std::time_t primitive;
        std::string scale="year";
        void setPrimitive(std::string&);
        void parseDash(std::string&);
        void parseSlash(std::string&);
        void IntToDate(int, int, int);
	public:
		Date();
        Date(std::string&);
        Date(char const[]);
        Date(std::time_t&);
	   std::time_t getPrimitive() const;
        Date operator=(std::string&);
        Date operator=(char const[]);
		double dateDiff(const Date&) const;
		int msDiff(Date&);
		Date dateAdd(double) const;
		void setScale(std::string&);
        void setScale(char const[]);
        int size();
        std::string type();
        std::string strDate() const;
        friend double operator-(const Date&, const Date&);
        friend Date operator+(const Date&, double);
        friend std::ostream& operator<<(std::ostream& out, const Date& x) {
            out<<x.strDate();
            return out;
        }
        friend bool operator<(const Date&, const Date&);
        friend bool operator==(const Date&, const Date&);
        friend bool operator>(const Date&, const Date&);
        friend bool operator!=(const Date&, const Date&);
};

#endif
