// matlabdlltest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "IRIjisuanchengxu_test.h"
#include "IRIjisuanchengxu.h"

int _tmain(int argc, _TCHAR* argv[])
{
	if (!mclmcrInitialize())
		return false;
	
	
	if (!IRIjisuanchengxuInitialize())
		return false;

	mwArray a(2, 2, mxDOUBLE_CLASS);

	int nargout = 1;
	mwArray IRI_result;
	mwArray y(1, 1, mxDOUBLE_CLASS);//这个参数IRIjisuanchengxu中会修改，所以初始化成什么都行。
	mwArray dx(1, 1, mxDOUBLE_CLASS);
	dx(1,1)=0.25;
	std::cout << dx << std::endl;
	
	mwArray  v(1, 1, mxDOUBLE_CLASS);
	v(1,1) = 80.0;

	IRIjisuanchengxu(nargout, IRI_result,  y,  dx,  v);


	//IRIjisuanchengxu_test(1, IRI_result);
    std::cout << IRI_result << std::endl;
	return 0;
}

