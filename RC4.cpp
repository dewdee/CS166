#include <iostream>
#include "RC4.h"

RC4::RC4(unsigned char key[], int keylen) {
	int i, j = 0;
	//initialize stream permutation 0,1,2,...255
	for (i = 0; i < 256; i++) {
		stream[i] = i;
	}
	for (i = 0; i < 256; i++) {
		j = (j + stream[i] + key[i % keylen]) % 256;
		swap(i, j);
	}
	std::cout << "i: " << std::dec << i << std::endl;
	std::cout << "j: " << std::dec << j << std::endl;
	print();
}

RC4::~RC4() {

}
void RC4::print() {
	int k = 0;
	std::cout << "[";
	for (int i = 0; i < 16; i++) {
		std::cout << "[";
		for (int j = 0; j < 16; j++) {
			std::cout << std::hex << (int)stream[k] << ' ';
			k++;
		}
		std::cout << "]" << std::endl;
	}
	std::cout << "]";
}
void RC4::prga() {
	int i = 0, j = 0;
	unsigned char temp;

	for (int k = 0; k < 1000; k++) {
		i = (i + 1) % 256;
		j = (j + stream[i]) % 256;
		swap(i, j);
		temp = (stream[i] + stream[j]) % 256;
		if (k == 99) {
			std::cout << "i: " << std::dec << i << std::endl;
			std::cout << "j: " << std::dec << j << std::endl;
			print();
		}
	}
	std::cout << "i: " << std::dec << i << std::endl;
	std::cout << "j: " << std::dec << j << std::endl;
	print();
}

void RC4::swap(int a, int b) {
	unsigned char temp = stream[a];
	stream[a] = stream[b];
	stream[b] = temp;
}

