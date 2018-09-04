#ifndef TAddress_h
#define TAddress_h

class TAddress	{
	public:
		TAddress();
		TAddress(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
		void get(unsigned char *byteArray);
		unsigned long get();
		unsigned char get(unsigned char bytePosition);
		void set(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
		void set(unsigned long address);
		void set(unsigned char bytePosition, unsigned char value);
		bool isSet();
	private:
		unsigned long addr;
		bool created;
};

#endif