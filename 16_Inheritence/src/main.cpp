#include <iostream>

class Entity
{
	public:
		int x_pos, y_pos;

		void move(const int& x, const int& y)
		{
			x_pos += x;
			y_pos += y;
		}
};

class Player : public Entity 
{
	public:
		const char * name;

		void PrintName()
		{
			std::cout<<"Player name = "<<name<<std::endl;
		}
};

int main()
{
	Player player;
	player.x_pos = 1;
	player.y_pos = 2;
	player.name = "inherited";
	player.PrintName();
	player.move(2,2);

	std::cout<<"Size of Entity = "<<sizeof(Entity)<<std::endl;
	std::cout<<"Size of Player = "<<sizeof(Player)<<std::endl;

	return 0;
}