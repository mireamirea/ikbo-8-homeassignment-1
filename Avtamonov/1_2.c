#include <stdio.h>


int main(){

	char str[255];
	char smbl[255];
	char answr;
	int i = 0, y = 0, j = 0;
	
	while(1){
	
		printf("Enter some symbols\n");
	
		scanf("%s", &str);
	
		printf("enter a element\n");
	
		scanf("%s", &smbl);
	
		while (str[i] != '\0')
		{
			y = 0;
			
			while (1)
			{	
				if (smbl[y] == '\0') 
				{
					printf("%d->%d \n", i + 1, i + y);
					break;
					
				} else if (smbl[y] != str[i + y])
					break;
					
				y++;
			}
			
			i++;
		}
	
	
		printf("continue?(Y/N)\n");
		scanf("%s", &answr);
		
		if(answr == 'y' || answr == 'Y')
			continue;
		else
			break;
	}
	
	return 0;
}
