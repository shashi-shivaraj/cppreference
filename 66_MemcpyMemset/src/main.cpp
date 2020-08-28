#include <iostream>
#include <cstring>

//memcpy(*dest, *src, sizeInBytes);
//memset(*dest,val,sizeInBytes);

typedef struct node
{
	unsigned int isValid : 1; //indicates size in bits
	unsigned int size :15;
	struct node* next;
} node_t;

int main()
{
	node_t n = {1,222,nullptr};
	std::cout<<"sizeof(node_t) = "<<sizeof(node_t)<<std::endl; // 8 = 4 bytes for 1 bit isValid, 15 bits size + 4 bytes for pointer. 
	std::cout<<"n = "<<n.isValid<<", "<<n.size<<", "<<n.next<<std::endl;

	node_t n2;
	n2 = n;
	std::cout<<"n2 = "<<n2.isValid<<", "<<n2.size<<", "<<n2.next<<std::endl;

	node_t n3;
	std::memcpy(&n3,&n,sizeof(node_t));
	std::cout<<"n3 = "<<n3.isValid<<", "<<n3.size<<", "<<n3.next<<std::endl;

	const int size = 500; 
	const int offset = 10;
	unsigned char buffer[size];

	std::memset(buffer,0,size);
	node_t* temp = (node_t *)(buffer + offset);
	std::cout<<"tempBeforeMemcpyWithMemset = "<<temp->isValid<<", "<<temp->size<<", "<<temp->next<<std::endl;

	std::memcpy(buffer + offset,&n,sizeof(node_t));
	std::cout<<"tempAfterMemcpy = "<<temp->isValid<<", "<<temp->size<<", "<<temp->next<<std::endl;

	return 0;
}
