// matlabdlltest.cpp : �������̨Ӧ�ó������ڵ㡣
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
	mwArray y(1, 1, mxDOUBLE_CLASS);//�������IRIjisuanchengxu�л��޸ģ����Գ�ʼ����ʲô���С�
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

