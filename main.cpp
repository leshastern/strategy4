#include <iostream>
#include <string>
using namespace std;

class Shop
{
public:
	virtual string payment() const = 0;
};

class Context
{
private:
	Shop* strategy_;
	
public:
	Context(Shop* strategy = nullptr) : strategy_(strategy)
	{
	}
	~Context()
	{
		delete this->strategy_;
	}

	void set_strategy(Shop* strategy)
	{
		delete this->strategy_;
		this->strategy_ = strategy;
	}
	
	void DoSomeBusinessLogic() const
	{
		
		string result = this->strategy_->payment();
		cout << result << endl;
	}
};


class Cash : public Shop
{
public:
	string payment() const override
	{
		return "Cash, skidka";
	}
};

class Card : public Shop
{
public:
	string payment() const override
	{
		return "Card, bonuses";
	}
};


int main()
{
	int N;
	cout << "Enter sum (km/h)\n";
	cin >> N;

	Context* context = new Context();

	if (N <= 0) cout << "Error: invalid data" << endl;
	else if (N < 5000) context->set_strategy(new Cash);
	else if context->set_strategy(new Card);

	context->DoSomeBusinessLogic();
	delete context;

	system("PAUSE");
	return 0;
}
