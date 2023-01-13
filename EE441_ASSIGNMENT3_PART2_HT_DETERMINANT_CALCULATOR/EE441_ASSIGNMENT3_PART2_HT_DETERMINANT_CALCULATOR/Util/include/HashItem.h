#ifndef HASHITEM_H
#define HASHITEM_H

#include "Matrix.h"
#include "MatrixFunctions.h"

class HT_Item
{
	public:
		Matrix key;
		long value;
		HT_Item() : key(), value(0) {};
};

#endif
