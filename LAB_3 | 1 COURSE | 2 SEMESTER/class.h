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

	void AddStrings();
	void EquateStrings();
	void CompareStrings();
	void BMString();
	void IndexString();

	void DublicateString();
	void FindString();

	~TStrings();
};
