#include <stdio.h>
#include <stdlib.h>

int main() {
	int counter;
	int loopCount = 0;
	signed int inputArr[5] = {0,0,0,0,0};
	int arrIndex = 0;
	char format[] = "%d";
	char resultFormat[] = "%d, ";
	char end[] = "\b\b.\n";
	char counterInputMessage[] = "Select total number of positive integers (between 2-5):\n";
	char inputErrorMessage[] = "\nIncorrect input! Thie number should lied between 2-5!\n";
	char nextMessage[] = "Your input is corrext\n";
	char terminateMessage[] = "Program terminates and has looped %d times.\n";
	char loopMessage[] = "Enter positive interger %d: ";
	char endLoopMessage[] = "Program terminates and has looped %d time(s)\n";
	char resultMessage[] = "Your integers from lowest to highest is ";
	
	_asm {
	startop: 
		lea eax, counterInputMessage								;
		push eax													;
		call printf													;
		add esp, 4													;

		lea eax, counter											;
		push eax													;
		lea eax, format												;
		push eax													;
		call scanf													;
		add esp, 8													;

		mov eax, counter											;
		cmp eax, 2													;
		jnb compare2												;
		jmp incorrectCounterInput									;

	compare2: 
		cmp eax, 5													;
		jna nextop													;
		jmp incorrectCounterInput									;

	incorrectCounterInput: 
		lea eax, inputErrorMessage									;
		push eax													;
		call printf													;
		add esp, 4													;
		jmp startop													;

	nextop: 
		lea eax, nextMessage										;
		push eax													;
		call printf													;
		add esp, 4													;

		mov ecx, counter											;

	inputLoop:
		push ecx													;
		inc loopCount												;

		mov eax, loopCount											;
		push eax													;
		lea eax, loopMessage										;
		push eax													;
		call printf													;
		add esp, 8													;

		mov ebx, arrIndex											;
		push ebx													;
		lea eax, inputArr[ebx * 4]									;
		push eax													;
		lea eax, format												;
		push eax													;
		call scanf													;
		add esp, 8													;

		mov eax, [inputArr + ebx * 4]								;
		cmp eax, 0													;
		jle preEndLoop												;

		inc arrIndex												;
	
		pop ebx														;
		pop ecx														;
		loop inputLoop												;

		jmp endLoop													;

	preEndLoop: 
		dec loopCount												;
		jmp endLoop													;

	endLoop: 
		mov eax, loopCount											;
		push eax													;
		lea eax, endLoopMessage										;
		push eax													;
		call printf													;
		add esp, 8													;



		mov ecx, loopCount											;
		dec ecx														;

	L1:
		push ecx;
		lea esi, inputArr;
	L2:
		mov eax, [esi];
		cmp [esi + 4], eax;
		jge L3;
		xchg eax, [esi + 4];
		mov [esi], eax;
	L3:
		add esi, 4;
		loop L2;
		pop ecx;
		loop L1;
		
													

		
		lea eax, resultMessage										;
		push eax													;
		call printf													;
		add esp, 4													;

		mov ecx, loopCount											;
		lea esi, inputArr;

	resultLoop:
		push ecx;
		mov eax, [esi];
		push eax;
		lea eax, resultFormat;
		push eax;
		call printf;
		add esp, 8;

		pop ecx;
		add esi, 4;
		loop resultLoop;

		lea eax, end;
		push eax;
		call printf;
		add esp, 4;
		
		
	}
	//printf("%d", temp);
	

	/*for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4 - j; k++) {
			if (inputArr[k] > inputArr[k + 1])
			{
				temp = inputArr[k];
				inputArr[k] = inputArr[k + 1];
				inputArr[k + 1] = temp;
			}
		}
	}*/

	/*for (int l = 0; l < 5; l++) {
		printf("%d， ", inputArr[l]);
	}*/

	_asm {

	}
	/*printf("%d", counter);
	
	mov eax, dword ptr[arrIndex]
		mov ecx, dword ptr[loopInput]
		mov dword ptr inputArr[eax * 4], ecx
		mov eax, dword ptr[arrIndex]
		add eax, 1
		mov dword ptr[arrIndex], eax


		操作助记符为JL(小于), JLE(小于等于), JG(大于), JGE(大于等于), JZ(相等) JNZ(不等).
		而对应的无符号比较的条件转移语句是JB(小于), JBE(小于等于), JA(大于), JAE(大于等于), JZ(相等) JNZ(不等).
	*/
	/*for (int i = 0; i < 5; i++) {
		printf("%d", inputArr[5]);
	}*/
	system("pause");
	return 0;
}