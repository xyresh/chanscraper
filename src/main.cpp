#include<stdio.h>
#include<vector>
#include<string>
#include<stdlib.h>

void stdDownload(std::string URL);

void argError(int argc,char *argv[]);

void cDirDownload(std::string URL,std::string cDir);

void cleanDownloads(std::string Dir);

int main(int argc, char* argv[])
{
  argError(argc,argv);
  if(argc==3)
  {
    cDirDownload(argv[1],argv[2]);
    cleanDownloads(argv[2]);
  }
  else
  {
    stdDownload(argv[1]);
    cleanDownloads("$HOME/chanscrapes");
  }
  
  printf("\nThank you for using Chanscraper!!\n\n");
  return 0;
}


void stdDownload(std::string URL){
  std::string cmd = "wget -q -P $HOME/chanscrapes -nd -r -l 1 -H -D i.4cdn.org -A png,gif,jpg,jpeg,webm  ";
  cmd += URL;
  const char * command = cmd.c_str();
  printf("\nDownloading Files ...\n\n");
  system(command);
  printf("Files save in <your home folder>/chanscrapes");
}


void cDirDownload(std::string URL,std::string cDir)
{
  std::string cmd = "wget -q -P ";
  cmd += cDir+" -nd -r -l 1 -H -D i.4cdn.org -A png,gif,jpg,jpeg,webm  "+URL;
  const char * command = cmd.c_str();
  const char * dir = cDir.c_str();
  printf("Downloading Files ...");
  system(command);
  printf("Files saved at %s",dir);
}

void cleanDownloads(std::string Dir)
{
  std::string cmd = "rm -rf "+Dir+"/*s.*";
  const char * ccmd= cmd.c_str();
  system(ccmd);
}


void argError(int argc,char *argv[])
{

  if(argc == 1)
  {
     printf("invalid Arguments!\nUsage: chanscrapes <Thread URL> <directory of choice>");
     std::exit(69);
  }
  if(argv[2] == "$HOME")
  {
    printf("\nDue to system Nuke probability aborting\n");
    std::exit(420);
  }
}
