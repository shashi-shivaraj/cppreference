#include <iostream>

typedef struct node
{
	unsigned int isValid;
	unsigned int size;
	struct node* next;
} node_t;

int main()
{
	node_t *nodes = new node_t[10];

	std::cout<<"sizeof(node_t) in bytes = "<<sizeof(node_t)<<std::endl; //12 bytes
	std::cout<<"First Node Address = "<<nodes<<std::endl;
	std::cout<<"thrid Node Address = "<<nodes+2<<std::endl; //1st Node + 2 * 12 bytes 

	delete [] nodes;

	return 0;
}
