#include <iostream>

//return_type oprator'*'(params) const{}
//std::ostream operator<<(std::ostream& stream, param){return stream;}

struct Vector2
{
	float x, y;

	Vector2(const float& x, const float& y):x(x),y(y)
	{}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}
	
	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	bool operator==(const Vector2& other) const
	{
		return (x == other.x && y == other.y);
	}

	bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream <<" ( "<< other.x << ", "<<other.y <<" )";
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));
	Vector2 result2 = position + speed * powerup;

	std::cout<<"result 1 = "<< result1 <<std::endl;
	std::cout<<"result 2 = "<< result2 <<std::endl;

	if(result1 == result2)
	{
		std::cout<<"Results match" <<std::endl;
	}

	if(result1 != position)
	{
		std::cout<<"vectors don't match" <<std::endl;
	}

	return 0;
}
