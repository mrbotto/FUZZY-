#include "YourOp.hpp"
#include "AlphaLevelFuzzy.hpp"

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{

	AlphaLevelFuzzy a,b,c;
	YourOp testOp ;
	a.Triang2AlphaLevel(1,2,3);
	b.Triang2AlphaLevel(4,5,6);
        

	testOp.setOp1(a);
	testOp.setOp2(b);
        testOp.run();
        c = testOp.getResult();
        c.print();
        
	return 0;
}
//---------------------------------------------------------------------------
