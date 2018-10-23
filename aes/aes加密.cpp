#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include "openssl/aes.h"
#include <fstream>
#define  maxNameLength 50
#define   bufferLength     16
#pragma comment(lib,"libcrypto.lib")
using namespace std;

char  inFileName[maxNameLength];
char  outFileName[maxNameLength];
ifstream infileStream;
ofstream outfileStream;

int main(int argc, char* argv[])
{
	// ׼��32�ֽ�(256λ)��AES�����ֽ�
	unsigned char aes_keybuf[32];
	AES_KEY aeskey;
	memset(aes_keybuf, 0x00, sizeof(aes_keybuf));
	memcpy(aes_keybuf, "0123456789abcdef0123456789abcdef", AES_BLOCK_SIZE);
	AES_set_encrypt_key(aes_keybuf, 256, &aeskey);

	//���ļ�
	
	strcpy_s(inFileName, "C:\\Users\\Zmore\\Desktop\\new.txt");
	strcpy_s(outFileName, "C:\\Users\\Zmore\\Desktop\\z.enc");
	infileStream.open(inFileName, ifstream::binary | ifstream::in);//�����ƴ�
	outfileStream.open(outFileName, ofstream::out | ofstream::binary);

	if (!infileStream.is_open())
	{
		cout << "�ļ��򿪳���" << endl;
		return 0;
	}

	while (!infileStream.eof())
	{
		unsigned char buf[bufferLength];
		unsigned char buf2[bufferLength];
		memset(buf, 0, 16);
		memset(buf2, 0, 16);
		infileStream.read((char *)buf, bufferLength);

		int inCount = infileStream.gcount();//ͳ�ƶ�ȡ�����ַ���
		if (inCount == bufferLength)
		{
			AES_encrypt(buf, buf2, &aeskey);
			outfileStream.write((char *)buf2, bufferLength);
			//outfileStream.put(inCount);

		}
		else
		{
			outfileStream.write((char *)buf, inCount);
		}

	}
	infileStream.close();
	outfileStream.close();
		


		
	return 0;
}