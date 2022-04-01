#pragma once
#include <iostream>
#include <string>
#include <windows.h>

#include "Funkcionalita.h"

#define _CRT_SECURE_NO_DEPRECATE

using namespace structures;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SetConsoleOutputCP(1250);
	SetConsoleCP(1250);
	setlocale(LC_ALL, "slovak");
	Funkcionalita fun3("2 Uzemne clenenie SR.csv", "1 Obce SR.csv");
	fun3.cli();
}