// write a program to change a given name in the file

#include <stdio.h>
#include <string.h>

#define NAMES_FILE "USERNAMES.txt"
#define SIZE 10

FILE *fp_names;

void remove_new_line(char *text)
{
	int length = strlen(text);
	if (length > 0 && text[length - 1] == '\n')
	{
		text[length - 1] = '\0';
	}
}

int find_name(char *check_name)
{
	char existing_name[SIZE];
	fp_names = fopen(NAMES_FILE, "r+");
	while (fgets(existing_name, SIZE, fp_names))
	{
		remove_new_line(existing_name);
		if (strcmp(existing_name, check_name) == 0)
		{
			int string_length = strlen(existing_name) + 1;
			fseek(fp_names, -string_length, SEEK_CUR);
			return 1;
		}
	}
	fclose(fp_names);
	printf("\nName not found. ");
	return 0;
}


int main()
{
	char new_name[SIZE], check_name[SIZE];
	printf("Enter the name you want to change: ");
	fgets(check_name, SIZE, stdin);
	remove_new_line(check_name);
	if (find_name(check_name))
	{
		printf("Enter new name: ");
		fgets(new_name, SIZE, stdin);
		remove_new_line(new_name);
		fputs(new_name, fp_names);
		fclose(fp_names);
		printf("Name updated successfully. ");
	}
	return 0;

}
