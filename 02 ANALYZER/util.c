#include "my.h"

char fg[]={0,1,2,3,4,5,6};
char bg[]={8,8,8,8,8,8,8};

void colore(int col){
	col%=sizeof(fg);
	myprintf("\033[0;%d;%dm",30+fg[col],40+bg[col]);	
}

void o_colore(int col){
	col%=sizeof(fg);
	myprintf("\033[0;%d;%dm",30+fg[col],40+bg[col]);	
}

//string append
void append(char* s, char c)
{
		int len = strlen(s);
		s[len] = c;
		s[len+1] = '\0';
}

// string split

char** str_split(char* a_str, const char a_delim)
{
		char** result    = 0;
		size_t count     = 0;
		char* tmp        = a_str;
		char* last_comma = 0;
		char delim[2];
		delim[0] = a_delim;
		delim[1] = 0;

		// Count how many elements will be extracted.
		while (*tmp)
		{
				if (a_delim == *tmp)
				{
						count++;
						last_comma = tmp;
				}
				tmp++;
		}

		// Add space for trailing token. 
		count += last_comma < (a_str + strlen(a_str) - 1);

		//Add space for terminating null string so caller
		//	 knows where the list of returned strings ends. 
		count++;

		result = malloc(sizeof(char*) * count);

		if (result)
		{
				size_t idx  = 0;
				char* token = strtok(a_str, delim);

				while (token)
				{
						//assert(idx < count);
						*(result + idx++) = strdup(token);
						token = strtok(0, delim);
				}
				//assert(idx == count - 1);
				*(result + idx) = 0;
		}

		return result;
}

//extract string between delimeters
char* extractString(char source[], char* delim1, char* delim2) {
	//myprintf("ABOUT TO TEST %s , %s, %s", source, delim1, delim2);
	const char *p1 = strstr(source, delim1) + strlen(delim1);
	const char *p2 = strstr(source, delim2);

	if ((p1 == NULL) || (p2 == NULL)) {
		myprintf("NULL !!!\n\n");
		return "";
	}

	myprintf("p1 %s : ", p1);
	myprintf("p2 %s : ", p2);
	size_t len = p2 - p1;
	//static char result[2000];//
	char result[1000] = "CULO";//(char*) malloc(sizeof(char)*(len+1));
	//strncpy(result, p1, len);
	//result[len] = '\0';
	//myprintf("RESULT : %s", result);
	return result;
}

void myprintf(const char *fmt, ...){
	va_list ap;
	va_start(ap,fmt);
	vsprintf(outbuf+olen,fmt,ap);
	va_end(ap);
	olen+=strlen(outbuf+olen);
}
void myscanf( const char * str, const char * format, ... ) {
  va_list args;
  va_start (args, format);
  vsscanf (str, format, args);
  va_end (args);
}

void print_liv2(const u_char *p){
	int i;
	for(i=0;;i++){
		myprintf("%x",*p++); //MODIFICATO myprintf
		if(i==5)break;
		myprintf(":"); //MODIFICATO myprintf
	}
}

void print_ipv4(const u_char *p){
	const u_char *mp;
	int i;
	for(mp=p,i=0;;i++){
		myprintf("%d",*mp++); //MODIFICATO myprintf
		if(i==3)break;
		myprintf("."); //MODIFICATO myprintf
	}
}

void print_ipv6(const u_char *p){
	const u_char *mp;
	int i;
	for(mp=p,i=0;;i++){
		myprintf("%x",ntohs(*(u_int *)mp)); //MODIFICATO myprintf
		if(i==7)break;
		mp+=2;
		myprintf(":"); //MODIFICATO myprintf
	}
}
