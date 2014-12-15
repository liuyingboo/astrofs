/*
 *
 *
 */
#include <gdsl.h>
#include <stdio.h>
#include <string.h>

gdsl_element_t
alloc_string(void* string)
{
     return (gdsl_element_t) strdup ((char*) string);
}

void
free_string(gdsl_element_t e)
{
     free(e);
}


extern void
print_string (gdsl_element_t e, FILE* file, gdsl_location_t location, void* d)
{
    char loc [256] = "";

    if (location & GDSL_LOCATION_ROOT)
	{
	    strcat (loc, "ROOT ");
	}

    if (location & GDSL_LOCATION_LEAF)
	{
	    strcat (loc, "LEAF ");
	}

    if (d == NULL)
	{
	    fprintf (file, "%s%s", (char*) e, loc);
	}
    else
	{
	    fprintf (file, "%s%s%s", (char*) e, loc, (char*) d);
	}
}


void
main(void)
{
     gdsl_list_t l = gdsl_list_alloc ("MY LIST", alloc_string, free_string);
     if(gdsl_list_is_empty(l))
     {
          printf ("The list is empty.\n");
     }

     char a[10] = "liu";
     char b[10] = "ying";
     char c[10] = "bo";
     char d[10] = "AstroFS";

     gdsl_list_insert_tail (l, a);
     gdsl_list_insert_tail (l, b);
     gdsl_list_insert_tail (l, c);
     gdsl_list_insert_tail (l, d);

     gdsl_list_dump (l, print_string, stdout, NULL);
}
