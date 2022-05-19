#ifndef _MAIN_H_
#define _MAIN_H_

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Main Helper Prototypes */
int main(void);
char *reading(void);
char **cutting(char *line);
int executing(char **tokens, char *line);
int comparing(char **tokens);
void sigint_handler(int sigint);
int semicolon(char *line);

/* Built-in Prototypes */
void _env(char **commands);
int _cd(char **args);

/* Errors Prototypes */
void errors(char __attribute__((unused)) **tokens);

/* String Prototypes */
int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

extern char **environ;
#endif
