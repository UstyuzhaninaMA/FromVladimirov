#include <stdio.h>
#include <fenv.h>
#include <string.h>
#include <stdlib.h>

int toDemicalSystem(float num, int start, int end)
{
	int res, intNum;

	res = 0;

	memcpy(&intNum, &num, sizeof(float));

	for(int i = start; i <= end; i++)
	{
		res += ((intNum >> i) & 1u) * (1u << (i - start));
	}
	return res;
}

int main(){
	float ch, zn;
	float ansUp, ansDown;
	int mantUp, fracUp, mantDown, fracDown;

	if (scanf("%f %f", &ch, &zn) != 2)
	{
		abort();
	}
	
	fesetround(FE_UPWARD);
	ansUp = ch/zn;

	fesetround(FE_DOWNWARD);
	ansDown = ch/zn;

	mantUp = toDemicalSystem(ansUp, 23, 30);
	fracUp = toDemicalSystem(ansUp, 0, 22);
	mantDown = toDemicalSystem(ansDown, 23, 30);
	fracDown = toDemicalSystem(ansDown, 0, 22);

	if((mantUp == mantDown) && (fracUp == fracDown))
	{
		printf("0x%x 0x%x\n", mantUp, fracUp);
		return 0;
	}


	printf("0x%x 0x%x 0x%x 0x%x\n", mantDown, fracDown, mantUp, fracUp);

	return 0;
}

