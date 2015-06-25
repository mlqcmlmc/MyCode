#include "json.h"
#include <iostream>
#include <stdlib.h>

void creatjson() {
	Json::Value v;
	v["name"] = "zhuhp";
	v["gender"] = "female";

	{
		Json::Value arrayv;
		for (int i = 0; i < 3; ++i) {
			//arrayv.append(i);
			arrayv[i] = i;
		}
		v["array"] = arrayv;
	}

	std::cout << v.toStyledString() << std::endl;
}

void test() {
}

void main() {
	creatjson();
	system("pause");
}