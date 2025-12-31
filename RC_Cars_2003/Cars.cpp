class Car
{
protected:
	float max_speed;
	float acceleration;
	float current_speed;
	float money;

public:
	Car(float max_sp, float accel): max_speed(max_sp), acceleration(accel), current_speed(0), money(0) {}
	
	virtual void accelerate() = 0;
	virtual void brake() = 0;

	void upgrade_engine(float cost)
	{
		if (money >= cost)
		{
			max_speed += 5;
			money -= cost;
		}
	}
	float get_current_speed() { return current_speed; }
};


class SportsCar : public Car
{
public:
	SportsCar() : Car(200, 15){}
	void accelerate() override
	{
		current_speed += acceleration;
		if (current_speed > max_speed)
			current_speed = max_speed;
	}

	void brake() override
	{
		current_speed -= 20;
		if (current_speed < 0)
			current_speed = 0;
	}
};

class ArmyMachine : public Car
{
public:
	ArmyMachine() : Car(150, 10){}

	void accelerate() override
	{
		current_speed += acceleration;
		if (current_speed > max_speed)
			current_speed = max_speed;
	}

	void brake() override
	{
		current_speed -= 15;
		if (current_speed < 0)
			current_speed = 0;
	}
};

class BuggyCar : public Car
{
public:
	BuggyCar() : Car(190, 20){}

	void accelerate() override
	{
		current_speed += acceleration;
		if (current_speed > max_speed)
			current_speed = max_speed;
	}

	void brake() override
	{
		current_speed -= 15;
		if (current_speed < 0)
			current_speed = 0;
	}
};
