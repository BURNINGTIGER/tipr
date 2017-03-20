#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	vector<string> vec1, vec2, vec3;
	unsigned int a = 0, i, j;
	char ch_1[256], ch_2[256];
	FILE *file_1;
	FILE *file_2;

	if ((file_1 = fopen("f1.txt", "r")) == NULL)
	{
		cout << "Error!";
		system("pause");
		return 1;
	}
	if ((file_2 = fopen("f2.txt", "r")) == NULL)
	{
		cout << "Error!";
		system("pause");
		return 1;
	}
	while (!feof(file_1))
	{
		fgets(ch_1, 256, file_1);
		vec1.push_back(ch_1);
		a++;
	}
	a = 0;
	while (!feof(file_2))
	{
		fgets(ch_2, 256, file_2);
		vec2.push_back(ch_2);
		a++;
	}
	a = 1;
	for (i = 0; i < vec1.size(); i++)
	{
		for (j = 0; j < vec2.size(); j++)
		{
			if ((vec1[i] == vec2[j]) && ((vec1[i] != "") || (vec2[j] != "")))
			{
				vec3.push_back(vec1[i]);
				vec1[i] = " ";
				vec2[j] = " ";
				a++;
			}
		}
	}

	for (i = 0; i < vec1.size(); i++)
	{
		for (j = 0; j < vec3.size(); j++)
		{
			if (vec1[i] == vec3[j])
				vec1[i] = " ";
		}
	}
	for (i = 0; i < vec2.size(); i++)
	{
		for (j = 0; j < vec3.size(); j++)
		{
			if (vec2[i] == vec3[j])
				vec2[i] = " ";
		}
	}
	for (i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] != " ")
			cout << "File 1 string " << i+1 << "  " << vec1[i] << "\n";
	}
	for (i = 0; i < vec2.size(); ++i)
	{
		if (vec2[i] != " ")
			cout << "File 2 string " << i + 1 << "  " << vec2[i] << "\n";
	}
	fclose(file_1);
	fclose(file_2);
	system("pause");
	return 0;
}