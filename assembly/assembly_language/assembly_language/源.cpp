#include <stdio.h>
#include <stdlib.h>

void main() {
	char message1[] = "Give me a first number: \n";
	char message2[] = "\nGive me a second number: \n";
	char message3[] = "\nThe numbers are equal! \n";
	char message4[] = "\nThe numbers are not equal! \n";
	char message6[] = "\nThe first one is greater!\n";
	char message7[] = "\nThe second one is greater!\n";
	char message5[] = "Finish!\n";
	char format[] = "%d"; // format string for the scanf function
	int first, second, end;
	_asm {
		lea eax, message1;
		push eax;
		call printf;            print the first message
		add esp, 4;

		lea eax, first;
		push eax;
		lea eax, format;
		push eax;               get first number
		call scanf_s;
		add esp, 8;

		lea eax, message2;
		push eax;               print the second message
		call printf;
		add esp, 4;

		lea eax, second;
		push eax;
		lea eax, format;        get second number
		push eax;
		call scanf_s;
		add esp, 8;

		mov eax, first;
		cmp eax, second;			comparing process
		ja fgreater;
		jna sgreater;

	equal: lea eax, message3;
		push eax;
		call printf;
		add esp, 4;
		jmp finish;

	nequal: lea eax, message4;
		push eax;
		call printf;
		add esp, 4;
		jmp finish;

	fgreater: lea eax, message6;
		push eax;
		call printf;
		add esp, 4;
		jmp finish;

	sgreater: lea eax, message7;
		push eax;
		call printf;
		add esp, 4;
		jmp finish;

	finish: lea eax, message5;
		push eax;
		call printf;
		add esp, 4;
	}
	//printf("%d", first);
	system("pause");
	return;
}

/*void main() {
	int i;
	printf("input the first number: \n");
	scanf_s("%d", &i);
	printf("%d", i);
	system("pause");
	return;
}*/