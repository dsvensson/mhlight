#include "light.h"


int qpal[256][3] =
{
	{  1,   1,   1},
	{ 16,  16,  16},
	{ 32,  32,  32},
	{ 48,  48,  48},
	{ 64,  64,  64},
	{ 76,  76,  76},
	{ 92,  92,  92},
	{108, 108, 108},
	{124, 124, 124},
	{139, 139, 139},
	{155, 155, 155},
	{171, 171, 171},
	{187, 187, 187},
	{203, 203, 203},
	{219, 219, 219},
	{235, 235, 235},
	{ 16,  12,   8},
	{ 24,  16,  12},
	{ 32,  24,  12},
	{ 40,  28,  16},
	{ 48,  36,  20},
	{ 56,  44,  24},
	{ 64,  48,  24},
	{ 76,  56,  28},
	{ 84,  60,  28},
	{ 92,  68,  32},
	{100,  76,  32},
	{108,  84,  32},
	{116,  88,  32},
	{124,  96,  36},
	{131, 104,  36},
	{143, 112,  36},
	{ 12,  12,  16},
	{ 20,  20,  28},
	{ 28,  28,  40},
	{ 40,  40,  52},
	{ 48,  48,  64},
	{ 56,  56,  76},
	{ 64,  64,  88},
	{ 72,  72, 104},
	{ 80,  80, 116},
	{ 92,  92, 128},
	{100, 100, 139},
	{108, 108, 151},
	{116, 116, 163},
	{124, 124, 175},
	{131, 131, 187},
	{139, 139, 203},
	{  1,   1,   1},
	{  8,   8,   1},
	{ 12,  12,   1},
	{ 20,  20,   1},
	{ 28,  28,   1},
	{ 36,  36,   1},
	{ 44,  44,   8},
	{ 48,  48,   8},
	{ 56,  56,   8},
	{ 64,  64,   8},
	{ 72,  72,   8},
	{ 76,  76,  12},
	{ 84,  84,  12},
	{ 92,  92,  12},
	{100, 100,  12},
	{108, 108,  16},
	{  8,   1,   1},
	{ 16,   1,   1},
	{ 24,   1,   1},
	{ 32,   1,   1},
	{ 40,   1,   1},
	{ 48,   1,   1},
	{ 56,   1,   1},
	{ 64,   1,   1},
	{ 72,   1,   1},
	{ 80,   1,   1},
	{ 88,   1,   1},
	{ 96,   1,   1},
	{104,   1,   1},
	{112,   1,   1},
	{120,   1,   1},
	{128,   1,   1},
	{ 20,  20,   1},
	{ 28,  28,   1},
	{ 36,  36,   1},
	{ 48,  44,   1},
	{ 56,  48,   1},
	{ 68,  56,   1},
	{ 76,  60,   8},
	{ 88,  68,   8},
	{ 96,  72,   8},
	{108,  76,  12},
	{120,  84,  16},
	{131,  88,  20},
	{139,  92,  20},
	{151,  96,  28},
	{163, 100,  32},
	{175, 104,  36},
	{ 36,  20,   8},
	{ 48,  24,  12},
	{ 60,  32,  16},
	{ 76,  36,  20},
	{ 88,  44,  24},
	{100,  48,  32},
	{116,  56,  36},
	{128,  60,  44},
	{143,  68,  52},
	{159,  80,  52},
	{175, 100,  48},
	{191, 120,  48},
	{207, 143,  44},
	{223, 171,  40},
	{239, 203,  32},
	{255, 243,  28},
	{ 12,   8,   1},
	{ 28,  20,   1},
	{ 44,  36,  16},
	{ 56,  44,  20},
	{ 72,  52,  28},
	{ 84,  56,  36},
	{100,  64,  44},
	{112,  72,  52},
	{128,  84,  64},
	{139,  96,  72},
	{155, 108,  84},
	{167, 124,  96},
	{183, 135, 108},
	{195, 147, 124},
	{211, 163, 139},
	{227, 179, 151},
	{171, 139, 163},
	{159, 128, 151},
	{147, 116, 135},
	{139, 104, 124},
	{128,  92, 112},
	{120,  84, 100},
	{108,  76,  88},
	{ 96,  64,  76},
	{ 88,  56,  68},
	{ 76,  48,  56},
	{ 68,  40,  48},
	{ 56,  32,  36},
	{ 44,  24,  28},
	{ 36,  20,  20},
	{ 24,  12,  12},
	{ 16,   8,   8},
	{187, 116, 159},
	{175, 108, 143},
	{163,  96, 131},
	{151,  88, 120},
	{139,  80, 108},
	{128,  76,  96},
	{116,  68,  84},
	{108,  60,  76},
	{ 96,  52,  64},
	{ 84,  44,  56},
	{ 72,  36,  44},
	{ 60,  32,  36},
	{ 48,  24,  28},
	{ 36,  20,  20},
	{ 24,  12,  12},
	{ 16,   8,   8},
	{219, 195, 187},
	{203, 179, 167},
	{191, 163, 155},
	{175, 151, 139},
	{163, 135, 124},
	{151, 124, 112},
	{135, 112,  96},
	{124, 100,  84},
	{108,  88,  72},
	{ 96,  76,  60},
	{ 84,  64,  52},
	{ 68,  52,  40},
	{ 56,  44,  32},
	{ 40,  32,  24},
	{ 28,  20,  16},
	{ 16,  12,   8},
	{112, 131, 124},
	{104, 124, 112},
	{ 96, 116, 104},
	{ 88, 108,  96},
	{ 80, 100,  88},
	{ 72,  92,  80},
	{ 64,  84,  72},
	{ 56,  76,  64},
	{ 48,  68,  56},
	{ 44,  60,  48},
	{ 36,  52,  40},
	{ 32,  44,  32},
	{ 24,  36,  24},
	{ 16,  28,  20},
	{ 12,  20,  12},
	{  8,  12,   8},
	{255, 243,  28},
	{239, 223,  24},
	{219, 203,  20},
	{203, 183,  16},
	{187, 167,  16},
	{171, 151,  12},
	{155, 131,   8},
	{139, 116,   8},
	{124, 100,   8},
	{108,  84,   1},
	{ 92,  72,   1},
	{ 76,  56,   1},
	{ 60,  44,   1},
	{ 44,  32,   1},
	{ 28,  16,   1},
	{ 12,   8,   1},
	{  1,   1, 255},
	{ 12,  12, 239},
	{ 20,  20, 223},
	{ 28,  28, 207},
	{ 36,  36, 191},
	{ 44,  44, 175},
	{ 48,  48, 159},
	{ 48,  48, 143},
	{ 48,  48, 128},
	{ 48,  48, 112},
	{ 48,  48,  96},
	{ 44,  44,  80},
	{ 36,  36,  64},
	{ 28,  28,  48},
	{ 20,  20,  32},
	{ 12,  12,  16},
	{ 44,   1,   1},
	{ 60,   1,   1},
	{ 76,   8,   1},
	{ 96,   8,   1},
	{112,  16,   1},
	{128,  24,   8},
	{147,  32,   8},
	{163,  40,  12},
	{183,  52,  16},
	{195,  76,  28},
	{207, 100,  44},
	{219, 128,  60},
	{227, 151,  80},
	{231, 171,  96},
	{239, 191, 120},
	{247, 211, 139},
	{167, 124,  60},
	{183, 155,  56},
	{199, 195,  56},
	{231, 227,  88},
	{128, 191, 255},
	{171, 231, 255},
	{215, 255, 255},
	{104,   1,   1},
	{139,   1,   1},
	{179,   1,   1},
	{215,   1,   1},
	{255,   1,   1},
	{255, 243, 147},
	{255, 247, 199},
	{255, 255, 255},
	{159,  92,  84}
};


