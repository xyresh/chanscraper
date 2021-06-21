/*
 *  File: main.cpp
 *
 *  Author: mrayo
 *
 *  cpplang
 *
 *  written under GPL V3.0
 *
 */
#include<stdio.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<string.h>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>


struct passwd *pw = getpwuid(getuid());

const char *homedir = pw->pw_dir;


//function decs
void stdDownload(std::string URL);
//kinda autistic this one
void argError(int argc,char *argv[]);

void cDirDownload(std::string URL,std::string cDir);

void cleanDownloads(std::string Dir);
//main lel


int main(int argc, char* argv[])
{

  argError(argc,argv);
  if(argc==3 && strcmp(homedir,argv[2])!=0) //custom path declared
  {
    cDirDownload(argv[1],argv[2]);
    cleanDownloads(argv[2]);
  }
  else //default save directory
  {
    stdDownload(argv[1]);
    cleanDownloads("$HOME/chanscrapes");
  }
  //thank you message, may add an ascii art to make it look good 
  printf("\nThank you for using Chanscraper!!\n\n");
  return 0;
}

//download to default directory
void stdDownload(std::string URL){
  std::string cmd = "wget -q -P $HOME/chanscrapes -nd -r -l 1 -H -D i.4cdn.org -A png,gif,jpg,jpeg,webm  ";
  cmd += URL;
  const char * command = cmd.c_str();
  printf("\nDownloading Files ...\n\n");
  system(command);
  printf("\nFiles saved in <your home folder>/chanscrapes\n");
}

//download to custom directory
void cDirDownload(std::string URL,std::string cDir)
{
  std::string cmd = "wget -q -P ";
  cmd += cDir+" -nd -r -l 1 -H -D i.4cdn.org -A png,gif,jpg,jpeg,webm  "+URL;
  const char * command = cmd.c_str();
  const char * dir = cDir.c_str();
  printf("\nDownloading Files ...\n\n");
  system(command);//this is quite autistic i know lel
  printf("\nFiles saved at %s\n",dir);
}
//delete low res pictures
//meaning that if the filename contains 's' before the extension it will be nuked
//thus this part is really sketchy
void cleanDownloads(std::string Dir)
{
  std::string cmd = "rm -rf "+Dir+"/*s.*";
  const char * ccmd= cmd.c_str();
  system(ccmd);
}
//probably need to look into a safer way to go about with this

void argError(int argc,char *argv[])
{

  if(argc == 1)
  {
     //invalid argument error message
     printf("invalid Arguments!\nUsage: chanscrapes <Thread URL> <directory of choice>\n");
     std::exit(69);
     //error code is 69 lol
  }
}
