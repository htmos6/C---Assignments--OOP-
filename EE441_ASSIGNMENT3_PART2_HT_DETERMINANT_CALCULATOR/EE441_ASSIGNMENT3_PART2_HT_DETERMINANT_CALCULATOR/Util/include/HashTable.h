#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Matrix.h"
#include "MatrixFunctions.h"
#include "HashTable.h"


class HT_Table
{
	public:
		HT_Item* ht_table[65536] = {NULL};
		int count = 0;

		HT_Table();
		~HT_Table();

		virtual bool key_exists(Matrix A);
		virtual long search(Matrix A);
		virtual void insert(Matrix A, long detA);
		virtual long determinantHT(Matrix matr, int sizeOfMatrix);
};


HT_Table::HT_Table()
{
	for (int i = 0; i < 65536; i++)
	{
		ht_table[i] = NULL;
	}
}


HT_Table::~HT_Table()
{
	for (int i = 0; i < 65536; i++)
	{
		if (ht_table[i] != NULL)
		{
			delete ht_table[i];
		}
	}
}

bool HT_Table::key_exists(Matrix A)
{
	unsigned long hashValue = A.hashCalculator();

	while (ht_table[hashValue] != NULL)
	{
		if (ht_table[hashValue]->key == A)
		{
			return 1;
		}
		else
		{
			hashValue = (hashValue + 1) % 65536;
		}
	}
	return 0;
}


long HT_Table::search(Matrix A)
{
	unsigned long hashValue = A.hashCalculator();

	while (ht_table[hashValue] != NULL)
	{
		if (ht_table[hashValue]->key == A)
		{
			return ht_table[hashValue]->value;
		}
		else
		{
			hashValue = (hashValue + 1) % 65536;
		}
	}
	return 0;
}


void HT_Table::insert(Matrix A, long detA)
{
	unsigned long hashValue = A.hashCalculator();

	while (ht_table[hashValue] != NULL)
	{
		hashValue = (hashValue + 1) % 65536;
	}

	if (count < 65536)
	{
		ht_table[hashValue] = new HT_Item();
		ht_table[hashValue]->key = A;
		ht_table[hashValue]->value = detA;
		count += 1;
	}
}


long HT_Table::determinantHT(Matrix matr, int sizeOfMatrix)
{
	Matrix temp_matr(sizeOfMatrix - 1);

	int i_sub_mtr = 0;
	int j_sub_mtr = 0;
	long det = 0;

	if (key_exists(matr))
	{
		return search(matr);
	}
	else if (sizeOfMatrix == 1)
	{
		long det = matr.getter(1, 1);
		insert(matr, det);
		return det;
	}
	else
	{
		for (int i = 0; i < sizeOfMatrix; i++)
		{
			i_sub_mtr = 0;
			for (int j = 1; j < sizeOfMatrix; j++)
			{
				int j_sub_mtr = 0;
				for (int k = 0; k < sizeOfMatrix; k++)
				{
					if (k == i) // If closed column and travelling column are meet, pass current loop.
					{
						continue;
					}
					temp_matr.setter(i_sub_mtr + 1, j_sub_mtr + 1, matr.getter(j + 1, k + 1)); // Give index values as incremented by 1. Since minimum number of row || column number should be 1.
					j_sub_mtr += 1;
				}
				i_sub_mtr += 1;
			}
			det += (long)(determinantHT(temp_matr, sizeOfMatrix - 1) * matr.getter(1, i + 1) * pow(-1, i));
		}
		this->insert(matr, det);
		return det;
	}
}

#endif