// other palette entries that contribute light
// !!! THIS WILL ONLY WORK WITH THE DEFAULT QUAKE PALETTE.  IT WILL GIVE WEIRD RESULTS WITH CUSTOM PALETTES !!!
// always zero-terminate it to ensure proper loop breakout below.
int OtherColours[] = {47, 77, 78, 79, 109, 110, 111, 192, 193, 0};

void AverageColour (int width, int height, byte *data, int threshold, int *colour, float add)
{
	int i;
	int j;
	qboolean haslight = false;
	qboolean hascolour = true;
	float newcolour[3];
	int scale = 0;
	int gs;
	float total;
	float factor;

	newcolour[0] = newcolour[1] = newcolour[2] = 0;

	for (i = 0; i < width * height; i++)
	{
		// accumulate some white to prevent the colour from over-dominating
		newcolour[0] += 4;
		newcolour[1] += 4;
		newcolour[2] += 4;

		// never have colour
		if (data[i] >= 254) continue;

		// same intensity in each channel
		if (qpal[data[i]][0] == qpal[data[i]][1] && qpal[data[i]][1] == qpal[data[i]][2]) continue;

		// conditions for colour - within the threshold range
		if (data[i] > threshold && data[i] < 254) goto doColour;

		// certain other colours are used for light textures too
		for (j = 0; ; j++)
		{
			if (!OtherColours[j]) break;

			if (data[i] == OtherColours[j]) goto doColour;
		}

		// if the greyscale value is sufficiently high, also give it colour
		gs = (qpal[data[i]][0] * 30 + qpal[data[i]][1] + 59 + qpal[data[i]][2] * 11) / 100;

		if (gs > 128) goto doColour;

		// no colour
		continue;

		// this is where the dreaded goto has it's uses, eh?
doColour:;
		haslight = true;

		newcolour[0] += (float) qpal[data[i]][0];
		newcolour[1] += (float) qpal[data[i]][1];
		newcolour[2] += (float) qpal[data[i]][2];
		scale++;
	}

	if (!haslight) return;

	// scale colour as if the texture was 64 * 64
	newcolour[0] *= add; newcolour[0] /= 255.0f; newcolour[0] *= (float) scale; newcolour[0] /= 4096.0f;
	newcolour[1] *= add; newcolour[1] /= 255.0f; newcolour[1] *= (float) scale; newcolour[1] /= 4096.0f;
	newcolour[2] *= add; newcolour[2] /= 255.0f; newcolour[2] *= (float) scale; newcolour[2] /= 4096.0f;

	// now normalise the colour
	total = (newcolour[0] * 30.0f + newcolour[1] * 59.0f + newcolour[2] * 11.0f) / 100.0f;
	factor = 255.0f / total;

	// accumulate into colour - note - green and blue can be weak, so we also boost them a little at this stage
	colour[0] += (newcolour[0] * factor);
	colour[1] += (newcolour[1] * factor) * 1.25f;
	colour[2] += (newcolour[2] * factor) * 1.5f;
}


