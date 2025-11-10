#include <iostream>


template<typename Type>
void UpArr(Type*& ptr, int & size, Type element);
template<typename Type>
void NewArr(Type*& ptr, int size);

void FillArr(int* ptr, int size);
void FillArr(double* ptr, int size);
void FillArr(float* ptr, int size);
void FillArr(std::string* ptr, int size);
void FillArr(char* ptr, int size);
template<typename Type>
void PrintArr(Type* ptr, int size);
template<typename Type>
void Delete(Type* ptr);

int main()
{
	int size = 5;

	char* ptr = new char[size];

	size = 6;
	NewArr(ptr, size);
	FillArr(ptr, size);

	PrintArr(ptr, size);

	std::cout << std::endl;

	UpArr(ptr, size, 'f');
	PrintArr(ptr, size);


	FillArr(ptr, size);

	Delete(ptr);
}

template<typename Type>
void UpArr(Type*& ptr, int &size, Type element)
{
	size++;
	Type* buf = new Type[size];
	for (size_t i = 0; i < size - 1; i++)
	{
		buf[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new Type[size];
	for (size_t i = 0; i < size - 1; i++)
	{
		ptr[i] = buf[i];
	}
	ptr[size - 1] = element;
	delete[] buf;
}
template<typename Type>
void NewArr(Type* &ptr, int size) //Немного не понял, что значит "распределение" памяти. Прочел и вроде это так должно выглядить 
{
	delete[] ptr;
	ptr = new Type[size];
}
template<typename Type>
void Delete(Type * ptr)
{
	delete[] ptr;
}
template<typename Type>
void PrintArr(Type* ptr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << ptr[i] << " ";
	}
}
void FillArr(int* ptr, int size) //Немного не понял, что значит "инициализация" памяти(и чем оно отличается от распределения). Прочел и вроде это так должно выглядить 
{
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = 0;
	}
}
void FillArr(double* ptr, int size) 
{
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = 0.0;
	}
}
void FillArr(float* ptr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = 0.0;
	}
}
void FillArr(std::string* ptr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = " ";
	}
}
void FillArr(char* ptr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = ' ';
	}
}
