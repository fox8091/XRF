#include "XBFS.h"
#include "XRF.h"

namespace XBFS
{
	HANDLE hFlash;
	DWORD XBFS_BUFFER_LEN = 1048576;

	bool XBFS::Open(LPCSTR lpszFile, bool bRawDump)
	{
		char path[10000];
		if (bRawDump)
			strcat_s(path, PIPE_NAME_XVUC_FLASH);
		else
			strcat_s(path, PIPE_NAME_XVUC_FLASHFS);

		strcat_s(path, lpszFile);

		hFlash = CreateFileA(path, GENERIC_READ,
			FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

		if (!hFlash) {
			printf("[XBFS] Unable to open flash!\n");
			return false;
		}

		return true;
	}

	bool XBFS::Read(LPCSTR lpszFileName, LPCSTR lpszDestination, bool bRawDump)
	{
		DWORD dwNumRead = 0;
		FILE* f = NULL;

		if (!Open(lpszFileName, bRawDump)) {
			return false;
		}

		char* buffer = (char*)VirtualAlloc(0, XBFS_BUFFER_LEN, MEM_COMMIT, PAGE_READWRITE);
		if (!buffer) {
			printf("[XBFS] Failed to allocate memory: 0x%08\r\n", GetLastError());
			return false;
		}

		printf("[XBFS] Attempting to read %s from flash...\n", lpszFileName);
		for (;;) {
			if (!ReadFile(hFlash, buffer, XBFS_BUFFER_LEN, &dwNumRead, 0)) {
				printf("[XBFS] Unable to read from flash! Error: %ld\n", GetLastError());
				return false;
			}
			if (!dwNumRead)
				break;
			if (!f)
				f = fopen(lpszDestination, "wb");
			fwrite(buffer, dwNumRead, 1, f);
			printf(".");
		}

		printf("\n\n");

		CloseHandle(hFlash);

		if (!f) {
			printf("[XBFS] File does not exist!\n");
			return false;
		}

		printf("[XBFS] Copied %i bytes from %s successfully!\n", ftell(f), lpszFileName);

		fclose(f);

		return true;
	}
}