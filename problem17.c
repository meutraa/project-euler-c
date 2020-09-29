#include <stdio.h>
#include <math.h>

int numbers[9] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
int hundred = 7;
int and = 3;
int thousand = 8;
int special[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int tens[] = {3, 6, 6, 5, 5, 5, 7, 6, 6};

int main()
{
	int i, j;
	int count = 0;
	for(i = 1; i <= 1000; i++)
	{
		// x thousand
		if(i >= 1000)
		{
			count = count + numbers[0] + thousand;
		}
		// x hundred
		else if(i >= 900) count += numbers[8];
		else if(i >= 800) count += numbers[7];
		else if(i >= 700) count += numbers[6];
		else if(i >= 600) count += numbers[5];
		else if(i >= 500) count += numbers[4];
		else if(i >= 400) count += numbers[3];
		else if(i >= 300) count += numbers[2];
		else if(i >= 200) count += numbers[1];
		else if(i >= 100) count += numbers[0];
		if(count >= 100) count += hundred;

		j = i;
		while(j >= 100) j -= 100;
		
		// and
		if(i % 100 != 0 && i >= 100) count += and;
		
		// ninety
		if(j >= 90) count += tens[8];
		else if(j >= 80) count += tens[7];
		else if(j >= 70) count += tens[6];
		else if(j >= 60) count += tens[5];
		else if(j >= 50) count += tens[4];
		else if(j >= 40) count += tens[3];
		else if(j >= 30) count += tens[2];
		else if(j >= 20) count += tens[1];
		else if(j >= 10)
		{
			count += special[j - 10];
		}
		if(j > 20 || j < 10)
		{
			while(j >= 10) j -= 10;
			if(j != 0) count += numbers[j - 1];
		}
	}
	printf("%d\n", count);
	return 0;
}
