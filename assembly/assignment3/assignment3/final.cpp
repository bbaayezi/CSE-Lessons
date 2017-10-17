#include <stdio.h>
#include <stdlib.h>

void main3() {
	int counter;
	int loopCount = 1;
	char counterInputMessage[] = "Select total number of positive integers (between 2-5):\n";
	char toosmall[] = "The input is too small! The number should be 2-5!\n";
	char toobig[] = "The input is too big! The number should be 2-5!\n";
	char loopMessage[] = "Enter positive interger %d: ";
	char format[] = "%d"; // format to use scanf

	_asm {
	_START:

		; print the message START;

		lea eax, counterInputMessage;
		push eax;
		call printf;
		add esp, 4;
		
		; print OVER

		; initialize the counter START;

		lea eax, counter;
		push eax;
		lea eax, format;
		push eax;
		call scanf_s;
		add esp, 8;

		; initialize OVER

		; judge the counter to see if it lies between 2 and 5 START;

		mov eax, counter;
		cmp eax, 2;
		jl TOOSMALL;
		cmp eax, 5;
		jg TOOBIG;
		jmp INPUTLOOP;

		; judge OVER

		; to handle the two situations START;

	TOOSMALL:
		lea eax, toosmall;
		push eax;
		call printf;
		add esp, 4;
		jmp _START;

	TOOBIG:
		lea eax, toobig;
		push eax;
		call printf;
		add esp, 4;
		jmp _START;

		; handle OVER

		; input loop START

		mov ecx, counter;
	INPUTLOOP:
		push ecx;

		mov eax, loopCount;
		push eax;
		lea eax, loopMessage;
		push eax;
		call printf;
		add esp, 8;

		pop ecx;
		loop INPUTLOOP;
	}

	system("pause");
	return;
}