
#define bool int
#define true 1
#define false 0

bool isSubsequence(char* s, char* t)
{
	    while (*t && *s) {
		            if (*t == *s)
				                s++;
			            t++;
				        }
	        return !(*s);
}

