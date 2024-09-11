#include <iostream>
//Reminder: http://en.cppreference.com/w/cpp/language/operators
using std::string;

//Yes, unscoped, because the TA WON'T be using C++11 to compile.
enum Topping {
	RED_SAUCE,
	WHITE_SAUCE,
	MOZZARELLA,
	FETA,
	PEPPERONI,
	GREEN_PEPPER,
	RED_PEPPER,
	BANANA_PEPPER,
	BLACK_PEPPER,
	SAUSAGE,
	BACON,
	PINEAPPLE,
	CORN,
	ARTICHOKE,
	TOES,
	MUSHROOMS,
	ONIONS,
	HAM,
	OLIVES,
	CHERRIES
};

class Pizza {
private:
	bool toppings[20];
	Pizza(const bool toppings[20]); //Optional for internal use, if you want?
	
public:
	Pizza();
	
	Pizza operator+(const Pizza &other) const; //Something for everyone!
	Pizza operator^(const Pizza &other) const; //Intersection of agreed-upon tastes
	Pizza operator-(const Pizza &other) const; //Exclude everything covered by 'other'
	
	Pizza operator+(const Topping &other) const; //Adding a single topping
	Pizza operator-(const Topping &other) const; //Gimme one without THAT
	
	bool operator<=(const Pizza &other) const; //Subset
	bool operator<(const Pizza &other) const; //STRICT subset
	bool operator>=(const Pizza &other) const; //Superset
	bool operator>(const Pizza &other) const; //strict superset
	bool operator==(const Pizza &other) const; //Test for equality
	bool operator!=(const Pizza &other) const; //Test for inequality
	
	bool operator!() const; //Test if this pizza is naked
	int operator()() const; //p() would say the # of toppings on it
	
	bool operator[](const Topping &t) const; //Tests if a specific topping is present
	
	friend std::ostream& operator<<(std::ostream &out, const Pizza &pizza);//Output
	//We seriously don't want to worry about 'reading' a pizza. They flop over when you try.
	
	static Pizza oneWithEverything(); //Note: tied to the class; not an object! Contains all 20
	static Pizza meatLovers(); //Yields Pizza with ONLY meat: Pepperoni, sausage, bacon, toes, and ham (note: not even sauce or cheese)
};
