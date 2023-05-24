//idiots turing machine
#include <stdio.h> 
#include <conio.h>
#include <windows.h>

void egg(char* somethingrelevant){
	fgets(somethingrelevant, 261, stdin);
}

int left_bracket(int pointer_f, char *code_f){
	int depth = 1;
	while (depth > 0){
		pointer_f++;
		if (code_f[pointer_f] == '['){
			depth++;
		}
		else if (code_f[pointer_f] == ']'){
			depth--;
		}
	}
	return pointer_f;
}
int right_bracket(int pointer_f, char *code_f){
	int depth = 1;
	while (depth > 0){
		pointer_f--;
		if (code_f[pointer_f] == ']'){
			depth++;
		}
		else if (code_f[pointer_f] == '['){
			depth--;
		}
	}
	return pointer_f;
}
	

int main(int argc, char** argv){
	FILE * file;
	file = fopen (argv[1], "r");
	int code_lenght = 3000;
	char code[code_lenght];
	int tape_length = 1024;
	unsigned char tape[tape_length];
	int pointer = 0;
	int index = 0;
	int aa;
	int IS=0;
	egg(code);
	while (pointer < tape_length){
		tape[pointer] = 0;
		pointer++;
	} pointer = 0;
	while (1){
		switch(code[index]){
			case '>':
				pointer++;
				if (pointer == tape_length){
					pointer = 0;
				}
				break;
			case '<':
				if (pointer == 0){
					pointer = tape_length;
				}
				pointer--;
				break;
			case '+':
				tape[pointer]++;
				break;
			case '-':
				tape[pointer]--;
				break;
			case '*':
				tape[pointer] = tape[pointer]*2;
				break;
			case '.':
				printf("%c", tape[pointer]);
				break;
			case ':':
				printf("%d \n", tape[pointer]);
				break;
			case ',':
				aa=getchar();
				tape[pointer] = (int)aa;
				break;
			case '[':
				if (tape[pointer] == 0){
					index = left_bracket(index, code);
				}
				break;
			case ']': 
				if (tape[pointer] != 0){
					index = right_bracket(index, code);
				}
				break;
			case 'x':
				return 0;
				break;
			case '&':
				if (tape[pointer]  != 0){
					return 0;
				} 
				break;
			case '$':
				if (tape[pointer]  == 0){
					return 0;
				} 
				break;
			case '!':
				if (index < code_lenght){
					index++;
				}
				break;
			case '@':
				if (index < code_lenght && tape[pointer] == 0){
					index++;
				}
				break;
			case '#':
				if (index < code_lenght && tape[pointer] != 0){
					index++;
				}
				break;
			case '%':
				if (tape[pointer] < code_lenght){
					index = tape[pointer];
				}
				break;
			case '{':
				if (tape[pointer] != 0){
					index = left_bracket(index, code);
				}
				break;
			case '}': 
				if (tape[pointer] == 0){
					index = right_bracket(index, code);
				}
				break;
			case '\\':
				IS = index;
				break;
			case '/':
				index = IS;
				break;
			default:
				printf("error %d \n", code[index]);
				Beep(1000, 1000);
				break;
		}
		if (index >= code_lenght){
			index = 0;
		} else {
			index++;
		} 
	} return 0;
	
}
