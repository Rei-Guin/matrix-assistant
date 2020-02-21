#include <stdio.h>
#include "utils.h"
#include <unistd.h>

int main(){
	int done = 0;
	int selection = 0;
	

	while(!done){
		displayMenu();
		selection = getIntInRange(0, 3);
		switch(selection){
			case 0:
				done = 1;
				break;

			case 1:
				execl("../scripts/login", "login", "vluong5", "matrix.senecac.on.ca", NULL); 
				break;

			case 2:
				execl("../scripts/at", "at", NULL); 
				break;

			case 3:
				execl("../scripts/ali", "ali", NULL); 
				break;

			default:
				printf("shouldn't be here");
				break;
		}
	}

    	return 0;
}
