//idiots turing machine
#include <stdio.h> 
#include <conio.h>

int main(int argc, char** argv){
	FILE * file;
	file = fopen (argv[1], "r");
	char code[90];
	int tape[1024];
	int aa;
	int ac;
	int pointer = 1;
	int index = 0;
	int cicle = 0;
	fgets(code, 90, file);
	if (file == NULL){
		return 1;
	} else{
	while (1){
		if (code[index] == '>'){
			pointer++;
		} if (code[index] == '<'){
			pointer--;
		} if (code[index] == '+'){
			if (tape[pointer] > 255){
			tape[pointer] = 0;
			} else {
				tape[pointer] = tape[pointer] + 1;
			}
		} if (code[index] == '-'){
			if (tape[pointer] > 0){
			tape[pointer]--;
			} else {
				tape[pointer] = 256;
			}
		} if (code[index] == '.'){
			printf("%c", tape[pointer]);
		} if (code[index] == ':'){
			printf("%d \n", tape[pointer]);
		} if (code[index] == ','){
			aa=getchar();
			tape[pointer] = (int)aa;
		}  if (code[index] == 'x'){
			break;
		} if (code[index] == '*'){
			if (tape[pointer]  != 0){
			return 0;
			} 
		} if (code[index] == '$'){
			if (tape[pointer]  == 0){
			return 0;
			} 
		} if (code[index] == '!'){
			if (index < 89){
			index = index + 2;
			}
		} if (code[index] == '@'){
			if (index < 89){
				if (tape[pointer]  == 0){
					index = index + 2;
				} 
			}
		} if (code[index] == '#'){
			if (index < 89){
				if (tape[pointer]  != 0){
					index = index + 2;
				} 
			}
		} if (code[index] == '¢'){
			if (tape[pointer] < 90){
				index = tape[pointer];
			}
		} if (code[index] == '0'){
			index = 0;
		} 
		if (index > 89){
			index = 0;
		} else {
		index++;
		} 
	} return 0;
	}
}