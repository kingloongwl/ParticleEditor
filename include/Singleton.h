
#ifndef PARTICLEEDITOR_SINGLETON_H_
#define PARTICLEEDITOR_SINGLETON_H_

#define NULL 0

template <class T>
class Singleton
{
public:
	static T& getInstance()
	{
		if (Singleton<T>::_sInstance == NULL)
		{
			Singleton<T>::_sInstance = new T;
		}

		return *(Singleton<T>::_sInstance);
	}

	void release()
	{
		if ( Singleton<T>::_sInstance != NULL )
		{
			delete Singleton<T>::_sInstance;
			Singleton<T>::_sInstance = NULL;
		}
	}
	
private:

	static T*	_sInstance;
};

template<class T>
T* Singleton<T>::_sInstance = NULL;

#endif


