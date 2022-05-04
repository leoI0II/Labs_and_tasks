#include<iostream>
#include<list>
#include<string>
#include<vector>

int main()
{
	std::vector<std::pair<std::string, double>> vec;
	vec.push_back(std::pair<std::string, double>("apple", 1.23)); vec.push_back(std::pair<std::string, double>("banana", 2.1));

	using ht = std::list<std::pair<std::string, double>>;
	ht** hash = new ht*[2];
	for (size_t i = 0; i < 2; ++i){
		hash[i] = new ht;
		hash[i]->push_back(vec[i]);
	}

	for (int i = 0; i < 2; ++i){
		for (auto& list_elem: *hash[i])
			std::cout << list_elem.first << " costs " << list_elem.second << " dollars." << std::endl;
		delete hash[i];
	}

	delete [] hash;

	return 0;
}
