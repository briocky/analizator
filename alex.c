#include "alex.h"

#include <ctype.h>/* tutaj chyba nie ma isKeyword*/
/*bede korzystal zatem z keyword.h*/
#include "keyword.h"

static int ln = 0;
static char ident[256];
static FILE *ci = NULL;
static int c;
static int n_lex_return = 0;/* zwrot z funckji nextLexem*/
                        /* 1 - wszedl do if'a ktory pobiera o jeden znak za duzo*/
                        /* 0 - wszedl do innego miejsca*/

void alex_init4file(FILE *in)
{
  ln = 1;
  ci = in;
}

lexem_t alex_nextLexem(void)
{
  if(n_lex_return==1){
    ungetc(c, ci);/*trzeba bylo to tak rozwiazac, bo takto gdy funkcja wchodzila do "else if (isalpha(c)) to czytala zawsze o jeden znak wiecej i powodowalo to blad"*/
    n_lex_return = 0;
  }
  while ((c=fgetc(ci))!=EOF)
  {
    if (isspace(c)){
      if(c=='\n')
        ln++;
      continue;
    }
    //tutaj coś odkomentowałem
    /*else if (c == '\n')
      ln++;*/
    else if (c == '('){
      n_lex_return=0;
      return OPEPAR;
    }
    else if (c == ')'){
      n_lex_return=0;
      return CLOPAR;
    }
    else if (c == '{'){
      n_lex_return=0;
      return OPEBRA;
    }
    else if (c == '}'){
      n_lex_return=0;
      return CLOBRA;
    }
    else if (isalpha(c))
    {
      int i = 1;
      ident[0] = c;
      while (isalnum(c = fgetc(ci)))
        ident[i++] = c;
      ident[i] = '\0';
      n_lex_return=1;
      return isKeyword(ident) ? OTHER : IDENT;
    }
    else if (c == '"')
    {
      /* Uwaga: tu trzeba jeszcze poprawic obsluge nowej linii w trakcie napisu
        i \\ w napisie 
      */
      int cp = c;
      while ((c = fgetc(ci)) != EOF && c != '"' && cp == '\\')
      {
        cp = c;
      }
      return c == EOF ? EOFILE : OTHER;
    }
    else if (c == '/')
    {
      /* moze byc komentarz */
    }
    else if (isdigit(c) || c == '.')
    {
      /* liczba */
    }
    else
    {
      return OTHER;
    }
  }
  return EOFILE;
}

char *alex_ident(void)
{
  return ident;
}

int alex_getLN()
{
  return ln;
}
