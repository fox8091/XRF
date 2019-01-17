#pragma once

#include "Prerequisites.h"

static const char* XBFS_ENTRIES[] = {
	"1smcbl_a.bin",	// 0
	"header.bin",	// 1
	"devkit.ini",	// 2
	"mtedata.cfg",	// 3
	"certkeys.bin", // 4
	"smcerr.log",	// 5
	"system.xvd",	// 6
	"$sospf.xvd",	// 7
	"download.xvd", // 8
	"smc_s.cfg",	// 9
	"sp_s.cfg",		// 10
	"os_s.cfg",		// 11
	"smc_d.cfg",	// 12
	"sp_d.cfg",		// 13
	"os_d.cfg",		// 14
	"smcfw.bin",	// 15
	"boot.bin",		// 16
	"host.xvd",		// 17
	"settings.xvd", // 18
	"1smcbl_b.bin", // 19
	"bootanim.dat", // 20
	"obsolete.001", // 2
	"update.cfg",	// 22
	"obsolete.002",	// 23
	"hwinit.cfg",	// 24
	"qaslt.xvd",	// 25
	"sp_s.bak",		// 26
	"update2.cfg",	// 27
	"obsolete.003",	// 28
	"dump.lng",		// 29
	"os_d_dev.cfg", // 30
	"os_glob.cfg",	// 31
	"sp_s.alt",		// 32
	"sysauxf.xvd",	// 33
};

namespace XBFS
{
	bool Open(LPCSTR lpszFile, bool bRawDump);
	bool Read(LPCSTR lpszFileName, LPCSTR lpszDestination, bool bRawDump);
}
