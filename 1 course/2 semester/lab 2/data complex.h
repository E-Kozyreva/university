class TComplex {
private:
	double ActualPart1, ImaginaryPart1;
	double ActualPart2, ImaginaryPart2;
public:
	TComplex (double a1, double e1, double a2, double e2) {
		ActualPart1 = a1;
		ImaginaryPart1 = e1;
		ActualPart2 = a2;
		ImaginaryPart2 = e2;
	}
	void Output(double ActualPart, double ImaginaryPart);

	void AdditionComplex();
	void SubtractionComplex();
	void MultiplicationComplex();
	void DivisionComplex();
	void AssignmentComplex();
	void ComparisonComplex();

	void ModuleComplex();
	void PowerPComplex();
	void PowerMComplex();
	void PowerDComplex();
	void PowerCComplex();
	void TrigonometricComplex();

	~TComplex();
};
