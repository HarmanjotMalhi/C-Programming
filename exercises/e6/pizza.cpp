#include <iostream>

#include <string>

using namespace std;

enum Topping
{
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

class Pizza
{
private:
	bool toppings[20];
	Pizza(const bool toppings[20]); // Optional for internal use, if you want?

public:
	Pizza() {}

	Pizza operator+(const Pizza &other) const
	{
		Pizza *y = new Pizza();

		for (int i = 0; i < sizeof(toppings); i++)
		{
			if (toppings[i] == true || other.toppings[i] == true)
				y->toppings[i] = true;
			else
				y->toppings[i] = false;
		}

		return *y;
	}; // Something for everyone!

	Pizza operator^(const Pizza &other) const
	{
		Pizza *y = new Pizza();

		for (int i = 0; i < sizeof(toppings); i++)
		{
			if (toppings[i] == true && other.toppings[i] == true)
				y->toppings[i] = true;

			else
				y->toppings[i] = false;
		}

		return *y;

	}; // Intersection of agreed-upon tastes

	Pizza operator-(const Pizza &other) const
	{

		Pizza *y = new Pizza();

		for (int i = 0; i < sizeof(toppings); i++)
		{
			if (other.toppings[i] == true)
				y->toppings[i] = false;

			else if (toppings[i] == true)
				y->toppings[i] = true;

			else
				y->toppings[i] = false;
		}

		return *y;

	}; // Exclude everything covered by 'other'

	Pizza operator+(const Topping &other) const

	{

		Pizza *y = new Pizza();

		for (int i = 0; i < sizeof(toppings); i++)
		{

			y->toppings[i] = toppings[i];
		}
		y->toppings[other] = true;

		return *y;

	}; // Adding a single topping
	Pizza operator-(const Topping &other) const
	{

		Pizza *y = new Pizza();

		for (int i = 0; i < sizeof(toppings); i++)
		{

			y->toppings[i] = toppings[i];
		}
		y->toppings[other] = false;

		return *y;

	}; // Gimme one without THAT

	bool operator<=(const Pizza &other) const

	{
		bool b1 = true;

		for (int i = 0; i < 20; i++)
		{

			if (toppings[i] == true)
			{
				if (other.toppings[i] == true)
				{
					b1 = true;
				}
				else
				{
					b1 = false;
					return b1;
				}
			}
		}
		return b1;
	} // Subset

	bool operator<(const Pizza &other) const
	{

		bool b1 = true;
		int cp = 0;
		int op = 0;
		for (int i = 0; i < 20; i++)
		{

			if (other.toppings[i] == true)
			{
				op++;
				if (toppings[i] == true)
				{
					b1 = true;
					cp++;
				}
			}
			else if (toppings[i] == true)
			{
				b1 = false;
				return b1;
			}
		}
		if (cp < op)
			return true;

		else
			return false;

	} // STRICT subset
	bool operator>=(const Pizza &other) const
	{

		bool b1 = true;

		for (int i = 0; i < 20; i++)
		{

			if (other.toppings[i] == true)
			{
				if (toppings[i] == true)
				{
					b1 = true;
				}
				else
				{
					b1 = false;
					return b1;
				}
			}
		}
		return b1;

	} // Superset
	bool operator>(const Pizza &other) const
	{

		bool b1 = true;
		int cp = 0;
		int op = 0;
		for (int i = 0; i < 20; i++)
		{

			if (toppings[i] == true)
			{
				cp++;
				if (other.toppings[i] == true)
				{
					op++;
					b1 = true;
				}
			}
			else if (other.toppings[i] == true)
				return false;
		}
		if (cp > op)
			return true;

		else
			return false;

	} // strict superset

	bool operator==(const Pizza &other) const
	{

		bool b1 = true;
		for (int i = 0; i < 20; i++)
		{

			if (toppings[i] == other.toppings[i])
			{
			}
			else
				return false;
		}

		return b1;
	} // Test for equality
	bool operator!=(const Pizza &other) const

	{

		bool b1 = true;
		for (int i = 0; i < 20; i++)
		{

			if (toppings[i] == other.toppings[i])
			{
			}
			else
				b1 = false;
		}

		if (b1 == true)
			return false;
		else
			return true;

	} // Test for inequality

	bool operator!() const
	{
		bool b1 = true;
		for (int i = 0; i < 20; i++)
		{

			if (toppings[i] == false)
			{
			}
			else
				return false;
		}

		return b1;
	} // Test if this pizza is naked

	int operator()() const

