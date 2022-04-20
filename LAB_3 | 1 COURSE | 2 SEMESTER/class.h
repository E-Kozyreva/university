#pragma once
class TStrings {
private:
	std::string string1;
	std::string string2;
public:
	int answer;
	std::string string;

	TStrings(std::string& str1, std::string& str2) {
		string1 = str1;
		string2 = str2;
	}

	int SelectString();

	void AddStrings();
	void EquateStrings();
	void CompareStrings();
	void BMString();
	void IndexString();

	void DublicateString();
	void FindString();
	void CountString();
	void SymbolsInString();
	void CountSymbolsInString();

	~TStrings();
};
