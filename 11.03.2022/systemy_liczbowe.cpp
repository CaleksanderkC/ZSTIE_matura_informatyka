#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::string dec_to_bin(int n) {
	
	std::string out;
	while (n) {
		out += (n%2) + '0';
		n /= 2;	
	}
	int s = out.size();
	for (int i=0; i < s/2; ++i)	{
		std::swap(out[i], out[s-1-i]);	
	}
	
	return out;
}



std::vector<int> from_dec(int n, int sys) {
	
	std::vector<int> out;
	while (n) {
		out.push_back(n%sys);
		n /= sys;
	}

	int s = out.size();
	for (int i=0; i < s/2; ++i)	{
		std::swap(out[i], out[s-1-i]);	
	}
	
	return out;
}



int to_dec(std::vector<int> n, int sys) {
	
	int out = 0;
	for(int i=0; i< n.size(); ++i) {
		out += std::pow(sys, i) * n[n.size()-i-1];
	}
	
	return out;
}


int main (){
	int number = 20;
	int system = 16;
	
	std::vector<int> w = from_dec(number, system);
	
	for (int i=0; i< w.size(); ++i)
	{
		std::cout << w[i] << " ";
	}
	
	std::cout << std::endl;
	
	std::cout  << to_dec(w, system) << std::endl;
}
