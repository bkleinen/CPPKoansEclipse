/*
 * AboutPointers.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "Assert.h"
#include "AboutPointers.h"

void aboutPointers(){
	int i = 5;
	int *i_pointer = &i;
	int* i_pointer2 = &i;
	expectThat("pointers contain memory addresses - they are a reference to the variable",_____,*i_pointer);
	expectThatNot("pointers are thus different from the value they are pointing to",5,i_pointer);
	*i_pointer = 6;
	expectThat("now the value of i has changed",_____,i);
}
void aboutAssignmentCompatibility(){
	int *pInt, i=5;
	double *pDouble;
	pInt = &i;
	// pDouble = (int*)pInt; does not compile in Visual Studio
}
void aboutDynamicAllocation(){
	int *p;
	p = new int;
	*p = 5000;
	expectThatNot("what's in the pointer now?",0,p);
	delete p;
	// *p = 6000; this produces a crash / Access Violation
}
void aboutPointersAndArrays(){
	const int number = 10;
	char a[number];
	char defaultChar = 'x';
	char *p = a; // same type, p would also work below.
	for (int i=0;i<number;i++){
		*(a+i) = defaultChar;
	}
	for (int i=0;i<number;i++){
		expectThat("now the defaultChar should be in every cell #"+i,defaultChar,p[i]);
	}
}
void AboutPointers::meditate(){
	aboutPointers();
	aboutAssignmentCompatibility();
	aboutDynamicAllocation();
	aboutPointersAndArrays();

}

