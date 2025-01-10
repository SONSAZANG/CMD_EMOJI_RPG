#pragma once

template <typename T>
class SingletonBase
{
private:
	static T* instance;

public:
	static T* GetInstance()
	{
		if (!instance)
		{
			instance = new T;
		}
		return instance;
	}

	static void DeleteInstance()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}

protected:
	SingletonBase() {}
	virtual ~SingletonBase() {}

public:
	SingletonBase(const SingletonBase&) = delete;
	SingletonBase& operator = (const SingletonBase&) = delete;
};

template <typename T>
T* SingletonBase<T>::instance = nullptr;