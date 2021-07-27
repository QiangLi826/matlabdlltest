% 高程数据以m为单位，第一个数据与第二个数据相差11m，程序运行需要几秒钟
function IRI_result = IRI( y,dx,v )
% Summary of this function goes here
%  此M文件是计算国际平整度指数的
%  IRI_result = IRI( y,dx,v )
%  输入变量意义如下：
%             dx  为路面高程采样间隔（m），默认为0.25m
%             y   为测量路段高程数据（m）
%             v   1/4车辆行驶速度（km/h），默认为80km/h
%  IRI_result为输出变量，为包含两个元素的数组，意义如下：
%             IRI_result(1)  为测量路段长度（m）
%             IRI_result(2)  为国际平整度指数（m/km)


%  IRI_XISHU Summary of this function goes here
%  Detailed explanation goes here
% 输出量：
%  st     4×4矩阵
%  pr     4×1矩阵

% 输入量：
%  dx     采样间隔（m）
%  v      1/4车辆行驶速度（km/h）
dx=0.25;                         %input('请输入采样间隔dx:');
v=80;                           %input('请输入1/4车辆行驶速度v:');
y=xlsread('yshuju.xlsx');

[ st,pr ] = IRI_xishu( dx,v );              % 调用计算系数矩阵的子函数IRI_xishu( dx,v )，计算系数矩阵，并将结果传递给矩阵st和pr，下面的计算中将用到矩阵st和pr

k=round(0.25/dx)+1;                         % k为中间参数，本行中的“round()”函数功能为：对一个数四舍五入求整       
if k<2                                      % 如果k小于2，k设为2
    k=2;            
end
bl=(k-1)*dx;
% kk=round(11/dx);                            % 从测量路段起点开始，离11m处最近的那个高程数据的序号（起点高程数据序号为1）
z1(1)=(y(2)-y(1))/11;                        % z1是一个一维数组，包含四个元素：z1(1),z1(2),z1(3),z1(4)；37～40行是对该数组元素赋初值
z1(2)=0;
z1(3)=z1(1);
z1(4)=0;
rs=0;                                       % 变量rs初值为0

kk=length(y)-k+1;                        % y为测量路段高程数据（m），函数“length(y)”是计算测量路段总的高程数据点数 
for i=1:kk                                  % 循环开始，对应的结束行是61行，此循环的内部还包括若干个子循环
    ixx=i;                                  % ixx为中间变量
    for ix=1:k                              % 46～49行是一个子循环，k就是31行求得的
        yy(ix)=y(ixx);
        ixx=ixx+1;
    end 
   
   if dx==0.1
       yp=((yy(k)+yy(k-1))/2-yy(1))/0.25;
   else
       yp=(yy(k)-yy(1))/bl;                    % bl由35行计算求得
   end
   
   disp(yp)
    for j=1:4                               % 51～56行是一个子循环，主要是计算z，z是一个一维数组，包含四个元素：z(1),z(2),z(3),z(4)，具体的数学表达式见“说明.DOC”文件的第六条
        z(j)=pr(j)*yp;
        for jj=1:4
            z(j)=z(j)+st(j,jj)*z1(jj);
        end
    end
    for j=1:4                               % 57～59行是一个子循环，主要是将数组z的各元素的值赋值给数组z1相应的元素
        z1(j)=z(j);
    end
    rs=rs+abs(z(1)-z(3));                   % 函数“abs()”是求绝对值
end
disp(rs)
IRI_result(1)=(length(y)-2)*dx;              % 计算测量路段的长度
IRI_result(2)=rs/kk*1000;                    % 计算国际平整度指数IRI
disp(length(y))
disp('计算结束');                           % 屏幕显示“计算结束”



function [ st,pr ] = IRI_xishu( dx,v )
k1=653;                                                       % 车辆参数，标准车辆取653，见“说明.DOC”文件的第一条
k2=63.3;                                                      % 车辆参数，标准车辆取63.3，见“说明.DOC”文件的第一条
u=0.15;                                                       % 车辆参数，标准车辆取0.15，见“说明.DOC”文件的第一条
c=6.00;                                                       % 车辆参数，标准车辆取6.00，见“说明.DOC”文件的第一条
A=[0,1,0,0;-k2,-c,k2,c;0,0,0,1;k2/u,c/u,-1*(k1+k2)/u,-c/u];   % 由车辆参数组成的4×4矩阵，见“说明.DOC”文件的第二条
B=[0;0;0;k1/u];                                               % 由车辆参数组成的4×1矩阵，见“说明.DOC”文件的第二条
I=[1,0,0,0;0,1,0,0;0,0,1,0;0,0,0,1];                          % 单位矩阵，见“说明.DOC”文件的第二条
dt=3.6*dx/v;                                                  % 计算路面高程的时间采样间隔dt（s），即车速为v时，车辆行驶dx距离所需的时间，单位为秒
st=expm(A*dt);                                                % 矩阵运算，见“说明.DOC”文件的第三条
disp(st);
AA=inv(A);                                                    % 求A矩阵的逆矩阵AA
SSTT=st-I;                                                    % 矩阵运算，见“说明.DOC”文件的第四条
pr=AA*SSTT*B;
disp(pr);



