#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

struct pereche
{
	bool operator()(const pair<string, int>& a, const pair<string, int>& b) const
	{
		if (a.second != b.second)
		{
			return a.second < b.second;
		}
		else
		{
			return a.first > b.first;
		}
	}
};

vector<string> separaCuvinte(const string& sir)
{
	vector<string> words;
	string cuvant;
	for (char caracter : sir)
	{
		if (caracter == ' ' ||
			caracter == ',' ||
			caracter == '.' ||
			caracter == '!' ||
			caracter == '?')
		{
			if (!cuvant.empty())
			{
				words.push_back(cuvant);
				cuvant.clear();
			}
		}
		else
		{
			cuvant += tolower(caracter);
		}
	}
	if (!cuvant.empty())
	{
		words.push_back(cuvant);
	}
	return words;
}


int main()
{
	fstream fis;
	fis.open("input.txt", ios::in);
	if (!fis.is_open())
	{
		cout << "Nu se poate deschide fisierul";
		return 1;
	}

	string propozitie;
	map<string, int> dictionar;

	while (getline(fis, propozitie))
	{
		for (auto& cuvant : separaCuvinte(propozitie))
		{
			++dictionar[cuvant];
		}
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, pereche> pq;

	for (const auto& it : dictionar)
	{
		pq.push(make_pair(it.first, it.second));
	}

	while (!pq.empty())
	{
		cout << pq.top().first << " => " << pq.top().second << '\n';
		pq.pop();
	}

	fis.close();
	return 0;
}