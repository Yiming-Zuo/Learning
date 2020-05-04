#include "mydll.h"

__declspec(dllexport) myadd(int a, int b) {
	return a + b;
}