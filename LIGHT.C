// lighting.c

#include "light.h"

void GenerateLITFile (char *source);
void ProcessColour (void);

int oversample = 1;

/*

NOTES
-----

*/

float		scaledist = 1.0;
float		scalecos = 0.5;
float		rangescale = 0.5;

byte		*filebase, *file_p, *file_end;

dmodel_t	*bspmodel;
int			bspfileface;	// next surface to dispatch

vec3_t	bsp_origin;

int			extrasamples = 1;

float		minlights[MAX_MAP_FACES];


byte *GetFileSpace (int size)
{
	byte	*buf;
	
	file_p = (byte *)(((long)file_p + 3)&~3);
	buf = file_p;
	file_p += size;

	if (file_p > file_end)
		Error ("GetFileSpace: overrun");
	return buf;
}


void LightThread (qboolean test)
{
	int			i;
	int			progress_stride;
	int			progress_tick = 0;

	progress_stride = numfaces / 77;

	// set up progress as if it was for real
	progress_tick = 0;
	bspfileface = 0;

	if (test)
		printf ("Building Coloured Light...\n[");
	else printf ("Lighting World...\n[");

	while (1)
	{
		i = bspfileface++;

		if (i >= numfaces)
			break;

		progress_tick++;

		if (progress_tick > progress_stride)
		{
			printf (" ");
			progress_tick = 0;
		}
	}

	printf ("]\r[");

	// now do it really for real
	progress_tick = 0;
	bspfileface = 0;

	while (1)
	{
		i = bspfileface++;

		if (i >= numfaces)
		{
			printf ("\n\n");
			return;
		}
		
		progress_tick++;

		if (progress_tick > progress_stride)
		{
			printf ("*");
			progress_tick = 0;
		}

		LightFace (i, test);
	}
}

/*
=============
LightWorld
=============
*/
void LightWorld (void)
{
	filebase = file_p = dlightdata;
	file_end = filebase + MAX_MAP_LIGHTING;

	LightThread (false);

	lightdatasize = file_p - filebase;

	printf ("Light Data Size: %i\n\n", lightdatasize);
}


/*
========
main

light modelfile
========
*/
int main (int argc, char **argv)
{
	int		i;
	double		start, end;
	char		source[1024];

	for (i=1 ; i<argc ; i++)
	{
		if (!strcmp(argv[i], "-extra"))
		{
			extrasamples = 2;
			printf ("2 x extra sampling enabled\n");
		}
		else if (!strcmp(argv[i], "-extra4"))
		{
			extrasamples = 4;
			printf ("4 x extra sampling enabled\n");
		}
		else if (!strcmp(argv[i],"-dist"))
		{
			scaledist = atof (argv[i+1]);
			i++;
		}
		else if (!strcmp(argv[i],"-range"))
		{
			rangescale = atof (argv[i+1]);
			i++;
		}
		else if (argv[i][0] == '-')
			Error ("Unknown option \"%s\"", argv[i]);
		else
			break;
	}

	if (i != argc - 1)
		Error ("usage: light [-extra] bspfile");

	InitThreads ();

	start = I_FloatTime ();

	strcpy (source, argv[i]);
	StripExtension (source);
	DefaultExtension (source, ".bsp");
	
	LoadBSPFile (source);
	LoadEntities ();
	
	MakeTnodes (&dmodels[0]);

	printf ("Lighting %i Surfaces\n", numfaces);

	printf ("\n");

	ProcessColour ();

	LightWorld ();

	WriteEntitiesToString ();	
	WriteBSPFile (source);
	GenerateLITFile (source);

	end = I_FloatTime ();

	printf ("%0.2f Seconds Elapsed\n", end - start);

	return 0;
}

