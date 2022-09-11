#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class PizzaSlice {
public:
	virtual PizzaSlice* clone()=0;
	virtual void show()=0;
	virtual ~PizzaSlice() {
	}
};

class Margherita: public PizzaSlice {
	int mozarella;
public:
	Margherita(int mozarella = 0) {
		this->mozarella = mozarella;
	}
	Margherita(Margherita *pizza) {
		this->mozarella = pizza->mozarella;
	}
	PizzaSlice* clone() {
		return new Margherita(this);
	}
	void show() {
		cout << "This is a slice of Margherita" << endl;
	}
};

class QuattroFormaggi: public PizzaSlice {
	int mozarella;
	int parmesan;
	int gruyere;
	int saga_blue;
public:
	QuattroFormaggi(int mozarella = 0, int parmesan = 0, int gruyere = 0,
			int saga_blue = 0) {
		this->mozarella = mozarella;
		this->parmesan = parmesan;
		this->gruyere = gruyere;
		this->saga_blue = saga_blue;
	}
	QuattroFormaggi(QuattroFormaggi *pizza) {
		this->mozarella = pizza->mozarella;
		this->parmesan = pizza->parmesan;
		this->gruyere = pizza->gruyere;
		this->saga_blue = pizza->saga_blue;
	}
	PizzaSlice* clone() {
		return new QuattroFormaggi(this);
	}
	void show() {
		cout << "This is a slice of Quattro Formaggi" << endl;
	}
};

class Pepperoni: public PizzaSlice {
	int mozarella;
	int pepperoni;
public:
	Pepperoni(int mozarella = 0, int pepperoni = 0) {
		this->mozarella = mozarella;
		this->pepperoni = pepperoni;

	}
	Pepperoni(Pepperoni *pizza) {
		this->mozarella = pizza->mozarella;
		this->pepperoni = pizza->pepperoni;
	}
	PizzaSlice* clone() {
		return new Pepperoni(this);
	}
	void show() {
		cout << "This is a slice of Pepperoni" << endl;
	}
};

class Hawaii: public PizzaSlice {
	int mozarella;
	int ham;
	int pineapple;
public:
	Hawaii(int mozarella = 0, int ham = 0, int pineapple = 0) {
		this->mozarella = mozarella;
		this->ham = ham;
		this->pineapple = pineapple;

	}
	Hawaii(Hawaii *pizza) {
		this->mozarella = pizza->mozarella;
		this->pineapple = pizza->pineapple;
		this->ham = pizza->ham;
	}
	PizzaSlice* clone() {
		return new Hawaii(this);
	}
	void show() {
		cout << "This is a slice of Hawaii" << endl;
	}
};

int main() {
	srand(time(NULL));
	vector<PizzaSlice*> samples = { new Margherita, new QuattroFormaggi,
			new Pepperoni, new Hawaii };
	vector<PizzaSlice*> pizza(8);

	generate(pizza.begin(),pizza.end(),[samples](){
		return samples[rand() % samples.size()]->clone();
	});

	for (auto slice : pizza)
		slice->show();
	return 0;
}
