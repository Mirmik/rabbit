#!/usr/bin/env python3

import sys
import licant
from licant.cxx_modules import application
from licant.modules import submodule, module
from licant.libs import include

licant.execute("../rabbit.g.py")

application("runtests",
	sources = [
		"main.cpp",
		"intersect.cpp",	
		"htrans3.cpp",		
		"nearest.cpp"		
	],

	cxx_flags = "-g",
	cc_flags = "-g",

	include_paths = ["."],
	mdepends = [ "rabbit" ],

	libs=["nos", "igris"]
)

licant.ex("runtests")