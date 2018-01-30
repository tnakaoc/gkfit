#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
struct data_t
{
	double value;
	double buf[9];
};
#define CREAT_OP(op) \
bool operator op (const data_t& lhs,const data_t& rhs) \
{ \
	return lhs.value op rhs.value; \
}
CREAT_OP(< )
CREAT_OP(> )
CREAT_OP(<=)
CREAT_OP(>=)
CREAT_OP(==)
CREAT_OP(!=)
#undef CREAT_OP
int main(int argc,char* argv[])
{
	if(argc==2 && argv[1][0]=='-' && argv[1][1]=='h')
	{
		printf("usage: %s ([opt])\n",argv[0]);
		printf("OPTIONS:\n");
		printf("\t-v : verbose mode\n");
		printf("\t-h : print this\n");
		return 0;
	}
	const double E[]=
	{
		 1.00000E-03 ,1.50000E-03 ,2.00000E-03 ,3.00000E-03
		,4.00000E-03 ,5.00000E-03 ,6.00000E-03 ,8.00000E-03
		,1.00000E-02 ,1.50000E-02 ,2.00000E-02 ,3.00000E-02
		,4.00000E-02 ,5.00000E-02 ,6.00000E-02 ,8.00000E-02
		,1.00000E-01 ,1.50000E-01 ,2.00000E-01 ,3.00000E-01
		,4.00000E-01 ,5.00000E-01 ,6.00000E-01 ,8.00000E-01
		,1.00000E+00 ,1.25000E+00 ,1.50000E+00 ,2.00000E+00
		,3.00000E+00 ,4.00000E+00 ,5.00000E+00 ,6.00000E+00
		,8.00000E+00 ,1.00000E+01 ,1.50000E+01 ,2.00000E+01
	};
	const char* el_name[]=
	{
		"H","C","N","O","Na","P","S","Cl","K"
	};
	const size_t Ne=sizeof(E)/sizeof(double);
	const size_t Nn=sizeof(el_name)/sizeof(char*);
	const double sum[Ne]=
	{
		 3.7010E+03 ,1.2470E+03 ,5.5770E+02 ,1.8190E+02
		,8.0300E+01 ,4.1350E+01 ,2.3890E+01 ,9.9350E+00
		,4.9870E+00 ,1.4020E+00 ,5.6630E-01 ,1.6160E-01
		,7.2160E-02 ,4.3600E-02 ,3.2640E-02 ,2.6170E-02
		,2.5450E-02 ,2.7450E-02 ,2.9420E-02 ,3.1640E-02
		,3.2490E-02 ,3.2690E-02 ,3.2540E-02 ,3.1760E-02
		,3.0740E-02 ,2.9380E-02 ,2.8070E-02 ,2.5830E-02
		,2.2590E-02 ,2.0450E-02 ,1.8950E-02 ,1.7860E-02
		,1.6390E-02 ,1.5470E-02 ,1.4220E-02 ,1.3620E-02
	};
	const double v[Nn][Ne]=
	{
		{ // H
			 6.820E+00 ,1.752E+00 ,6.643E-01 ,1.693E-01
			,6.549E-02 ,3.278E-02 ,1.996E-02 ,1.160E-02
			,9.849E-03 ,1.102E-02 ,1.355E-02 ,1.863E-02
			,2.315E-02 ,2.709E-02 ,3.053E-02 ,3.620E-02
			,4.063E-02 ,4.813E-02 ,5.254E-02 ,5.695E-02
			,5.860E-02 ,5.900E-02 ,5.875E-02 ,5.739E-02
			,5.556E-02 ,5.311E-02 ,5.075E-02 ,4.650E-02
			,3.992E-02 ,3.523E-02 ,3.174E-02 ,2.905E-02
			,2.515E-02 ,2.247E-02 ,1.837E-02 ,1.606E-02
		},{ // C
			 2.209E+03 ,6.990E+02 ,3.016E+02 ,8.963E+01
			,3.723E+01 ,1.866E+01 ,1.054E+01 ,4.242E+00
			,2.078E+00 ,5.627E-01 ,2.238E-01 ,6.614E-02
			,3.343E-02 ,2.397E-02 ,2.098E-02 ,2.037E-02
			,2.147E-02 ,2.449E-02 ,2.655E-02 ,2.870E-02
			,2.950E-02 ,2.969E-02 ,2.956E-02 ,2.885E-02
			,2.792E-02 ,2.669E-02 ,2.551E-02 ,2.345E-02
			,2.048E-02 ,1.849E-02 ,1.710E-02 ,1.607E-02
			,1.468E-02 ,1.380E-02 ,1.258E-02 ,1.198E-02
		},{ // N
			 3.306E+03 ,1.080E+03 ,4.755E+02 ,1.447E+02
			,6.094E+01 ,3.086E+01 ,1.759E+01 ,7.170E+00
			,3.545E+00 ,9.715E-01 ,3.867E-01 ,1.099E-01
			,5.051E-02 ,3.217E-02 ,2.548E-02 ,2.211E-02
			,2.231E-02 ,2.472E-02 ,2.665E-02 ,2.873E-02
			,2.952E-02 ,2.969E-02 ,2.956E-02 ,2.886E-02
			,2.792E-02 ,2.669E-02 ,2.550E-02 ,2.347E-02
			,2.057E-02 ,1.867E-02 ,1.734E-02 ,1.639E-02
			,1.512E-02 ,1.434E-02 ,1.332E-02 ,1.285E-02
		},{ // O
		 	 4.576E+03 ,1.545E+03 ,6.926E+02 ,2.158E+02
			,9.221E+01 ,4.715E+01 ,2.708E+01 ,1.116E+01
			,5.565E+00 ,1.545E+00 ,6.179E-01 ,1.729E-01
			,7.530E-02 ,4.414E-02 ,3.207E-02 ,2.468E-02
			,2.355E-02 ,2.506E-02 ,2.679E-02 ,2.877E-02
			,2.953E-02 ,2.971E-02 ,2.957E-02 ,2.887E-02
			,2.794E-02 ,2.669E-02 ,2.551E-02 ,2.350E-02
			,2.066E-02 ,1.882E-02 ,1.757E-02 ,1.668E-02
			,1.553E-02 ,1.483E-02 ,1.396E-02 ,1.360E-02
		},{ // Na
		 	 6.522E+02 ,3.151E+03 ,1.504E+03 ,5.023E+02
			,2.238E+02 ,1.178E+02 ,6.915E+01 ,2.941E+01
			,1.499E+01 ,4.313E+00 ,1.759E+00 ,4.928E-01
			,2.031E-01 ,1.063E-01 ,6.625E-02 ,3.761E-02
			,2.931E-02 ,2.579E-02 ,2.635E-02 ,2.771E-02
			,2.833E-02 ,2.845E-02 ,2.830E-02 ,2.760E-02
			,2.669E-02 ,2.549E-02 ,2.437E-02 ,2.249E-02
			,1.997E-02 ,1.842E-02 ,1.743E-02 ,1.675E-02
			,1.595E-02 ,1.552E-02 ,1.508E-02 ,1.496E-02
		},{ // P
		 	 1.910E+03 ,6.522E+02 ,2.996E+02 ,1.074E+03
			,5.079E+02 ,2.782E+02 ,1.682E+02 ,7.457E+01
			,3.912E+01 ,1.179E+01 ,4.939E+00 ,1.422E+00
			,5.850E-01 ,2.965E-01 ,1.735E-01 ,8.083E-02
			,5.068E-02 ,3.188E-02 ,2.899E-02 ,2.870E-02
			,2.892E-02 ,2.891E-02 ,2.869E-02 ,2.793E-02
			,2.698E-02 ,2.575E-02 ,2.462E-02 ,2.279E-02
			,2.049E-02 ,1.921E-02 ,1.846E-02 ,1.801E-02
			,1.760E-02 ,1.747E-02 ,1.754E-02 ,1.771E-02
		},{ // S
		 	 2.426E+03 ,8.314E+02 ,3.828E+02 ,1.265E+03
			,6.066E+02 ,3.360E+02 ,2.046E+02 ,9.171E+01
			,4.847E+01 ,1.477E+01 ,6.235E+00 ,1.809E+00
			,7.466E-01 ,3.779E-01 ,2.199E-01 ,1.000E-01
			,6.052E-02 ,3.516E-02 ,3.080E-02 ,2.983E-02
			,2.991E-02 ,2.984E-02 ,2.959E-02 ,2.878E-02
			,2.780E-02 ,2.652E-02 ,2.535E-02 ,2.349E-02
			,2.118E-02 ,1.993E-02 ,1.923E-02 ,1.884E-02
			,1.850E-02 ,1.845E-02 ,1.864E-02 ,1.889E-02
		},{ // Cl
		 	 2.829E+03 ,9.742E+02 ,4.494E+02 ,1.361E+03
			,6.626E+02 ,3.711E+02 ,2.282E+02 ,1.034E+02
			,5.510E+01 ,1.700E+01 ,7.227E+00 ,2.114E+00
			,8.756E-01 ,4.433E-01 ,2.570E-01 ,1.148E-01
			,6.745E-02 ,3.639E-02 ,3.067E-02 ,2.898E-02
			,2.887E-02 ,2.874E-02 ,2.847E-02 ,2.767E-02
			,2.671E-02 ,2.549E-02 ,2.436E-02 ,2.258E-02
			,2.043E-02 ,1.931E-02 ,1.871E-02 ,1.839E-02
			,1.819E-02 ,1.824E-02 ,1.861E-02 ,1.899E-02
		},{ // K
		 	 4.053E+03 ,1.415E+03 ,6.563E+02 ,2.174E+02
			,8.304E+02 ,4.752E+02 ,2.974E+02 ,1.383E+02
			,7.490E+01 ,2.370E+01 ,1.023E+01 ,3.045E+00
			,1.272E+00 ,6.454E-01 ,3.730E-01 ,1.628E-01
			,9.161E-02 ,4.346E-02 ,3.378E-02 ,3.015E-02
			,2.959E-02 ,2.929E-02 ,2.895E-02 ,2.807E-02
			,2.707E-02 ,2.581E-02 ,2.467E-02 ,2.290E-02
			,2.084E-02 ,1.985E-02 ,1.935E-02 ,1.914E-02
			,1.910E-02 ,1.928E-02 ,1.983E-02 ,2.029E-02
		}
	};
	double a[Nn]{10.5,25.6,2.7,60.2,0.1,0.2,0.3,0.2,0.2};
	double a0[Nn]{10.5,25.6,2.7,60.2,0.1,0.2,0.3,0.2,0.2};
	bool verbose=(argc>1&&argv[1][0]=='-'&&argv[1][1]=='v');
	for(size_t i=0;i<Nn;++i) a[i]=0.;
	auto diff=[&](void)->double{
		double ret{0.};
		for(size_t i=0;i<Ne;++i)
		{
			double tsum{0.};
			for(size_t j=0;j<Nn;++j)
			{
				tsum+=a[j]*v[j][i];
			}
			double tmp=(tsum-sum[i])/sum[i];
			ret+=(tmp*tmp);
		}
		return sqrt(ret);
	};
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_real_distribution<> dist(-1,1.);
	double width=0.2;
	auto gen_a=[&](void){
		double tsum{0.};
		for(size_t i=0;i<Nn;++i)
		{
			a[i]=(1+width*dist(engine))*a0[i];
			tsum+=a[i];
		}
		tsum=1./tsum;
		for(size_t i=0;i<Nn;++i) a[i]*=tsum;
	};
	auto print_a=[&](void){
		for(auto v:a) printf("%lf\t",v);
		printf("\n");
	};
	std::vector<data_t> buffer;
	const size_t TR=200;
	const size_t BN=30;
	for(size_t k=0;k<BN;++k)
	{
		for(size_t i=0;i<TR;++i)
		{
			gen_a();
			if (verbose) print_a();
			data_t data;
			data.value=diff();
			memcpy(data.buf,a,sizeof(a));
			buffer.push_back(data);
		}
		width*=0.8;
		std::sort(buffer.begin(),buffer.end());
		memcpy(a,buffer[0].buf,sizeof(a));
		buffer.clear();
		memcpy(a0,a,sizeof(a));
	}
	printf("# Final result\n");
	printf("# %zu times binary estimate trials.\n",BN);
	printf("# %zu times random trials by every estimate.\n",TR);
	printf("# \n");
	for(size_t i=0;i<Nn;++i)
	{
		printf("# %s\t %lf\n",el_name[i],a[i]);
	}
	printf("# \n");
	printf("# [E]\t[input]\t[fitval]\n");
	for(size_t i=0;i<Ne;++i)
	{
		double tsum{0.};
		for(size_t j=0;j<Nn;++j)
		{
			tsum+=a[j]*v[j][i];
		}
		printf("%e\t%e\t%e\n",E[i],sum[i],tsum);
	}
	return 0;
}