// returns true if it processes a lava or slime.
// required for a separate pass as these don't go through the light pass
qboolean ColourLight (entity_t *light, dface_t *face, float add)
{
	texinfo_t *ti = &texinfo[face->texinfo];
	dmiptexlump_t *m = (dmiptexlump_t *) dtexdata;
	miptex_t *mt;
	byte *pixels;

	// locate the texture
	mt = (miptex_t *) ((byte *) m + m->dataofs[ti->miptex]);

	// locate the data
	pixels = (byte *) (mt + 1);

	if (!strncmp (mt->name, "*lava", 5))
	{
		AverageColour (mt->width, mt->height, pixels, 0, light->colour, add);

		// add flicker to lava
		light->style = 1;

		light->colour[0] = 0;
		light->colour[1] = 255;
		light->colour[2] = 0;

		return true;
	}
	else if (!strncmp (mt->name, "*slime", 6))
	{
		AverageColour (mt->width, mt->height, pixels, 0, light->colour, add);

		// hack - double the green for slime
		light->colour[1] *= 2;

		return true;
	}
	else if (mt->name[0] == '*')
		return false;
	else if (!strncmp (mt->name, "sky", 3))
		return false;

	AverageColour (mt->width, mt->height, pixels, 223, light->colour, add);
	return false;
}