	{

		int numT = 0;
		for (int i = 0; i < 20; i++)
		{

			if (toppings[i] == true)
				numT++;
		}
		return numT;

	} // p() would say the # of toppings on it

	bool operator[](const Topping &t) const

	{

		if (toppings[t] == true)
			return true;

		else
			return false;

	} // Tests if a specific topping is present

	friend std::ostream &operator<<(std::ostream &out, const Pizza &pizza)
	{

		string Toppings[20] = {"RED_SAUCE", "WHITE_SAUCE", "MOZZARELLA", "FETA", "PEPPERONI", "GREEN_PEPPER", "RED_PEPPER", "BANANA_PEPPER", "BLACK_PEPPER", "SAUSAGE", "BACON", "PINEAPPLE", "CORN", "ARTICHOKE", "TOES", "MUSHROOMS", "ONIONS", "HAM", "OLIVES", "CHERRIES"};

		out << " [ ";
		int count = 0;
		for (int i = 0; i < 20; i++)
		{
			if (count == 0 && pizza.toppings[i] == true)
			{
				out << Toppings[i];
				count++;
			}
			else if (pizza.toppings[i] == true)
				out << " | " << Toppings[i];
		}
		out << " ] ";
		return out;
	} // Output
	// We seriously don't want to worry about 'reading' a pizza. They flop over when you try.

	static Pizza oneWithEverything()
	{
		Pizza *y = new Pizza();

		for (int i = 0; i < 20; i++)
		{

			y->toppings[i] = true;
		}
		return *y;
	} // Note: tied to the class; not an object! Contains all 20
	static Pizza meatLovers()
	{

		Pizza *y = new Pizza();

		y->toppings[PEPPERONI] = true;
		y->toppings[SAUSAGE] = true;
		y->toppings[BACON] = true;
		y->toppings[TOES] = true;
		y->toppings[HAM] = true;

		return *y;
	} // Yields Pizza with ONLY meat: Pepperoni, sausage, bacon, toes, and ham (note: not even sauce or cheese)
};

int main()
{

	Pizza *h = new Pizza();

	Pizza *b = new Pizza();

	*h = *h + MOZZARELLA + FETA + RED_PEPPER + CHERRIES + OLIVES;

	*b = *b + CHERRIES + OLIVES + BACON + ARTICHOKE;

	Pizza jU = *h + *b;

	Pizza jI = *h ^ *b;

	Pizza jE = *h - *b;

	cout << "First pizza: " << *h << endl;

	cout << "Second pizza: " << *b << endl;

	cout << "Their union: " << jU << endl;

	cout << "Their intersection: " << jI << endl;

	cout << "excluding second from first: " << jE << endl;

	*h = *h + MUSHROOMS;

	*b = *b - BACON;

	cout << "Adding Mushrooms to the first pizza: " << *h << endl;

	cout << "Removing Bacon from the second pizza: " << *b << endl;

	Pizza *c = new Pizza();

	*c = *c + MOZZARELLA + FETA + RED_PEPPER + CHERRIES + OLIVES + MUSHROOMS;

	Pizza *d = new Pizza();

	*d = *d + MOZZARELLA + FETA + RED_PEPPER;

	cout << " fourth pizza: " << *c << endl;

	cout << "fifth pizza: " << *d << endl;

	if (*c <= *h)
		cout << "fourth pizza is a subset of the first pizza" << endl;

	if (*d < *h)
		cout << "fifth pizza is a strict subset of the first pizza" << endl;

	if (*h >= *c)
		cout << "first pizza is the superset of the fourth pizza" << endl;

	if (*h > *d)
		cout << "first pizza is a strict superset of the fifth pizza" << endl;

	if ((*c < *h) == false)
		cout << "third pizza is not a subset of the first pizza" << endl;

	if (*c == *h)
		cout << "Third pizza is same as the  first pizza" << endl;

	if (*d != *h)
		cout << "Fourth pizza is not equal to the first pizza" << endl;

	if (!h == false)
		cout << "First pizza is not naked" << endl;

	Pizza count = *h;

	int toppCount = count();
	cout << "Number of toppings on the first pizza are: " << toppCount << endl;

	Pizza toppCheck = *h;

	if (toppCheck[MUSHROOMS] == true)
		cout << "Mushrooms is present on the first pizza" << endl;

	Pizza sixth;

	sixth = sixth.oneWithEverything();

	Pizza seven;

	seven = seven.meatLovers();

	cout << "Pizza that contains all the toppings: " << sixth << endl;

	cout << "MeatLovers: " << seven << endl;

	delete h;
	delete b;
	delete c;
	delete d;
}
