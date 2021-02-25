#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <err.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <sysexits.h>
#include <sys/sysmacros.h>

#define MAXDIRNAME 256

char *rwxmode(mode_t, char *str);
char *FormattedDate(time_t, char *str);

int main(int argc, char *argv[])
{
    char user[32];        //  Name of file's owner
    char group[32];       //  Name of file's group owner
    struct passwd *uinfo; //  Temporary passwd structure
    struct group *ginfo;  //  Temporary group structure

    char atime[32]; //  Formatted access time
    char mtime[32]; //  Formatted modification time
    char ctime[32]; //  Formatted file status time

    char rwx[16]; // mode permission
    char dirname[MAXDIRNAME] = ".";
    struct stat info;
    struct dirent *entry;

    // collect the directory name, with "." as default
    if (argc >= 2)
    {
        strncpy(dirname, argv[1], MAXDIRNAME);
    }

    // check that the name really is a directory
    if (stat(dirname, &info) < 0)
    {
        err(EX_OSERR, "%s", dirname);
    }

    if (!S_ISDIR(info.st_mode))
    { // test for a directory
        errno = ENOTDIR;
        err(EX_DATAERR, "%s", dirname);
    }
    DIR *df; // open the directory to start reading the file

    //Set df to be a pointer to the directory stream and assert for no errors
    if ((df = opendir(".")) == NULL)
    {
        perror("Cannot open .\n End of program");
        exit(1);
    }

    chdir(dirname); //Change directory
    int count =1;
    //While there are still objects in directory
    while ((entry = readdir(df)) != NULL)
    {
        //Ignore '.' files
        
        if (entry->d_name[0] == '.')
        {
            continue;
        }
        //Get the stats for the object and store in info struct
        if (lstat(entry->d_name, &info) < 0)
        {
            err(EX_OSERR, "%s", dirname);
        }

        // Use the uid to get the owner's name
        if ((uinfo = getpwuid(info.st_uid)) == NULL)
            sprintf(user, "%d", info.st_uid);
        else
            strcpy(user, uinfo->pw_name);

        // Use the gid to get the group owner's name
        if ((ginfo = getgrgid(info.st_gid)) == NULL)
            sprintf(group, "%d", info.st_gid);
        else
            strcpy(group, ginfo->gr_name);

        //permission string r, w, x
        rwxmode(info.st_mode, rwx);

        // Format the last access time according to ls -l
        FormattedDate(info.st_atime, atime);

        // Format the last modification time time according to ls -l
        FormattedDate(info.st_mtime, mtime);

        // Format the last file status change time time according to ls -l
        FormattedDate(info.st_ctime, ctime);
        //print ls -l
        // if the file is a character special file or block special file
        if (S_ISCHR(info.st_mode) || S_ISBLK(info.st_mode))
        {
            printf("---------------------FILE NO.%d-------------------\n",count);
            printf("file permission =%9s\nlink=%ld\nusername=%8s\ngroupName=%8s\ni-node=%2ld\
            \nmajor=%3d,minor=%3d\nacess time=%s\nmodify time=%s\nchange time=%s\nfileName=%2s\n",
                   rwx,                 //file permission
                   info.st_nlink,       //link
                   user,                //username
                   group,               //group name
                   info.st_ino,         //number of i-node
                   major(info.st_rdev), //major
                   minor(info.st_rdev), //minor
                   atime,       //last access time
                   mtime,       //last modification time
                   ctime,       //last file status change time
                   entry->d_name);      //type of file
        }
        else
        {
            printf("---------------------FILE NO.%d-------------------\n",count);

            printf("file permission=%9s\nlink=%ld\nusername=%8s\ngroup name=%8s\
             \nfile size = %5lld\ni-node=%2ld\nacess time=%s\nmodify time=%s\nchange time=%s\
             \nfile name=%2s",
                   rwx,                     //file permission
                   info.st_nlink,           //link
                   user,                    //username
                   group,                   //group name
                   (long long)info.st_size, //size of file
                   info.st_ino,             //number of i-node
                   atime,                   //last access time
                   mtime,                   //last modification time
                   ctime,                   //last file status change time
                   entry->d_name);       //type of file
            printf("\nDevice no. major =%d minor = %d\n",major(info.st_dev),minor(info.st_dev));
                   
        }
        count ++;
    }
    closedir(df); //close directory
    return 0;
}

//file permission mode
char *rwxmode(mode_t mode, char *str)
{

    //array of bit rwx_arr for rwx string
    int rwx_arr[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};

    switch (mode & S_IFMT)
    { // type of file
    case (S_IFDIR):
        str[0] = 'd';
        break; // test for a directory
    case (S_IFLNK):
        str[0] = 'l';
        break; // test for a symbolic link
    case (S_IFREG):
        str[0] = '-';
        break; // test for a regular file
    default:
        str[0] = '?';
        break;
    }

    for (int i = 1; i <= 9; i++)
    {

        //to store respective r, w, or x
        if (mode & rwx_arr[i - 1])
        {
            if (i == 1 || i == 4 || i == 7)
            {
                str[i] = 'r';
            }
            if (i == 2 || i == 5 || i == 8)
            {
                str[i] = 'w';
            }
            if (i == 3 || i == 6 || i == 9)
            {
                str[i] = 'x';
            }
        }
        else
        {
            str[i] = '-';
        }
    }

    return str;
}

char *FormattedDate(time_t time, char *str) {
strftime(str,32, "%b %d %H:%M" , localtime(&time)); 
return str;
}
