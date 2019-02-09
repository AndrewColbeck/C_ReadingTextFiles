#include <stdio.h>
#include <stdlib.h>

//Define global constants, files speed and output:
#define speedfile "speed.txt"
#define outputfile "output.txt"

int main()
{
	//Define file pointers:
	FILE *fp1;
	FILE *fp2;
	int count=0, i;
	float time=0, speed=0, max=0, min=1000, total, avg=0;

	//for loop for count
	//Assign pointers to files:
	fp1 = fopen (speedfile, "r");
	fp2 = fopen (outputfile, "w");

	//Return An error if unable to open file, else begin Program:
	if (fp1 == NULL)
		printf("Error opening input file\n");
	else{

		//Check number of sensor readings, assign to count:
		fscanf (fp1, "%i", &count);
		printf("Sensor Readings: %i\n", count);

		for (i=0; i<count; i++){
			fscanf (fp1, "%f %f", &time, &speed);

			//Find the maximum value
			if (max<speed)
				max=speed;

			//Find the minimum value
			if (min>speed)
				min=speed;

			//Find the total
			total+=speed;
		}

		//Calculate the Average Speed:
		avg=total/count;

	}

	//Opens the Output File and prints the final values:
	fprintf(fp2, "Number of Sensor Readings: \t\t%i\n", count);
	fprintf(fp2, "average reading is:\t\t\t%f\n", avg);
	fprintf(fp2, "maximum reading:\t\t\t%f\n", max);
	fprintf(fp2, "minimum reading:\t\t\t%f\n", min);

	int fclose(FILE *fp1);
	int fclose(FILE *fp2);


	return 0;
}