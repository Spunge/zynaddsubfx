/*
  ZynAddSubFX - a software synthesizer
 
  PresetsStore.C - Presets and Clipboard store
  Copyright (C) 2002-2004 Nasca Octavian Paul
  Author: Nasca Octavian Paul

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#include "../Misc/XMLwrapper.h"
#define MAX_PRESETTYPE_SIZE 30
#define MAX_PRESETS 1000

class PresetsStore{
    public:
	PresetsStore();
	~PresetsStore();
	void copyclipboard(XMLwrapper *xml,char *type);
	bool pasteclipboard(XMLwrapper *xml);
	bool checkclipboardtype(char *type);
	
	struct presetstruct{
	    char *file;
	    char *name;
	};
	presetstruct presets[MAX_PRESETS];
	
    private:
	struct {
	    char *data;
	    char type[MAX_PRESETTYPE_SIZE];
	} clipboard;
	
	void clearpresets();
	void rescanforpresets(char *type);
	
};

extern PresetsStore presetsstore;
