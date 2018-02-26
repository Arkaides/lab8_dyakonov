#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


using namespace std;

int dcheck(char *dname)
{
    struct stat rs;
    struct dirent *res;
    DIR *dp;

    char *cur_ent = malloc(sizeof(char));
    int count = 0;

    if ((dp = opendir(dname)) != NULL)
    {
        while((res = readdir(dp)) != NULL)
        {
           if(!strcmp(res->d_name, ".") || !strcmp(res->d_name, ".."))
                continue;
            strcpy(cur_ent, dname);
            strcat(cur_ent,"/");
           strcat(cur_ent, res->d_name);
           stat(cur_ent, &rs);
           if(!((rs.st_mode & S_IFMT) == S_IFDIR))
            {
             count+= rs.st_size;
            }
        }
       closedir(dp);
    }
    return count;
}

int main(void)
{
    int a=0;
    DIR* dp=opendir(".");
    struct dirent *res;
    struct stat rs;
    while ((res=readdir(dp))!=NULL){
        if(!strcmp(res->d_name,".")|| !strcmp(res->d_name,".."))
            continue;
        stat(res->d_name, &rs);
        if((rs.st_mode&S_IFMT)==S_IFDIR)
        {
            count+=dcheck(res->d_name);
        }
        if(!((rs.st_mode&S_IFMT)==S_IFDIR))
        {
            count+=rs.st_size;
        }
        }
        }


    closedir(dp);
    cout << count << "\n";
    return 0;
}
