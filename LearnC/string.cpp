   /* strcmp.c */

   #include <stdio.h>
   #include <string.h>

   #define ANSWER "blue"

   int main()
   {
     char s[100];
     puts( "What is the secret color?" );
     gets( s );
     
     while ( strncmp( s, ANSWER, 4) )
     {
         puts( "Wrong, try again." );
         gets( s );
     }
     
     puts( "Right!" );
   }
   
  /* strchr.c */

   #include <stdio.h>

   #include <string.h>

   int main()
   {
     char *t = "MEAS:VOLT:DC?";
     char *p;
     p = t;
     puts( p );
     while(( p = strchr( p, ':' )) != NULL )
     {
       puts( ++p );
     }
   }