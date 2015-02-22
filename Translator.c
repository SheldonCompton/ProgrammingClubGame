//(Sheldon)This is really just practice for when I end up writting a compiler
//(Sheldon)Feel free to modify and add to this.  I probably screwed some stuff up that needs to be changed anyway.
#include <stdio.h>

int main(){
			char input[100];
		
			while(1){
			puts("What would you like to translate to?");
			fgets(input,100,stdin); 	//(Sheldon)(string,max num of chars to copy,stream)
			int counter;			
			for(counter = 0;counter < 100;counter++){
				input[counter] = tolower(input[counter]); //(Sheldon)Convert char to lower case			
			}
			
			char m[11] = "morse code";			
			for(counter=0;counter<=10;counter++){
				if(input[counter]!=m[counter]){
					break;
				}
			}
			if(counter==10){
			Morse();
			continue;	//(Sheldon) skips rest testing and goes back to top of loop			
			}
			puts("failed");	//(Sheldon) this will later be replaced with a list of commands
			
		}
}

Morse(){
char input[1001];		//TODO: (Sheldon) look into how to make a variable global in c
puts("What would you like to translate?");
puts("Max 1000 characters");
fgets(input,1000,stdin);
int counter;
int counter2;
for(counter = 0;counter < 100;counter++){
	input[counter] = tolower(input[counter]); 			
}
char buffer[5001];	//(Sheldon)0 in morse code is 5 dashes which is its longest character
char tester;
int writingpoint=0;
for(counter=0;counter < 1000;counter++){
tester=0;
if(input[counter]==tester) break;
tester=97;	//(Sheldon)a in ascii
//(Sheldon)get ready for the ugliest block of code ever
if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='-';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='-';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='-';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='-';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='.';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='.';;writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='.';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='-';buffer[++writingpoint]='-';writingpoint++;}
tester++;
else if(input[counter]==tester){buffer[writingpoint]='-';buffer[++writingpoint]='-';buffer[++writingpoint]='.';buffer[++writingpoint]='.';writingpoint++;}
}
printf("%s\n",buffer);
for(counter=0;counter<5001;counter++){
buffer[counter]=0;	
}
}
