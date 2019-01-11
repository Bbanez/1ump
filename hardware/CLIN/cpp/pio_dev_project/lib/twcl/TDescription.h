#ifndef TDescription_h
#define TDescription_h

// TMessage type value
const unsigned char UINT8	=	1;
const unsigned char UINT16	=	2;
const unsigned char UINT32	=	3;
const unsigned char INTEGER	=	4;
const unsigned char ULONG	=	5;
const unsigned char LONG	=	6;
const unsigned char FLOAT	=	7;
const unsigned char DOUBLE	=	8;
const unsigned char CHAR	=	9;
const unsigned char STRING	=	10;

// Positions
const unsigned char TYPE_POSITION	=	1;
const unsigned char NAME_POSITION	=	2;
const unsigned char VALUE1_POSTION	=	3;
const unsigned char VALUE2_POSITION =	4;

class TDescription	{
	public:
		TDescription();
		TDescription(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
		unsigned char get(unsigned char bytePosition);
		void get(unsigned char *bytes);
		void set(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
		void set(unsigned char *bytes);
		void set(unsigned long value);
		bool isSet();
	private:
		unsigned char b[4];
		bool created;
};

#endif