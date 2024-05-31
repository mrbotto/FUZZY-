//---------------------------------------------------------------------------
#ifndef AlphaLevelFuzzyH
#define AlphaLevelFuzzyH   
//---------------------------------------------------------------------------
#define LN 11 //Default number of levels

struct datum {
	double mf; //Level of Memebership Function
	double lv; //Left alpha level Value
	double rv; //right alpha level Value
};


class AlphaLevelFuzzy {
	public:
		datum level[LN];

		AlphaLevelFuzzy();

		void Triang2AlphaLevel(double lmin, double max, double rmin);
		void Trap2AlphaLevel(double lmin, double lmax, double rmax, double rmin);
//		void Expo2AlphaLevel(...
//		void Sigma2AlphaLevel(...
//		void ReverseSigma2AlphaLevel(...

		void print();
		
		~AlphaLevelFuzzy() {}
};

#endif