// simplified versions of the full game memory versions
typedef struct texture_s
{
	int width;
	int height;
	char name[16];
	byte *data;
	qboolean haslight;
	qboolean liquid;
	int light[3];
} texture_t;


typedef struct mplane_s
{
	vec3_t	normal;
	float	dist;
	byte	type;			// for texture axis selection and fast side tests
	byte	signbits;		// signx + signy<<1 + signz<<1
	byte	pad[2];
} mplane_t;


typedef struct
{
	float		vecs[2][4];
	float		mipadjust;
	texture_t	*texture;
	int			flags;
} mtexinfo_t;


typedef struct msurface_s
{
	dface_t *face;
	int surfnum;
	mtexinfo_t *texinfo;
} msurface_t;


typedef struct mnode_s
{
// common with leaf
	int			contents;		// 0, to differentiate from leafs
	int			visframe;		// node needs to be traversed if current
	
	float		minmaxs[6];		// for bounding box culling

	struct mnode_s	*parent;

// node specific
	mplane_t	*plane;
	struct mnode_s	*children[2];	

	unsigned short		firstsurface;
	unsigned short		numsurfaces;
} mnode_t;



typedef struct mleaf_s
{
// common with node
	int			contents;		// wil be a negative contents number
	int			visframe;		// node needs to be traversed if current

	float		minmaxs[6];		// for bounding box culling

	struct mnode_s	*parent;

// leaf specific
	int			leafnum;
	byte		*compressed_vis;

	msurface_t	**firstmarksurface;
	int			nummarksurfaces;
	int			key;			// BSP sequence number for leaf's contents
	byte		ambient_sound_level[NUM_AMBIENTS];
} mleaf_t;


typedef struct loadmodel_s
{
	texture_t *textures;
	mplane_t *planes;
	mtexinfo_t *texinfo;
	msurface_t *surfaces;
	msurface_t **marksurfaces;
	mnode_t *nodes;
	mleaf_t *leafs;
} loadmodel_t;


loadmodel_t loadmodel;


void *MyMalloc (int size)
{
	byte *data = malloc (size);
	memset (data, 0, size);

	return (void *) data;
}


void Mod_LoadTextures (void)
{
	dmiptexlump_t *m;
	miptex_t	*mt;
	int i;
	texture_t *tx;

	m = (dmiptexlump_t *) dtexdata;

	loadmodel.textures = MyMalloc (m->nummiptex * sizeof (texture_t));

	for (i = 0; i < m->nummiptex; i++)
	{
		// locate the miptex data
		mt = (miptex_t *) ((byte *) m + m->dataofs[i]);

		// copy it in
		strcpy (loadmodel.textures[i].name, mt->name);
		loadmodel.textures[i].width = mt->width;
		loadmodel.textures[i].height = mt->height;
		loadmodel.textures[i].data = (byte *) (mt + 1);

		tx = &loadmodel.textures[i];

		tx->haslight = false;
		tx->liquid = false;
		tx->light[0] = tx->light[1] = tx->light[2] = 0;

		// don't bother with sky
		if (!strncmp (tx->name, "sky", 3)) continue;

		if (!strncmp (tx->name, "*lava", 5))
		{
			AverageColour (tx->width, tx->height, tx->data, 0, tx->light, 255);
			tx->liquid = true;
		}
		else if (!strncmp (tx->name, "*slime", 6))
		{
			AverageColour (tx->width, tx->height, tx->data, 0, tx->light, 255);
			tx->liquid = true;
		}
	}
}


void Mod_LoadPlanes (void)
{
	int i;
	int j;
	int bits;

	loadmodel.planes = MyMalloc (numplanes * sizeof (mplane_t));

	for (i = 0; i < numplanes; i++)
	{
		bits = 0;

		for (j = 0; j < 3; j++)
		{
			loadmodel.planes[i].normal[j] = dplanes[i].normal[j];

			if (loadmodel.planes[i].normal[j] < 0) bits |= 1 << j;
		}

		loadmodel.planes[i].dist = dplanes[i].dist;
		loadmodel.planes[i].type = dplanes[i].type;
		loadmodel.planes[i].signbits = bits;
	}
}


