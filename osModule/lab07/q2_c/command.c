// file:		command.c for Week 8
// purpose;		to separate a list of tokens into a sequence of commands.
// assumptions:		any two successive commands in the list of tokens are separated 
//			by one of the following command separators:
//				"|"  - pipe to the next command
//				"&"  - shell does not wait for the proceeding command to terminate
//				";"  - shell waits for the proceeding command to terminate
// author:		HX
// date:		2006.09.21
// note:		not tested therefore it may contain errors

#include <string.h>
#include "command.h"

// return 1 if the token is a command separator
// return 0 otherwise
//
int separator(char *token)
{
    int i=0;
    char *commandSeparators[] = {pipeSep, conSep, seqSep, NULL};

    while (commandSeparators[i] != NULL) {
        if (strcmp(commandSeparators[i], token) == 0) {
            return 1; 
        } 
        ++i;
    }
    
    return 0;
}

// fill one command structure with the details
//
void fillCommandStructure(Command *cp, int first, int last, char *sep)
{
     cp->first = first; 
     cp->last = last - 1;
     cp->sep = sep; 
}

int separateCommands(char *token[], Command command[])
{
     int i;
     int nTokens;

     // find out the number of tokens
     i = 0;
     while (token[i] != NULL) ++i; 
     nTokens = i;

     // if empty command line
     if (nTokens == 0) 
          return 0;

     // check the first token
     if (separator(token[0]))
          return -3;

     // check last token, add ";" if necessary 
     if (!separator(token[nTokens-1])) {
          token[nTokens] = seqSep;
          ++nTokens;
     }
          
     int first=0;   // points to the first tokens of a command
     int last;      // points to the last  tokens of a command
     char *sep;     // command separator at the end of a command
     int c = 0;         // command index
     for (i=0; i<nTokens; ++i) {
         last = i;
         if (separator(token[i])) {
             sep = token[i];
             if (first==last)  // two consecutive separators
                 return -2;
             fillCommandStructure(&(command[c]), first, last, sep);
             ++c;
             first = i+1; 
         }
     }

     // check the last token of the last command  
     if (strcmp(token[last], pipeSep) == 0) { // last token is pipe separator
          return -4; 
     } 

     // calculate the number of commands
     int nCommands = c;
 
     return nCommands; 
}
