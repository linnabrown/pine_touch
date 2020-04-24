# pine_touch

定时touch pine
```
gcc -Wall deamon.c -o deamon

./deamon
```



revise this line into your own onyen
```
system("find /pine/scr/<first_character>/<second_character>/<onyen_id>/ -exec touch {} \\;");
```
