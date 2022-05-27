#include <windows.h>
#include <stdio.h>
//Create key in registry
BOOL CreateRegistryKey(HKEY hKeyParent,LPCSTR subkey)
{
    DWORD dwDisposition; 
    HKEY  hKey;
    DWORD Ret;
    Ret =
        RegCreateKeyEx(
            hKeyParent,
            subkey,
            0,
            NULL,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            NULL,
            &hKey,
            &dwDisposition);
    if (Ret != ERROR_SUCCESS)
    {
        printf("Error opening or creating key.\n");
        return FALSE;
    }
    RegCloseKey(hKey);
    return TRUE;
}

BOOL writeStringInRegistry(HKEY hKeyParent, LPCSTR subkey, LPCSTR valueName, LPCSTR strData)
{
    DWORD Ret;
    HKEY hKey;
    //Check if the registry exists
    Ret = RegOpenKeyEx(
              hKeyParent,
              subkey,
              0,
              KEY_WRITE,
              &hKey
          );
    if (Ret == ERROR_SUCCESS)
    {
        if (ERROR_SUCCESS !=
                RegSetValueEx(
                    hKey,
                    valueName,
                    0,
                    REG_SZ,
                    (LPBYTE)(strData),
                    ((((DWORD)lstrlen(strData) + 1)) * 2)))
        {
            RegCloseKey(hKey);
            return FALSE;
        }
        RegCloseKey(hKey);
        return TRUE;
    }
    return FALSE;
}

int main(int argc, char *argv[])
{
    BOOL status;
    status = CreateRegistryKey(HKEY_CURRENT_USER, "onePiece"); //create key
    if (status != TRUE)
        return FALSE;
    
    status = writeStringInRegistry(HKEY_CURRENT_USER, "onePiece", "Luffy", "Gum-Gum Bazoooookaa"); //write string
    if (status != TRUE)
        return FALSE;
    
    return 0;
}
