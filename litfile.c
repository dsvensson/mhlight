#include "light.h"


byte *dlitdata = NULL;

byte *AllocLitEntry (int offset)
{
	// generate the proper data the first time we go in here
	if (!dlitdata)
		dlitdata = malloc (MAX_MAP_LIGHTING * 3);

	// just return a position within the array
	return &dlitdata[offset];
}


#define LIT_IDENT 0x54494c51
#define LIT_VERSION 1

void GenerateLITFile (char *source)
{
	int i;
	FILE *f;
	char litfilename[256];

	printf ("Generating LIT file... ");

	sprintf (litfilename, "%s", source);

	for (i = 0; ; i++)
	{
		// note : these will always happen
		if (litfilename[i] == '.' && 
			litfilename[i + 1] == 'b' && 
			litfilename[i + 2] == 's' && 
			litfilename[i + 3] == 'p')
		{
			litfilename[i + 1] = 'l';
			litfilename[i + 2] = 'i';
			litfilename[i + 3] = 't';

			break;
		}
	}

	f = fopen (litfilename, "wb");

	// write the header
	i = LIT_IDENT;
	fwrite (&i, sizeof (int), 1, f);

	i = LIT_VERSION;
	fwrite (&i, sizeof (int), 1, f);

	// write the entries
	fwrite (dlitdata, lightdatasize * 3, 1, f);

	fclose (f);

	printf ("Done\n");
}
