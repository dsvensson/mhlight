Not a general purpose lighting utility; this is the latest version of MHColour.  I'd originally updated it back in 2007, but never got round to releasing it then.  A few final bits of work and here it is.

Use it to generate a LIT file for (almost) any BSP; information from fullbright colours in the textures and from lava and slime textures is used to create colour values for nearby lights.  Certain special lights (torches, etc) are also coloured.

Bugs?  Limitations?  I'm sure it has plenty... here's what I know of for sure:

* It seems to become unhappy with Hipnotic rotating brushes - not sure why and can't really be bothered to find out right now.  It won't crash, but it won't light the brush either.

* It's based on the original ID Light utility, so all limitations and bugs that apply to that also apply to this.  It'll probably choke on really large BSPs. One exception - I added "-extra4" as an option.

* As well as generating a LIT file it will also relight the BSP.  LIT files created by this probably won't be redistributable.  The reason for this is that I tried it the other way and it didn't work; packing the LIT data into the same face offsets used by the original produced weird results on some brushes.  It only takes about half an hour to relight all of ID1 with -extra4 on a modern PC anyway, so it doesn't matter too much.


If anybody does anything cool with this I'd love to know; you can normally find me hanging around on Inside3D.
