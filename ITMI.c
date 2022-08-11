//idiots turing machine
#include <stdio.h> 
#include <conio.h>

int main(int argc, char** argv){
	FILE * file;
	file = fopen (argv[1], "r");
	char code[261];
	int tape[1024];
	int aa;
	int ac;
	int pointer = 1;
	int index = 0;
	int cicle = 0;
	fgets(code, 261, stdin);
	//if (file == NULL){
	//	return 1;
	//} else{
	while (1){
		if (code[index] == '>'){
			if (pointer < 254 ){
			pointer++;
			} else{
				pointer = 0;
			}
			pointer++;
		} if (code[index] == '<'){
			if (pointer > 1 ){
			pointer--;
			} else {
				pointer = 254;
			}
		} if (code[index] == '+'){
			if (tape[pointer] > 255){
			tape[pointer] = 0;
			} else {
				tape[pointer] = tape[pointer] + 1;
			}
		} if (code[index] == '*'){
			if (tape[pointer] > 127){
			tape[pointer] = 0;
			} else {
				tape[pointer] = tape[pointer]*2;
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
		} if (code[index] == 'x'){
			break;
		} if (code[index] == '£'){
			if (tape[pointer]  != 0){
			return 0;
			} 
		} if (code[index] == '$'){
			if (tape[pointer]  == 0){
			return 0;
			} 
		} if (code[index] == '!'){
			if (index < 260){
			index = index + 2;
			}
		} if (code[index] == '@'){
			if (index < 260){
				if (tape[pointer]  == 0){
					index = index + 2;
				} 
			}
		} if (code[index] == '#'){
			if (index < 260){
				if (tape[pointer]  != 0){
					index = index + 2;
				} 
			}
		} if (code[index] == '¢'){
			if (tape[pointer] < 261){
				index = tape[pointer];
			}
		} if (code[index] == '0'){
			index = 0;
		} 
		if (index > 260){
			index = 0;
		} else {
		index++;
		} 
	} return 0;
	//}
}