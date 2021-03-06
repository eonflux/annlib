#pragma once
#include <vector>
#include "PerceptronLayer.h"
#include "FeatureSet.h"
#include <atomic>

using namespace std;
template<typename T> class network
{
	//friend void PerceptronLayer<T>::setReadyFlag();
public:
	network(PerceptronLayer<T>& _initl) : _start(_initl)
	{
		//_count=0;
		//_currReady=0;
	}
	void addEndPoint(PerceptronLayer<T>& _endl)
	{
		//_end.push_back(_endl);
		//_endl.setNetwork((void*) this);
		_end.push_back(_endl.data());
	}
	void ready()
	{
		for(int i(0);i<_end.size();i++)
		{
			while (true)
			{
				if (_end.at(i)->isReady())
				{
					break;
				}
				this_thread::yield();
			}
		}

	}
private:
	PerceptronLayer<T>& _start;
	vector<PerceptronLayer<T>*> _end;
};
