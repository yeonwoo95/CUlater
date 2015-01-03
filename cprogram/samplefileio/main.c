#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* fileText;			//file handling object
	char filename[1024];	//string to save filename
	char lineRead[1024];	//string to save each line of the file
	int i;					//line counter

	printf("use filename \"this.txt\" to test\n");
	printf("Input filename: ");
	scanf("%s",filename);	//read filename from user

	printf("Opening file: %s\n\n",filename);
	fileText = fopen(filename,"r");		//open file and handle with fileText object

	if(fileText==NULL){					//if file could not be opened, print error on the screen
		printf("Error opening the file\n");
		return 0;
	}

	i = 0;					//set i to 0
	while( fgets(lineRead,1024,fileText) ){		//if line is not NULL, print the line and loop to next line
		i++;				//count lines
		printf("%d\t%s",i,lineRead);
        printf("\tAscii:\t");

		int j=0;
		while (lineRead[j]){
			printf("%4d ",lineRead[j++]);
			if(j%5==0&&j!=0){
				printf("\n\t\t");
			}
		}

		printf("\n");
	}

	printf("\n\n# of lines: %d\n",i);

	fclose(fileText);		//close the file before the program terminates

	return 0;
}

/* save your textfile to CUlater\cprogram\samplefileio\ to make sure the program works properly */
