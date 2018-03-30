#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

using namespace std;
long int razmer, kol, kol1;

void dfs(){
DIR* dp = opendir(".");
	struct dirent *res;

	while ((res = readdir(dp)) != NULL) {

        if (strcmp(res->d_name,".")==0 || strcmp(res->d_name,"..")==0)
            continue;
        struct stat info;
        stat(res->d_name, &info);

    	if (S_ISDIR(info.st_mode)){
            cout << " DIR" <<  "\n";
            kol1++;
            chdir(res->d_name);
            dfs();
            chdir("..");
            }
    	else{
            razmer+= info.st_size;
            kol++;
    	}
        cout << info.st_size<< " " << res->d_name << "\n";
	}

    closedir(dp);
    }


int main()
{
	dfs();
    cout << "file = " << kol << ", dir = " << kol1 << ", bytes = " << razmer << "\n";
    return 0;
}

