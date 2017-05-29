#pragma once
#ifndef RC4_H
#define RC4_H

class RC4 {
public:
	RC4(unsigned char key[], int keylen);
	~RC4();
	void prga();
	void print();

	unsigned char stream[256];
private:
	void swap(int a, int b);
	
};

#endif