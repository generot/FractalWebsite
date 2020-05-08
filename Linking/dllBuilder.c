#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 40

char *entryPoint[] = {
    "#include <windows.h>\n",
    "\n",
    "BOOL WINAPI DllMain(HINSTANCE hI, DWORD reason, LPVOID lpReserved){\n",
    "\tif(reason == DLL_PROCESS_ATTACH){\n",
    "\t\t//Do something\n",
    "\t}\n",
    "\treturn TRUE;\n",
    "}\n"
};

int main(int argc, char**argv){
    char *command = "gcc -shared -o dynLib.dll ", *buffer = malloc(MAX_BUFF*sizeof(char)), *addInp = "create";

    if(argc != 2){
        printf("Usage: dbl <src_file>/create");
        exit(EXIT_FAILURE);
    }

    if(strncmp(argv[1], addInp, strlen(addInp)+1) == 0){
        FILE *stream = fopen("srcfile.c", "w");
        for(int i = 0; i < sizeof(entryPoint)/sizeof(char*); i++){
            fprintf(stream, "%s", entryPoint[i]);
        }
        fclose(stream);
        return EXIT_SUCCESS;
    }

    strncpy(buffer, command, strlen(command)+1);
    strncat(buffer, argv[1], strlen(argv[1])+1);
    buffer[MAX_BUFF-1] = '\0';

    system(buffer);

    free(buffer);
    return EXIT_SUCCESS;
}