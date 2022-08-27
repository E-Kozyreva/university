#pragma once
class TStrings {
private:
	std::string string1;
	std::string string2;
	std::string *str1;
	std::string *str2;
	size_t s1 = strlen(string1.c_str());
	size_t s2 = strlen(string2.c_str());
public:
	TStrings(std::string& str1, std::string& str2);
	TStrings(const TStrings& other);

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
