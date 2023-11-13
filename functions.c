#include "main.h"

/**
 *  * strlen _ length of string
 *   * @s: string
 *    * Return : the length of the string
 *     */
int _strlen(char *s)
{
	    int len = 0;
	        while (s[len])
			    len++;
		    return (len);
}
/**
 *  * strcat _ appends two strings
 *   * @des : destination
 *    * @sr : source
 *     * Return : appended strings
 *      */
char *_strcat(char *des, const char *sr)
{
	    char *p = des;
	        while (*p != NULL)
			        p++;
		    while(*sr != NULL)
			        {
					        *p = *sr;
						        p++;
							        sr++;
								    }
		        *p = *sr;
			    return(des);
}
/**
 *  * strcmp _ compare two strings
 *   * @st1 : string number one
 *    * @st2 : string number two
 *     * Return : integer value
 *      */
int _strcmp(char *st1, char *st2)
{
	    int cmp;
	        while (st1[cmp] == st2[cmp])
			    {
				            if (st1[cmp] == "\0" || st1[cmp] == NULL)
						            {
								                return 0;
										        }
					            cmp++;

						        }
		        return str1[cmp] - str2[cmp];
}

/**
 *  * strcpy _ copy strings
 *   * @des : destination
 *    * @sr : source
 *     * 
 *      * Return : output
 *       */
char *_strcpy(char *des, char *sr)
{
	    int i = 0;
	        while (sr[i])
			    {
				            des[i] = sr[i];
					            i++;
						        }
		        return(des);
}

