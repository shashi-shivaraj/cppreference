 #include <iostream>

 struct Player
 {
	 int x_pos,y_pos;
	 int speed;

	 void move(int x, int y)
	 {
		 x_pos += x * speed;
		 y_pos += y * speed;

		 move_count++;
	 }

	private:
		int move_count;

 };

 struct vect
 {
	 int x;
	 int y;
	 int z;

	 void add(const vect& other)
	 {
		 x += other.x;
		 y += other.y;
		 z += other.z;
	 }
 };

int main()
{	
	Player player;
	player.x_pos = 5;
	player.y_pos = 10;
	player.speed = 2;

	player.move(1,1);

	std::cout<<"Position = ( "<< player.x_pos << ", "<<player.y_pos<<" )"<<std::endl;
	std::cout<<"Speed = "<< player.speed <<std::endl;
	//std::cout<<" Move count =  "<<player.move_count<<std::endl;

	return 0;
}