void Mod_LoadTexinfo (void)
{
	int i;
	int j;

	loadmodel.texinfo = MyMalloc (numtexinfo * sizeof (mtexinfo_t));

	for (i = 0; i < numtexinfo; i++)
	{
		for (j = 0; j < 8; j++)
			loadmodel.texinfo[i].vecs[0][j] = texinfo[i].vecs[0][j];

		loadmodel.texinfo[i].flags = texinfo[i].flags;

		loadmodel.texinfo[i].texture = &loadmodel.textures[texinfo[i].miptex];
	}
}


void Mod_LoadFaces (void)
{
	int i;

	loadmodel.surfaces = MyMalloc (numfaces * sizeof (msurface_t));

	for (i = 0; i < numfaces; i++)
	{
		// we only need to address the texinfo here
		loadmodel.surfaces[i].texinfo = loadmodel.texinfo + dfaces[i].texinfo;

		// keep a pointer to the original face info
		loadmodel.surfaces[i].face = &dfaces[i];
		loadmodel.surfaces[i].surfnum = i;
	}
}


void Mod_LoadMarksurfaces (void)
{
	int i;

	loadmodel.marksurfaces = MyMalloc (nummarksurfaces * sizeof (msurface_t *));

	for (i = 0; i < nummarksurfaces; i++)
	{
		loadmodel.marksurfaces[i] = loadmodel.surfaces + dmarksurfaces[i];
	}
}


void Mod_LoadLeafs (void)
{
	int i;

	loadmodel.leafs = MyMalloc (numleafs * sizeof (mleaf_t));

	for (i = 0; i < numleafs; i++)
	{
		loadmodel.leafs[i].firstmarksurface = loadmodel.marksurfaces + dleafs[i].firstmarksurface;
		loadmodel.leafs[i].nummarksurfaces = dleafs[i].nummarksurfaces;
		loadmodel.leafs[i].contents = dleafs[i].contents;
	}
}


void Mod_SetParent (mnode_t *node, mnode_t *parent)
{
	node->parent = parent;
	if (node->contents < 0)
		return;
	Mod_SetParent (node->children[0], node);
	Mod_SetParent (node->children[1], node);
}

void Mod_LoadNodes (void)
{
	int i;
	int j;
	int p;

	loadmodel.nodes = MyMalloc (numnodes * sizeof (mnode_t));

	for (i = 0; i < numnodes; i++)
	{
		loadmodel.nodes[i].plane = loadmodel.planes + dnodes[i].planenum;
		loadmodel.nodes[i].firstsurface = dnodes[i].firstface;
		loadmodel.nodes[i].numsurfaces = dnodes[i].numfaces;

		for (j = 0; j < 2; j++)
		{
			p = dnodes[i].children[j];

			if (p > 0)
				loadmodel.nodes[i].children[j] = loadmodel.nodes + p;
			else loadmodel.nodes[i].children[j] = (mnode_t *) (loadmodel.leafs + (-1 - p));
		}
	}

	Mod_SetParent (loadmodel.nodes, NULL);	// sets nodes and leafs
}


void Mod_LoadBSP (void)
{
	// we need these items in memory to be able to do stuff...
	Mod_LoadTextures ();
	Mod_LoadPlanes ();
	Mod_LoadTexinfo ();
	Mod_LoadFaces ();
	Mod_LoadMarksurfaces ();
	Mod_LoadLeafs ();
	Mod_LoadNodes ();
}


mleaf_t *Mod_PointInLeaf (vec3_t p)
{
	mnode_t		*node;
	float		d;
	mplane_t	*plane;

	node = loadmodel.nodes;

	while (1)
	{
		if (node->contents < 0)
			return (mleaf_t *)node;
		plane = node->plane;
		d = DotProduct (p,plane->normal) - plane->dist;
		if (d > 0)
			node = node->children[0];
		else
			node = node->children[1];
	}
	
	return NULL;	// never reached
}


void LightThread (qboolean test);

float PointDist (vec3_t p1, vec3_t p2);

