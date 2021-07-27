matlab程序转c++ 64dll调试程序

IRIjisuanchengxu.dll是完整转换程序
IRIjisuanchengxu_test.dll 减少了入参



MATLAB R2016a 
VS2010



编译附加库目录
	D:\Program Files\MATLAB\R2016a\extern\include

编译附加库目录
D:\Program Files\MATLAB\MATLAB Runtime\v901\extern\lib\win64\microsoft

附加库
IRIjisuanchengxu.lib
mclmcrrt.lib




程序初始化
if (!mclmcrInitialize())
		return false;
	
	
if (!IRIjisuanchengxuInitialize())
	return false;


程序终止需要调用 IRIjisuanchengxuTerminate


