#pragma once
class TStrings {
private:
	std::string string1;
	std::string string2;
public:
	int answer;

	TStrings(std::string& str1, std::string& str2) {
		string1 = str1;
		string2 = str2;
	}

	int Options();
	void Restart();

	void AddLines();
	void EquateLines();
	void CompareLines();
	void BoSLines();

	void DublicateLine();
	void FindLine();

	~TStrings();
};