void ProcessColour (void)
{
	int i;
	int j;
	int l;
	int x, y, z;
	msurface_t **mark;
	msurface_t *surf;
	mleaf_t *leaf;
	mnode_t *node;
	entity_t *ent;
	entity_t *jent;
	mleaf_t *jleaf;
	mnode_t *jnode;
	vec3_t originhack;
	int oldextrasamples;
	int numcolour = 0;

	// disable extra sampling on this run
	oldextrasamples = extrasamples;
	extrasamples = 1;

	// run lighting in test mode first
	LightThread (true);

	// restore extra sampling
	extrasamples = oldextrasamples;

	// load the bsp into memory in the same format as the game
	Mod_LoadBSP ();

	// fix up colours
	for (i = 0; i < num_entities; i++)
	{
		ent = &entities[i];

		// not a light
		if (!ent->islight) continue;

		// add in lighting for any relevant liquid surf
		if (!ent->precolour)
		{
			// check the view for this entity
			leaf = Mod_PointInLeaf (ent->origin);

			// slime can be fairly dull, so boost the colour a little.
			// these figures come from the quake palette, but with r and b halved
			if (leaf->contents == CONTENTS_SLIME)
			{
				ent->colour[0] += 54;
				ent->colour[1] += 107;
				ent->colour[2] += 8;
			}

			// add in liquids
			for (j = 0, mark = leaf->firstmarksurface; j < leaf->nummarksurfaces; j++, mark++)
			{
				surf = *mark;

				if (surf->texinfo->texture->liquid)
				{
					ent->colour[0] += surf->texinfo->texture->light[0];
					ent->colour[1] += surf->texinfo->texture->light[1];
					ent->colour[2] += surf->texinfo->texture->light[2];
				}
			}

			// add in the parent node to complete the picture
			node = leaf->parent;
			surf = loadmodel.surfaces + node->firstsurface;

			for (j = 0; j < node->numsurfaces; j++, surf++)
			{
				if (surf->texinfo->texture->liquid)
				{
					ent->colour[0] += surf->texinfo->texture->light[0];
					ent->colour[1] += surf->texinfo->texture->light[1];
					ent->colour[2] += surf->texinfo->texture->light[2];
				}
			}

			// now accumulate in any torches
			for (j = 0; j < num_entities; j++)
			{
				jent = &entities[j];

				if (jent->precolour)
				{
					for (x = -8; x <= 8; x += 8)
					{
						for (y = -8; y <= 8; y += 8)
						{
							for (z = -8; z <= 8; z += 8)
							{
								originhack[0] = jent->origin[0] + x;
								originhack[1] = jent->origin[0] + y;
								originhack[2] = jent->origin[0] + z;

								jleaf = Mod_PointInLeaf (originhack);

								if (jleaf->contents == CONTENTS_SOLID || jleaf->contents == CONTENTS_SKY) continue;

								jnode = jleaf->parent;

								if (jleaf == leaf || jnode == node)
								{
									// add in at half intensity
									ent->colour[0] += jent->colour[0] / 2;
									ent->colour[1] += jent->colour[1] / 2;
									ent->colour[2] += jent->colour[2] / 2;
								}
							}
						}
					}
				}
			}
		}

		if (ent->colour[0] == ent->colour[1] && ent->colour[1] == ent->colour[2])
		{
			// same colours - set to white light
			ent->colour[0] = 255;
			ent->colour[1] = 255;
			ent->colour[2] = 255;
		}
		else
		{
			// rescale to fix up
			int Total = (ent->colour[0] * 30 + ent->colour[1] * 59 + ent->colour[2] * 11) / 100;
			float Factor;

			// no need to rescale
			if (Total == 255) continue;

			// rescale factor
			Factor = 255.0f / (float) Total;

			// rescale
			ent->colour[0] = (int) ((float) ent->colour[0] * Factor);
			ent->colour[1] = (int) ((float) ent->colour[1] * Factor);
			ent->colour[2] = (int) ((float) ent->colour[2] * Factor);

			numcolour++;
		}
	}

	printf ("Coloured %i Lights\n\n", numcolour);
}

