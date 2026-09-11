#include <vector>
#include <iostream>
#include <thread>

using namespace std;

struct Counter{
	int value;
	Counter():value(0){}
	void increment(){
		++value;
		}
	};
	
int main(){
	Counter counter;
	vector<thread> mythreads;

	for(int i=0; i<10; ++i) 
	{
		mythreads.push_back(thread([&counter](){
			for(int i=0; i<5000; ++i)
			{
				counter.increment();
			}
		}));
	}
	for(auto & thread : mythreads)
	{
		thread.join();
	}
	cout << counter.value << endl;
	return 0;
}
